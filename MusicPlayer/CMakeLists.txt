cmake_minimum_required(VERSION 3.19)
project(MusicPlayer LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

set(CMAKE_AUTORCC ON)


qt_add_executable(MusicPlayer
    WIN32 MACOSX_BUNDLE
    src/main.cpp
    src/musicplayer.cpp
    src/musicplayer.h
    src/musicplayer.ui
    src/headwidget.cpp
    src/headwidget.h
    Images.qrc
)


# 2. 把src目录加入头文件搜索路径
target_include_directories(MusicPlayer
    PRIVATE
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/images
)

target_link_libraries(MusicPlayer
    PRIVATE
        Qt::Core
        Qt::Widgets
)

install(TARGETS MusicPlayer
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET MusicPlayer
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
