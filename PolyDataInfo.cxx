#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPointData.h>
#include <vtkCellData.h>

int main (int argc, char *argv[])
{
  if(argc != 2)
    {
    std::cout << "Required arguments: InputFile.vtp" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string inputFilename = argv[1];
  
  vtkSmartPointer<vtkXMLPolyDataReader> reader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  std::cout << "input has " << reader->GetOutput()->GetNumberOfPoints() << " points." << std::endl;
  std::cout << "input has " << reader->GetOutput()->GetNumberOfCells() << " cells." << std::endl;


  // Get the point data arrays
  std::cout << std::endl << "Point Data Arrays: " << std::endl;
  {
  vtkIdType numArrays = reader->GetOutput()->GetPointData()->GetNumberOfArrays();

  for(vtkIdType i = 0; i < numArrays; i++)
    {
    std::cout << reader->GetOutput()->GetPointData()->GetArrayName(i) << std::endl;;
    }
  }

  // Get the cell data arrays
  std::cout << std::endl << "Cell Data Arrays: " << std::endl;
  {
  vtkIdType numArrays = reader->GetOutput()->GetCellData()->GetNumberOfArrays();

  for(vtkIdType i = 0; i < numArrays; i++)
    {
    std::cout << reader->GetOutput()->GetCellData()->GetArrayName(i) << std::endl;;
    }
  }

  return EXIT_SUCCESS;
}
