cmake_minimum_required(VERSION 2.6)

PROJECT(VTK_OneShot)

FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(CombineRGB CombineRGB.cxx)
TARGET_LINK_LIBRARIES(CombineRGB vtkHybrid)

# ADD_EXECUTABLE(GraphIterator GraphIterator.cxx)
# TARGET_LINK_LIBRARIES(GraphIterator vtkHybrid)

ADD_EXECUTABLE(PolyDataInfo PolyDataInfo.cxx)
TARGET_LINK_LIBRARIES(PolyDataInfo vtkHybrid)

ADD_EXECUTABLE(CopyArrayFromPolyDataToGraph CopyArrayFromPolyDataToGraph.cxx)
TARGET_LINK_LIBRARIES(CopyArrayFromPolyDataToGraph vtkHybrid)

ADD_EXECUTABLE(GraphToPolyData GraphToPolyData.cxx)
TARGET_LINK_LIBRARIES(GraphToPolyData vtkHybrid)

# ADD_EXECUTABLE(PolyDataToGraph PolyDataToGraph.cxx)
# TARGET_LINK_LIBRARIES(PolyDataToGraph vtkHybrid)

ADD_EXECUTABLE(DelimitedFileToPolyData DelimitedFileToPolyData.cxx)
TARGET_LINK_LIBRARIES(DelimitedFileToPolyData vtkHybrid vtkInfovis)

# ADD_EXECUTABLE(NearestNeighborGraph NearestNeighborGraph.cxx)
# TARGET_LINK_LIBRARIES(NearestNeighborGraph vtkHybrid)

# ADD_EXECUTABLE(PTXtoJPEG PTXtoJPEG.cxx)
# TARGET_LINK_LIBRARIES(PTXtoJPEG vtkHybrid)

# ADD_EXECUTABLE(EMST EMST.cxx)
# TARGET_LINK_LIBRARIES(EMST vtkHybrid)

ADD_EXECUTABLE(NormalArrayToNormals NormalArrayToNormals.cxx)
TARGET_LINK_LIBRARIES(NormalArrayToNormals vtkHybrid)

# ADD_EXECUTABLE(RBNNGraph RBNNGraph.cxx)
# TARGET_LINK_LIBRARIES(RBNNGraph vtkHybrid)

# requires VTK_USE_BOOST
ADD_EXECUTABLE(GraphConnectedComponents GraphConnectedComponents.cxx)
TARGET_LINK_LIBRARIES(GraphConnectedComponents vtkHybrid vtkInfovis)

# ADD_EXECUTABLE(PointSetNormalEstimation PointSetNormalEstimation.cxx)
# TARGET_LINK_LIBRARIES(PointSetNormalEstimation vtkHybrid)

ADD_EXECUTABLE(TreeToPolyData TreeToPolyData.cxx)
TARGET_LINK_LIBRARIES(TreeToPolyData vtkHybrid)

ADD_EXECUTABLE(GraphDisplayFirstFiveValues GraphDisplayFirstFiveValues.cxx)
TARGET_LINK_LIBRARIES(GraphDisplayFirstFiveValues vtkHybrid)

# ADD_EXECUTABLE(PointSetNormalQuality PointSetNormalQuality.cxx)
# TARGET_LINK_LIBRARIES(PointSetNormalQuality vtkHybrid)

ADD_EXECUTABLE(XYZtoVTP XYZtoVTP.cxx)
TARGET_LINK_LIBRARIES(XYZtoVTP vtkHybrid)

ADD_EXECUTABLE(GraphDoubleToFloat GraphDoubleToFloat.cxx)
TARGET_LINK_LIBRARIES(GraphDoubleToFloat vtkHybrid)

ADD_EXECUTABLE(PolyDataDisplayFirstFiveValues PolyDataDisplayFirstFiveValues.cxx)
TARGET_LINK_LIBRARIES(PolyDataDisplayFirstFiveValues vtkHybrid)

ADD_EXECUTABLE(GraphInfo GraphInfo.cxx)
TARGET_LINK_LIBRARIES(GraphInfo vtkHybrid)

ADD_EXECUTABLE(PolyDataDoubleToFloat PolyDataDoubleToFloat.cxx)
TARGET_LINK_LIBRARIES(PolyDataDoubleToFloat vtkHybrid)

ADD_EXECUTABLE(VTPtoXYZ VTPtoXYZ.cxx)
TARGET_LINK_LIBRARIES(VTPtoXYZ vtkHybrid)

# ADD_EXECUTABLE(AddVerticesToPoints AddVerticesToPoints.cxx)
# TARGET_LINK_LIBRARIES(AddVerticesToPoints vtkHybrid)
# 
