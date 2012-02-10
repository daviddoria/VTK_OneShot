#include <vtkTree.h>
#include <vtkSmartPointer.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkMutableDirectedGraph.h>
#include <vtkGraphToPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkGraphWriter.h>

#include <vtkNearestNeighborGraphFilter.h>

#include <sstream>
#include <string>

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cerr << "Required arguments: InputFile.vtp OutputFile.graph" << std::endl;
    return EXIT_FAILURE;
    }

  // Create a data set
  vtkSmartPointer<vtkXMLPolyDataReader> reader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(argv[1]);
  reader->Update();

  // Compute the EMST
  vtkSmartPointer<vtkNearestNeighborGraphFilter> nnFilter =
    vtkSmartPointer<vtkNearestNeighborGraphFilter>::New();
  nnFilter->SetInputConnection(reader->GetOutputPort());
  nnFilter->Update();

  vtkSmartPointer<vtkGraphWriter> graphWriter =
    vtkSmartPointer<vtkGraphWriter>::New();
  graphWriter->SetInputConnection(nnFilter->GetOutputPort());
  graphWriter->SetFileName(argv[2]);
  graphWriter->Update();

  vtkSmartPointer<vtkGraphToPolyData> graphToPolyData =
    vtkSmartPointer<vtkGraphToPolyData>::New();
  graphToPolyData->SetInputConnection(eMSTFilter->GetOutputPort());
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