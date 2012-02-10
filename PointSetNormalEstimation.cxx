#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkPointSetNormalEstimationFilter.h>
#include <vtkPointSetNormalEstimationFilter2.h>

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
  
  vtkSmartPointer<vtkPointSetNormalEstimationFilter> normalEstimation = 
    vtkSmartPointer<vtkPointSetNormalEstimationFilter>::New();
//  vtkSmartPointer<vtkPointSetNormalEstimationFilter2> normalEstimation = 
  //  vtkSmartPointer<vtkPointSetNormalEstimationFilter2>::New();
  normalEstimation->SetInputConnection(reader->GetOutputPort());
  normalEstimation->Update();
  
  //write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
      vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(normalEstimation->GetOutputPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
