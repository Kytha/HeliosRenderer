SET ( HELIOS_EDITOR_SOURCE
    Source/AssetBrowserPanel.cpp
    Source/ConsolePanel.cpp
    Source/EditorLayer.cpp
    Source/EnvironmentPanel.cpp
    Source/HeliosEditor.cpp
    Source/InspectorPanel.cpp
    Source/SceneHierarchyPanel.cpp
  )

SET ( HELIOS_EDITOR_HEADERS
    Source/EditorLayer.h
    Source/HeliosEditor.h
    Source/Panel.h
  )

ADD_EXECUTABLE ( HeliosEditor ${HELIOS_EDITOR_SOURCE} ${HELIOS_EDITOR_HEADERS} )

SET_TARGET_PROPERTIES ( HeliosEditor PROPERTIES OUTPUT_NAME HeliosEditor )
TARGET_LINK_LIBRARIES ( HeliosEditor HeliosEngine )
TARGET_INCLUDE_DIRECTORIES( HeliosEditor PUBLIC ../HeliosEngine/Source)

add_custom_target(CopyAssets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/Assets ${CMAKE_CURRENT_BINARY_DIR}/$<CONFIG>/Assets
)

add_dependencies(HeliosEditor CopyAssets)

INSTALL ( TARGETS
  HeliosEditor
  DESTINATION
  bin
  )
