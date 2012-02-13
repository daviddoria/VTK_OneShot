cmake_minimum_required(VERSION 2.6)

PROJECT(VTK_OneShot)
SET( INSTALL_DIR ${CMAKE_INSTALL_PREFIX} )

# vtkos is a prefix (stands for VTK One Shot) so that you can type vtkos[tab] in a terminal and it will show you all of the possible tools to run.
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

ADD_EXECUTABLE(vtkosCombineRGB CombineRGB.cxx)
TARGET_LINK_LIBRARIES(vtkosCombineRGB ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosCombineRGB RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosGraphIterator GraphIterator.cxx)
# TARGET_LINK_LIBRARIES(vtkosGraphIterator ${VTK_LIBRARIES})
#INSTALL( TARGETS vtkosGraphIterator RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosPolyDataInfo PolyDataInfo.cxx)
TARGET_LINK_LIBRARIES(vtkosPolyDataInfo ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosPolyDataInfo RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosCopyArrayFromPolyDataToGraph CopyArrayFromPolyDataToGraph.cxx)
TARGET_LINK_LIBRARIES(vtkosCopyArrayFromPolyDataToGraph ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosCopyArrayFromPolyDataToGraph RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosGraphToPolyData GraphToPolyData.cxx)
TARGET_LINK_LIBRARIES(vtkosGraphToPolyData ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosGraphToPolyData RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosPolyDataToGraph PolyDataToGraph.cxx)
# TARGET_LINK_LIBRARIES(vtkosPolyDataToGraph ${VTK_LIBRARIES})
#INSTALL( TARGETS vtkosPolyDataToGraph RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosDelimitedFileToPolyData DelimitedFileToPolyData.cxx)
TARGET_LINK_LIBRARIES(vtkosDelimitedFileToPolyData ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosDelimitedFileToPolyData RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosNearestNeighborGraph NearestNeighborGraph.cxx)
# TARGET_LINK_LIBRARIES(vtkosNearestNeighborGraph ${VTK_LIBRARIES})
#INSTALL( TARGETS vtkosNearestNeighborGraph RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosPTXtoJPEG PTXtoJPEG.cxx)
# TARGET_LINK_LIBRARIES(vtkosPTXtoJPEG ${VTK_LIBRARIES})
#INSTALL( TARGETS vtkosPTXtoJPEG RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosEMST EMST.cxx)
# TARGET_LINK_LIBRARIES(vtkosEMST ${VTK_LIBRARIES})
#INSTALL( TARGETS vtkosEMST RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosNormalArrayToNormals NormalArrayToNormals.cxx)
TARGET_LINK_LIBRARIES(vtkosNormalArrayToNormals ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosNormalArrayToNormals RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosRBNNGraph RBNNGraph.cxx)
# TARGET_LINK_LIBRARIES(vtkosRBNNGraph ${VTK_LIBRARIES})
#INSTALL( TARGETS vtkosRBNNGraph RUNTIME DESTINATION ${INSTALL_DIR} )

# requires VTK_USE_BOOST
ADD_EXECUTABLE(vtkosGraphConnectedComponents GraphConnectedComponents.cxx)
TARGET_LINK_LIBRARIES(vtkosGraphConnectedComponents ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosGraphConnectedComponents RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(PointSetNormalEstimation PointSetNormalEstimation.cxx)
# TARGET_LINK_LIBRARIES(PointSetNormalEstimation ${VTK_LIBRARIES})
# INSTALL( TARGETS vtkosPointSetNormalEstimation RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosTreeToPolyData TreeToPolyData.cxx)
TARGET_LINK_LIBRARIES(vtkosTreeToPolyData ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosTreeToPolyData RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosGraphDisplayFirstFiveValues GraphDisplayFirstFiveValues.cxx)
TARGET_LINK_LIBRARIES(vtkosGraphDisplayFirstFiveValues ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosGraphDisplayFirstFiveValues RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosPointSetNormalQuality PointSetNormalQuality.cxx)
# TARGET_LINK_LIBRARIES(vtkosPointSetNormalQuality ${VTK_LIBRARIES})
# INSTALL( TARGETS vtkosPointSetNormalQuality RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosXYZtoVTP XYZtoVTP.cxx)
TARGET_LINK_LIBRARIES(vtkosXYZtoVTP ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosXYZtoVTP RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosGraphDoubleToFloat GraphDoubleToFloat.cxx)
TARGET_LINK_LIBRARIES(vtkosGraphDoubleToFloat ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosGraphDoubleToFloat RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosPolyDataDisplayFirstFiveValues PolyDataDisplayFirstFiveValues.cxx)
TARGET_LINK_LIBRARIES(vtkosPolyDataDisplayFirstFiveValues ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosPolyDataDisplayFirstFiveValues RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosGraphInfo GraphInfo.cxx)
TARGET_LINK_LIBRARIES(vtkosGraphInfo ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosGraphInfo RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosPolyDataDoubleToFloat PolyDataDoubleToFloat.cxx)
TARGET_LINK_LIBRARIES(vtkosPolyDataDoubleToFloat ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosPolyDataDoubleToFloat RUNTIME DESTINATION ${INSTALL_DIR} )

ADD_EXECUTABLE(vtkosVTPtoXYZ VTPtoXYZ.cxx)
TARGET_LINK_LIBRARIES(vtkosVTPtoXYZ ${VTK_LIBRARIES})
INSTALL( TARGETS vtkosVTPtoXYZ RUNTIME DESTINATION ${INSTALL_DIR} )

# ADD_EXECUTABLE(vtkosAddVerticesToPoints AddVerticesToPoints.cxx)
# TARGET_LINK_LIBRARIES(vtkosAddVerticesToPoints ${VTK_LIBRARIES})
# INSTALL( TARGETS vtkosAddVerticesToPoints RUNTIME DESTINATION ${INSTALL_DIR} )
