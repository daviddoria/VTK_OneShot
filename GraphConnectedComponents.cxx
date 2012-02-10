#include <vtkSmartPointer.h>
#include <vtkMutableUndirectedGraph.h>
#include <vtkBoostConnectedComponents.h>
#include <vtkIntArray.h>
#include <vtkDataArray.h>
#include <vtkGraph.h>
#include <vtkGraphReader.h>
#include <vtkDataSetAttributes.h>

int main ( int argc, char *argv[] )
{
  //parse command line arguments
  if(argc != 2)
    {
    std::cout << "Required arguments: Filename" << std::endl;
    return EXIT_FAILURE;
    }
 
  vtkstd::string filename = argv[1];
  
  vtkSmartPointer<vtkGraphReader> reader = 
      vtkSmartPointer<vtkGraphReader>::New();
  reader->SetFileName(filename.c_str());
  reader->Update();
  
  vtkSmartPointer<vtkBoostConnectedComponents> connectedComponents = 
      vtkSmartPointer<vtkBoostConnectedComponents>::New();
  connectedComponents->SetInput(reader->GetOutput());
  connectedComponents->Update();
  
  vtkIntArray* components = vtkIntArray::SafeDownCast(connectedComponents->GetOutput()->GetVertexData()->GetArray("component"));
  
  std::vector<int> componentCount(10);
  for(unsigned int i = 0; i < componentCount.size(); i++)
    {
    componentCount[i] = 0;
    }
    
  std::cout << "There are " << components->GetNumberOfTuples() << " vertices." << std::endl;
  
  for(unsigned int i = 0; i < components->GetNumberOfTuples(); i++)
    {
    int val = components->GetValue(i);
    
    if(val >= componentCount.size())
      {
      std::cout << "val = " << val << " resizing to " << val + 1 << std::endl;
      componentCount.resize(val+1);
      }
    
    componentCount[val]++;
    //std::cout << val << std::endl;
    }
    
  for(unsigned int i = 0; i < componentCount.size(); i++)
    {
    std::cout << "Component " << i << " : " << componentCount[i] << std::endl;
    }
  
    std::cout << "Done." << std::endl;
    
  return EXIT_SUCCESS;
}
