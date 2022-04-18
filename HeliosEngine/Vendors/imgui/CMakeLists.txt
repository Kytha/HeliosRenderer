SET ( IMGUI_SOURCE
      imgui_demo.cpp
      imgui_draw.cpp
      imgui_tables.cpp
      imgui_widgets.cpp
      imgui.cpp
  )

SET ( IMGUI_HEADERS
    imgui.h
    imgui_internal.h
    imconfig.h
    imstb_rectpack.h
    imstb_textedit.h
    imstb_truetype.h
  )

ADD_LIBRARY ( imgui STATIC
  ${IMGUI_SOURCE}
  ${IMGUI_HEADERS}
  )

TARGET_INCLUDE_DIRECTORIES(imgui PUBLIC /backends)
