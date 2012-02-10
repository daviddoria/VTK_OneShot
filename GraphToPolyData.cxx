#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkGraphReader.h>
#include <vtkGraphToPolyData.h>

int main (int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.graph OutputFile.vtp" << std::endl;
    return EXIT_FAILURE;
    }
    
  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
  
  vtkSmartPointer<vtkGraphReader> reader = 
    vtkSmartPointer<vtkGraphReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  vtkSmartPointer<vtkGraphToPolyData> filter = 
    vtkSmartPointer<vtkGraphToPolyData>::New();
  filter->SetInputConnection(reader->GetOutputPort());
  filter->Update();
  
  // Write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(filter->GetOutputPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
