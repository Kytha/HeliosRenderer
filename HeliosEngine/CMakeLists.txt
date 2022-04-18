########################### SOURCE CODE ########################################
SET ( HELIOS_SOURCE
    Source/Core/Application.cpp
    Source/Core/OperatingSystem.cpp
    Source/Core/Window.cpp
    Source/Core/LayerStack.cpp
    Source/Platform/WindowsOS.cpp
    Source/Platform/WindowsWindow.cpp
    Source/UI/ImGuiContext.cpp
    Source/UI/ImGuiBuild.cpp
  )

SET ( HELIOS_HEADERS
    Source/helios.h
    Source/Core/Core.h
    Source/Core/Application.h
    Source/Core/Window.h
    Source/Core/OperatingSystem.h
    Source/Platform/WindowsOS.h
    Source/Core/Layer.h
    Source/Core/LayerStack.h
    Source/UI/ImGuiContext.h
  )

############################# DEPENDENCIES ###########################################

ADD_LIBRARY ( HeliosEngine STATIC
  ${HELIOS_SOURCE}
  ${HELIOS_HEADERS}
  )

ADD_SUBDIRECTORY(Vendors/glfw)
ADD_SUBDIRECTORY(Vendors/Glad)
ADD_SUBDIRECTORY(Vendors/imgui)
ADD_SUBDIRECTORY(Vendors/glm)

TARGET_INCLUDE_DIRECTORIES( HeliosEngine PUBLIC Source PUBLIC Vendors/glfw/include PUBLIC Vendors/glad/include PUBLIC Vendors/imgui PUBLIC Vendors/imgui/backends PUBLIC Vendors/glm )
TARGET_LINK_LIBRARIES( HeliosEngine PUBLIC glfw PUBLIC Glad PUBLIC imgui PUBLIC glm)

TARGET_PRECOMPILE_HEADERS ( HeliosEngine
    PUBLIC "Source/hlpch.h"
  )

INSTALL ( TARGETS
    HeliosEngine
    DESTINATION
    lib
  )