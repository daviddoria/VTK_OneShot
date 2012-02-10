#include <vtkSmartPointer.h>
#include <vtkMutableUndirectedGraph.h>

#include "vtkGraphIterator.h"

bool TestBFS(vtkGraph* g, vtkIdType vert);
bool TestDFS(vtkGraph* g, vtkIdType vert);

int main(int, char *[])
{
  vtkSmartPointer<vtkMutableUndirectedGraph> g =
      vtkSmartPointer<vtkMutableUndirectedGraph>::New();

  /*
        v0
       / \
      v1-v2
     / \ /
    v3 v4
  */
  // Create vertices
  vtkIdType v0 = g->AddVertex();
  vtkIdType v1 = g->AddVertex();
  vtkIdType v2 = g->AddVertex();
  vtkIdType v3 = g->AddVertex();
  vtkIdType v4 = g->AddVertex();

  // Create edges
  g->AddEdge(v0, v1);
  g->AddEdge(v0, v2);
  g->AddEdge(v1, v2);
  g->AddEdge(v1, v3);
  g->AddEdge(v1, v4);
  g->AddEdge(v2, v4);

  bool bfs = TestBFS(g, v0);
  if(!bfs)
    {
    std::cerr << "TestBFS failed!" << std::endl;
    return EXIT_FAILURE;
    }

  bool dfs = TestDFS(g, v0);
  if(!dfs)
    {
    std::cerr << "TestDFS failed!" << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}

bool TestBFS(vtkGraph* g, vtkIdType vert)
{
  std::cout << "TestBFS:" << std::endl;
  vtkSmartPointer<vtkGraphIterator> iterator =
    vtkSmartPointer<vtkGraphIterator>::New();
  iterator->SetGraph(g);
  iterator->SetStartVertex(vert);
  iterator->SetSearchOrder(vtkGraphIterator::BREADTHFIRST);
  iterator->Initialize();

  std::cout << "Next vertices ";
  while(iterator->HasNext())
    {
    vtkIdType nextVertex = iterator->Next();
    std::cout << nextVertex << " ";
    }
  std::cout << std::endl;
  return true;
}

bool TestDFS(vtkGraph* g, vtkIdType vert)
{
  std::cout << "TestDFS:" << std::endl;

  vtkSmartPointer<vtkGraphIterator> iterator =
    vtkSmartPointer<vtkGraphIterator>::New();
  iterator->SetGraph(g);
  iterator->SetStartVertex(vert);
  iterator->SetSearchOrder(vtkGraphIterator::DEPTHFIRST);
  iterator->Initialize();

  while(iterator->HasNext())
    {
    vtkIdType nextVertex = iterator->Next();
    std::cout << nextVertex << " ";
    }

  std::cout << std::endl;
  return true;
}
