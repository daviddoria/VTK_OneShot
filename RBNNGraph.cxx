#include <vtkTree.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkMutableDirectedGraph.h>
#include <vtkGraphToPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkGraphWriter.h>

#include <vtkRBNNGraphFilter.h>

#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
  if(argc != 4)
    {
    std::cerr << "Required arguments: InputFile.vtp OutputFile.graph radius" << std::endl;
    return EXIT_FAILURE;
    }

  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
  
  std::stringstream ssRadius;
  ssRadius << argv[3];
  double radius;
  ssRadius >> radius;
  
  // Create a data set
  vtkSmartPointer<vtkXMLPolyDataReader> reader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();

  // Compute the EMST
  vtkSmartPointer<vtkRBNNGraphFilter> rbnnFilter =
    vtkSmartPointer<vtkRBNNGraphFilter>::New();
  rbnnFilter->SetRadius(radius);
  rbnnFilter->SetInputConnection(reader->GetOutputPort());
  rbnnFilter->Update();

  vtkSmartPointer<vtkGraphWriter> graphWriter =
    vtkSmartPointer<vtkGraphWriter>::New();
  graphWriter->SetInputConnection(rbnnFilter->GetOutputPort());
  graphWriter->SetFileName(outputFilename.c_str());
  graphWriter->Update();

  // Convert back to a vtkPolyData and write a vtp file to verify the graph was created correctly (since Paraview can't read .graph files (yet!))
  vtkSmartPointer<vtkGraphToPolyData> graphToPolyData =
    vtkSmartPointer<vtkGraphToPolyData>::New();
  graphToPolyData->SetInputConnection(rbnnFilter->GetOutputPort());
  graphToPolyData->Update();

  vtkSmartPointer<vtkXMLPolyDataWriter> writer =
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  std::stringstream ss;
  ss << argv[2] << ".vtp";
  writer->SetFileName(ss.str().c_str());
  writer->SetInputConnection(graphToPolyData->GetOutputPort());
  writer->Write();

  return EXIT_SUCCESS;
}