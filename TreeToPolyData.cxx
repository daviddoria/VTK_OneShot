#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkTreeReader.h>
#include <vtkTree.h>
#include <vtkGraphToPolyData.h>

int main (int argc, char *argv[])
{
  if(argc != 3)
    {
    cout << "Required arguments: InputFile.tree OutputFile.vtp" << endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string inputFilename = argv[1];
  vtkstd::string outputFilename = argv[2];
  
  vtkSmartPointer<vtkTreeReader> reader = 
    vtkSmartPointer<vtkTreeReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  std::cout << "input has " << reader->GetOutput()->GetPoints()->GetNumberOfPoints() << " points." << std::endl;
  std::cout << "input has " << reader->GetOutput()->GetNumberOfVertices() << " vertices." << std::endl;
  std::cout << "input has " << reader->GetOutput()->GetNumberOfEdges() << " edges." << std::endl;
  
  vtkSmartPointer<vtkGraphToPolyData> filter = 
    vtkSmartPointer<vtkGraphToPolyData>::New();
  filter->SetInputConnection(reader->GetOutputPort());
  filter->Update();
  
  //write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(filter->GetOutputPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
