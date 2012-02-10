#include <vtkPolyData.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkSimplePointsReader.h>
#include <vtkSmartPointer.h>
 
int main(int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required parameters: InputFilename OutputFilename" << std::endl;
    return EXIT_FAILURE;
    }
 
  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
 
  vtkSmartPointer<vtkSimplePointsReader> reader = 
    vtkSmartPointer<vtkSimplePointsReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
 
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetFileName(outputFilename.c_str());
  writer->SetInput(reader->GetOutput());
  writer->Write();
 
  return EXIT_SUCCESS;
}