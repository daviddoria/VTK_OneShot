#include <vtkSmartPointer.h>
#include <vtkPolyData.h>
#include <vtkXMLPolyDataWriter.h>
#include <vtkDelimitedTextReader.h>
#include <vtkTable.h>
#include <vtkDoubleArray.h>
#include <vtkPointData.h>
#include <vtkVertexGlyphFilter.h>

int main (int argc, char *argv[])
{
  if(argc != 3)
    {
    std::cout << "Required arguments: InputFile.txt OutputFile.vtp" << std::endl;
    return EXIT_FAILURE;
    }
    
  std::string inputFilename = argv[1];
  std::string outputFilename = argv[2];
  
  vtkSmartPointer<vtkDelimitedTextReader> reader =
    vtkSmartPointer<vtkDelimitedTextReader>::New();
  reader->SetFileName(inputFilename.c_str());
  reader->DetectNumericColumnsOn();
  reader->SetFieldDelimiterCharacters(" ");
  reader->Update();

  vtkTable* table = reader->GetOutput();
 
  vtkSmartPointer<vtkPoints> points =
    vtkSmartPointer<vtkPoints>::New();
  vtkSmartPointer<vtkDoubleArray> normals =
    vtkSmartPointer<vtkDoubleArray>::New();
 
  normals->SetNumberOfComponents(3); //3d normals (ie x,y,z)
 
  std::cout << "Table has " << table->GetNumberOfRows()
            << " rows." << std::endl;
  std::cout << "Table has " << table->GetNumberOfColumns()
            << " columns." << std::endl;
 
  for(vtkIdType i = 0; i < table->GetNumberOfRows(); i++)
    { 
    points->InsertNextPoint((table->GetValue(i,0)).ToDouble(),
                            (table->GetValue(i,1)).ToDouble(),
                            (table->GetValue(i,2)).ToDouble());
 /*
    double n[3];
    n[0] = (table->GetValue(i,3)).ToDouble();
    n[1] = (table->GetValue(i,4)).ToDouble();
    n[2] = (table->GetValue(i,5)).ToDouble();
 
    std::cout << " n: " << n[0] << " " << n[1] << " " << n[2] << std::endl;
    normals->InsertNextTuple(n);
    */
    }
 
  std::cout << "There are " << points->GetNumberOfPoints()
            << " points." << std::endl;
 
  vtkSmartPointer<vtkPolyData> polydata =
    vtkSmartPointer<vtkPolyData>::New();
  polydata->SetPoints(points);
  //polydata->GetPointData()->SetNormals(normals);
 
  vtkSmartPointer<vtkVertexGlyphFilter> glyphFilter =
    vtkSmartPointer<vtkVertexGlyphFilter>::New();
  glyphFilter->SetInputConnection(polydata->GetProducerPort());
  glyphFilter->Update();
  
  // Write the result to a file
  vtkSmartPointer<vtkXMLPolyDataWriter> writer = 
    vtkSmartPointer<vtkXMLPolyDataWriter>::New();
  writer->SetInputConnection(glyphFilter->GetOutputPort());
  writer->SetFileName(outputFilename.c_str());
  writer->Write();
  
  return EXIT_SUCCESS;
}
