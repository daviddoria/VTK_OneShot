#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPointSetNormalQuality.h>

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.vtp OutputFile.vtp" << std::endl;
    return EXIT_FAILURE;
    }
    
  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
  
  
  vtkSmartPointer<vtkXMLPolyDataReader> reader = 
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  vtkSmartPointer<vtkPointSetNormalQuality> normalQualityFilter = 
    vtkSmartPointer<vtkPointSetNormalQuality>::New();

  normalQualityFilter->SetInputConnection(reader->GetOutputPort());
  normalQualityFilter->Update();
  
  // Write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
      vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(normalQualityFilter->GetOutputPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
