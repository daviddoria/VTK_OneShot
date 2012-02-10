#include <vtkSmartPointer.h>
#include <vtkGraph.h>
#include <vtkGraphReader.h>
#include <vtkPoints.h>
#include <vtkDataSetAttributes.h>

int main (int argc, char *argv[])
{
  if(argc != 2)
    {
    std::cout << "Required arguments: InputFile.graph" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string inputFilename = argv[1];
  
  vtkSmartPointer<vtkGraphReader> reader = 
      vtkSmartPointer<vtkGraphReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();

  std::cout << "Vertices: " << reader->GetOutput()->GetNumberOfVertices() << std::endl;
  std::cout << "Edges: " << reader->GetOutput()->GetNumberOfEdges() << std::endl;

  if(reader->GetOutput()->GetPoints())
    {
    std::cout << "Points: " << reader->GetOutput()->GetPoints()->GetNumberOfPoints() << std::endl;
    }

  // Get the vertex data arrays
  std::cout << std::endl << "Vertex Data Arrays: " << std::endl;
  {
  vtkIdType numArrays = reader->GetOutput()->GetVertexData()->GetNumberOfArrays();

  for(vtkIdType i = 0; i < numArrays; i++)
    {
    std::cout << reader->GetOutput()->GetVertexData()->GetArrayName(i) << " (" 
      << reader->GetOutput()->GetVertexData()->GetArray(i)->GetClassName() << ")" << std::endl;
    }
  }

  // Get the edge data arrays
  std::cout << std::endl << "Edge Data Arrays: " << std::endl;
  {
  vtkIdType numArrays = reader->GetOutput()->GetEdgeData()->GetNumberOfArrays();

  for(vtkIdType i = 0; i < numArrays; i++)
    {
    std::cout << reader->GetOutput()->GetEdgeData()->GetArrayName(i) << std::endl;;
    }
  }

  return EXIT_SUCCESS;
}
