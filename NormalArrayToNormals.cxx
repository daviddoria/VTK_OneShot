#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkPointData.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkXMLPolyDataWriter.h>

int main (int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.vtp OutputFile.vtp" << std::endl;
    return EXIT_FAILURE;
    }
    
  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
  
  vtkSmartPointer<vtkXMLPolyDataReader> reader = 
    vtkSmartPointer<vtkXMLPolyDataReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->Update();
  
  // Check for normals
  vtkDataArray* normals;
  
  normals = reader->GetOutput()->GetPointData()->GetArray("Normals");
  if(!normals)
    {
    std::cerr << "No named normals" << std::endl;
    //exit(-1);
    }
  normals = reader->GetOutput()->GetPointData()->GetNormals();
  if(!normals)
    {
    std::cerr << "No set normals" << std::endl;
    //exit(-1);
    }
    
  vtkSmartPointer<vtkPolyData> pd = 
    vtkSmartPointer<vtkPolyData>::New();
  pd->ShallowCopy(reader->GetOutput());
  pd->GetPointData()->SetNormals(normals);
  
  //write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(pd->GetProducerPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
