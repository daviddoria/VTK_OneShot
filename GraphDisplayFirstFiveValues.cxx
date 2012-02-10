#include <vtkSmartPointer.h>
#include <vtkGraph.h>
#include <vtkGraphReader.h>
#include <vtkFloatArray.h>
#include <vtkDataSetAttributes.h>

int main(int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.vtp ArrayName" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string filename = argv[1];
  vtkstd::string arrayName = argv[2];
  
  vtkSmartPointer<vtkGraphReader> reader =
    vtkSmartPointer<vtkGraphReader>::New();
  reader->SetFileName(filename.c_str());
  reader->Update();
  
  vtkFloatArray* array = vtkFloatArray::SafeDownCast(reader->GetOutput()->GetVertexData()->GetArray(arrayName.c_str()));
  
  for(vtkIdType i = 0; i < 5; i++)
    {
    float value = array->GetValue(i);
    std::cout << value << std::endl;
    }
  
  return EXIT_SUCCESS;
}
