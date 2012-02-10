#include "vtkObjectFactory.h" //for new() macro
#include "vtkInformation.h"
#include "vtkInformationVector.h"
#include "vtkPolyData.h"
#include "vtkSmartPointer.h"
#include "vtkCellArray.h"

#include "vtkAddVerticesToPoints.h"

vtkStandardNewMacro(vtkAddVerticesToPoints);
vtkCxxRevisionMacro(vtkAddVerticesToPoints, "$Revision$");


//-----------------------------------------------------------------------------
vtkAddVerticesToPoints::vtkAddVerticesToPoints()
{
}


//-----------------------------------------------------------------------------
vtkAddVerticesToPoints::~vtkAddVerticesToPoints()
{
}


//----------------------------------------------------------------------------
void vtkAddVerticesToPoints::AddSourceConnection(vtkAlgorithmOutput* input)
{
  this->AddInputConnection(1, input);
}


//----------------------------------------------------------------------------
void vtkAddVerticesToPoints::RemoveAllSources()
{
  this->SetInputConnection(1, 0);
}


//----------------------------------------------------------------------------
int vtkAddVerticesToPoints::FillInputPortInformation( int port, vtkInformation* info )
{
  if (!this->Superclass::FillInputPortInformation(port, info))
    {
    return 0;
    }
  if ( port == 0 )
    {
    //info->Set( vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkPolyData" );
    info->Set( vtkAlgorithm::INPUT_REQUIRED_DATA_TYPE(), "vtkDataSet" );
    return 1;
    }
  return 0;
}


//----------------------------------------------------------------------------
int vtkAddVerticesToPoints::RequestData(vtkInformation *vtkNotUsed(request),
                              vtkInformationVector **inputVector,
                              vtkInformationVector *outputVector)
{
  // get the info objects
  vtkInformation *inInfo = inputVector[0]->GetInformationObject(0);
  vtkInformation *outInfo = outputVector->GetInformationObject(0);

  // get the input and output
//  vtkPolyData *input = vtkPolyData::SafeDownCast(
  vtkDataSet *input = vtkPolyData::SafeDownCast(
                                                 inInfo->Get(vtkDataObject::DATA_OBJECT()));
  vtkPolyData *output = vtkPolyData::SafeDownCast(
                                                  outInfo->Get(vtkDataObject::DATA_OBJECT()));


  vtkSmartPointer<vtkCellArray> Vertices = vtkSmartPointer<vtkCellArray>::New();
 
  for ( unsigned int i = 0; i < input->GetNumberOfPoints(); ++i )
  { 
    vtkIdType id[1];
    id[0] = i;
    
    Vertices->InsertNextCell(1,id);
  }

  vtkSmartPointer<vtkPoints> Points = vtkSmartPointer<vtkPoints>::New();

  for ( unsigned int i = 0; i < input->GetNumberOfPoints(); ++i )
    { 
    double p[3];
    input->GetPoint(i, p);
    Points->InsertNextPoint(p);
    }

  vtkSmartPointer<vtkPolyData> OutputPolydata = vtkSmartPointer<vtkPolyData>::New();
  OutputPolydata->SetPoints(Points);
  OutputPolydata->SetVerts(Vertices);

  output->ShallowCopy(OutputPolydata);

  return 1;
}



////////// External Operators /////////////

void vtkAddVerticesToPoints::PrintSelf(ostream &os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os,indent);
}
