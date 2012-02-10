#include <vtkSmartPointer.h>
#include <vtkGraph.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkGraphReader.h>
#include <vtkGraphWriter.h>
#include <vtkPointData.h>
#include <vtkCellData.h>

int main (int argc, char *argv[])
{
  if(argc != 4)
    {
    std::cout << "Required arguments: InputFile.vtp OutputFile.graph ArrayName" << std::endl;
    return EXIT_FAILURE;
    }
    
  vtkstd::string vtpFilename = argv[1];
  vtkstd::string graphFilename = argv[2];
  vtkstd::string arrayName = argv[3];
  
  vtkSmartPointer<vtkXMLPolyDataReader> vtpReader =
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  vtpReader->SetFileName(vtpFilename.c_str());
  vtpReader->Update();
  
  vtkSmartPointer<vtkGraphReader> graphReader =
    vtkSmartPointer<vtkGraphReader>::New();
  graphReader->SetFileName(graphFilename.c_str());
  graphReader->Update();
  
  if(vtpReader->GetOutput()->GetNumberOfPoints() != graphReader->GetOutput()->GetNumberOfVertices())
    {
    std::cout << "Number of points must match number of vertices!" << std::endl;
    return EXIT_FAILURE;
    }

/*
  vtkSmartPointer<vtkGraph> graph = 
    vtkSmartPointer<vtkGraph>::New();
  graph->ShallowCopy(graphReader->GetOutput());
  
  graph->GetVertexData()->AddArray(vtpReader->GetOutput()->GetPointData()->GetArray(arrayName.c_str()));
  */
  
  graphReader->GetOutput()->GetVertexData()->AddArray(vtpReader->GetOutput()->GetPointData()->GetArray(arrayName.c_str()));

  vtkSmartPointer<vtkGraphWriter> writer = 
    vtkSmartPointer<vtkGraphWriter>::New();
  writer->SetFileName(graphFilename.c_str());
//  writer->SetInputConnection(graph->GetProducerPort());
  writer->SetInputConnection(graphReader->GetOutputPort());
  
  writer->Write();  

  return EXIT_SUCCESS;
}
