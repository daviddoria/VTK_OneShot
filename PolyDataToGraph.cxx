#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkGraphWriter.h>
#include <vtkPolyDataToGraph.h>
#include <vtkGraphToPolyData.h>
#include <vtkXMLPolyDataWriter.h>

int main (int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.vtp OutputFile.graph" << std::endl;
    return EXIT_FAILURE;
    }


  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];

  vtkSmartPointer<vtkXMLPolyDataReader> reader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();

  std::cout << "input has " << reader->GetOutput()->GetNumberOfPoints() << " points." << std::endl;
  std::cout << "input has " << reader->GetOutput()->GetNumberOfCells() << " cells." << std::endl;

  vtkSmartPointer<vtkPolyDataToGraph> filter =
    vtkSmartPointer<vtkPolyDataToGraph>::New();
  filter->SetInputConnection(reader->GetOutputPort());
  filter->Update();

  std::cout << "output has " << filter->GetOutput()->GetNumberOfVertices() << " vertices." << std::endl;
  std::cout << "output has " << filter->GetOutput()->GetNumberOfEdges() << " edges." << std::endl;

  // Write the result to a file
  vtkSmartPointer<vtkGraphWriter> writer =
    vtkSmartPointer<vtkGraphWriter>::New();
  writer->SetInputConnection(filter->GetOutputPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();

  vtkSmartPointer<vtkGraphToPolyData> graphToPolyData =
    vtkSmartPointer<vtkGraphToPolyData>::New();
  graphToPolyData->SetInputConnection(filter->GetOutputPort());
  graphToPolyData->Update();

  vtkSmartPointer<vtkXMLPolyDataWriter> checkWriter =
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  checkWriter->SetInputConnection(graphToPolyData->GetOutputPort());
  checkWriter->SetFileName("check.vtp");
  checkWriter->Write();

  return EXIT_SUCCESS;
}
