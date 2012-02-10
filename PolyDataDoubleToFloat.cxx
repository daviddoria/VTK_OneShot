#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkDoubleArray.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>

int main (int argc, char *argv[])
{
  if(argc != 4)
    {
    std::cout << "Required arguments: InputFile.vtp OutputFile.vtp" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string inputFilename = argv[1];
  vtkstd::string arrayName = argv[2];
  vtkstd::string outputFilename = argv[3];
  
  vtkSmartPointer<vtkXMLPolyDataReader> reader = 
      vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  vtkDoubleArray* doubleArray = vtkDoubleArray::SafeDownCast(reader->GetOutput()->GetPointData()->GetArray(arrayName.c_str()));
  
  vtkSmartPointer<vtkFloatArray> floatArray = 
    vtkSmartPointer<vtkFloatArray>::New();
  floatArray->SetName(arrayName.c_str());
  floatArray->SetNumberOfComponents(3);
  
  for(vtkIdType i = 0; i < doubleArray->GetNumberOfTuples(); i++)
    {
    double* val = doubleArray->GetTuple(i);
    float f[3];
    f[0] = static_cast<float>(val[0]);
    f[1] = static_cast<float>(val[1]);
    f[2] = static_cast<float>(val[2]);
    floatArray->InsertNextTuple(f);
    }
    
  vtkSmartPointer<vtkPolyData> polydata =
    vtkSmartPointer<vtkPolyData>::New();
  polydata->ShallowCopy(reader->GetOutput());
  polydata->GetPointData()->AddArray(floatArray);
  
  //write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
      vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(polydata->GetProducerPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
