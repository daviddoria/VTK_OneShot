#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPointData.h>
#include <vtkFloatArray.h>

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.vtp ArrayName" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string filename = argv[1];
  vtkstd::string arrayName = argv[2];
  
  vtkSmartPointer<vtkXMLPolyDataReader> reader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(filename.c_str());
  reader->Update();
  
  vtkFloatArray* array = vtkFloatArray::SafeDownCast(reader->GetOutput()->GetPointData()->GetArray(arrayName.c_str()));
  
  for(vtkIdType i = 0; i < 5; i++)
    {
    float value = array->GetValue(i);
    std::cout << value << std::endl;
    }
  
  return EXIT_SUCCESS;
}
