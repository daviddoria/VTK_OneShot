#include <vtkSmartPointer.h>
#include <vtkImageData.h>
#include <vtkJPEGWriter.h>
#include <vtkColor.h>
#include <vtkMath.h>

#include "vtkPTXReader.h"
#include "vtkPTXData.h"

int main(int argc, char *argv[])
{
   if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.ptx OutputFile.jpg" << std::endl;
    return EXIT_FAILURE;
    }
    
  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
  
  std::cout << "Reading " << inputFilename << " and writing " << outputFilename << std::endl;

  vtkSmartPointer<vtkPTXReader> reader =
    vtkSmartPointer<vtkPTXReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  vtkSmartPointer<vtkImageData> image = 
    vtkSmartPointer<vtkImageData>::New();
  vtkPTXData* data = reader->GetOutput();
  data->CreateImage(image);
   
  vtkSmartPointer<vtkJPEGWriter> writer = 
    vtkSmartPointer<vtkJPEGWriter>::New();
  writer->SetFileName(outputFilename.c_str());
  writer->SetInput(image);
  writer->Write();


  return EXIT_SUCCESS;
}
