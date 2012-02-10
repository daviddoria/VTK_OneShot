#include <vtkSmartPointer.h>
//#include <vtkGraph.h>
#include <vtkMutableUndirectedGraph.h>
#include <vtkGraphReader.h>
#include <vtkGraphWriter.h>
#include <vtkDoubleArray.h>
#include <vtkFloatArray.h>
#include <vtkDataSetAttributes.h>

int main (int argc, char *argv[])
{
  if(argc != 4)
    {
    std::cout << "Required arguments: InputFile.graph OutputFile.graph" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string inputFilename = argv[1];
  vtkstd::string arrayName = argv[2];
  vtkstd::string outputFilename = argv[3];
  
  vtkSmartPointer<vtkGraphReader> reader = 
      vtkSmartPointer<vtkGraphReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  vtkDoubleArray* doubleArray = vtkDoubleArray::SafeDownCast(reader->GetOutput()->GetVertexData()->GetArray(arrayName.c_str()));
  
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
  
  vtkSmartPointer<vtkMutableUndirectedGraph> graph = 
    vtkSmartPointer<vtkMutableUndirectedGraph>::New();
  graph->ShallowCopy(reader->GetOutput());
  graph->GetVertexData()->AddArray(floatArray);
  
  //write the result to a file
  vtkSmartPointer<vtkGraphWriter> writer = 
      vtkSmartPointer<vtkGraphWriter>::New();
  writer->SetInputConnection(graph->GetProducerPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
