#include <vtkSmartPointer.h>
#include <vtkBMPReader.h>
#include <vtkBMPWriter.h>
#include <vtkImageAppendComponents.h>

int main (int argc, char *argv[])
{
  if(argc != 5)
    {
    std::cout << "Required arguments: r.bmp g.bmp b.bmp output.bmp" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string rFilename = argv[1];
  vtkstd::string gFilename = argv[2];
  vtkstd::string bFilename = argv[3];
  vtkstd::string outputFilename = argv[4];
  
  vtkSmartPointer<vtkBMPReader> rReader = 
      vtkSmartPointer<vtkBMPReader>::New();
  rReader->SetFileName(rFilename.c_str());
  rReader->Update();
  
  vtkSmartPointer<vtkBMPReader> gReader = 
      vtkSmartPointer<vtkBMPReader>::New();
  gReader->SetFileName(gFilename.c_str());
  gReader->Update();
  
  vtkSmartPointer<vtkBMPReader> bReader = 
      vtkSmartPointer<vtkBMPReader>::New();
  bReader->SetFileName(bFilename.c_str());
  bReader->Update();

  vtkSmartPointer<vtkImageAppendComponents> append = 
    vtkSmartPointer<vtkImageAppendComponents>::New();
  //append->AddInputConnection(0, rReader->GetOutputPort());
  append->SetInputConnection(0, rReader->GetOutputPort());
  append->AddInputConnection(0, gReader->GetOutputPort());
  append->AddInputConnection(0, bReader->GetOutputPort());
  append->Update();
  
  vtkSmartPointer<vtkBMPWriter> writer = 
      vtkSmartPointer<vtkBMPWriter>::New();
  writer->SetFileName(outputFilename.c_str());
  writer->SetInputConnection(append->GetOutputPort());
  writer->Update();
  
  return EXIT_SUCCESS;
}
