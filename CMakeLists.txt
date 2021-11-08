cmake_minimum_required(VERSION 3.14)

project(HikvisonPCL VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Widgets QuickWidgets REQUIRED)

set(OpenCV_INCLUDE_DIR /home/siky/Applications/opencv/build/install/include)
set(OpenCV_LIB_DIR /home/siky/Applications/opencv/build/install/lib)
#find_package(OpenCV REQUIRED)
set(MegEngine_DIR /home/siky/Applications/MegEngine/build_dir/host/MGE_WITH_CUDA_OFF/MGE_INFERENCE_ONLY_ON/Release/install)
set(MegEngine_INCLUDE_DIR ${MegEngine_DIR}/include)
set(MegEngine_LIB_DIR ${MegEngine_DIR}/lib/MegEngine)

include_directories(Hikvison/incCn)
message("opencv include :${OpenCV_INCLUDE_DIR}")
include_directories(${OpenCV_INCLUDE_DIR})
link_directories($MegEngine_LIB_DIR)
link_directories(Hikvison/lib)
link_directories(Hikvison/lib/HCNetSDKCom)
link_directories(${OpenCV_LIB_DIR})

get_property(dirs DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY INCLUDE_DIRECTORIES)
message(">>> include_dirs=${dirs}") #打印一下目录情况



set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        hikvisonhandlercstyelfuncs.cpp
        hikvisonhandler.cpp
        hkvsplayer.cpp
        imageviewer.h
        imageviewer.cpp
        hikvisonviewer.h
        hikvisonviewer.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(HikvisonPCL
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET HikvisonPCL APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(HikvisonPCL SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(HikvisonPCL
          ${PROJECT_SOURCES}
        )
    endif()
endif()


target_compile_definitions(HikvisonPCL
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(HikvisonPCL
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickWidgets opencv_core opencv_imgproc opencv_highgui)
target_link_libraries(HikvisonPCL
  PRIVATE HCCore AudioRender NPQos PlayCtrl SuperRender crypto hcnetsdk hpr openal ssl z AudioIntercom HCAlarm HCCoreDevCfg HCDisplay HCGeneralCfgMgr HCIndustry HCPlayBack HCPreview HCVoiceTalk StreamTransClient SystemTransform analyzedata iconv2)

set_target_properties(HikvisonPCL PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(HikvisonPCL)
    qt_finalize_executable(HikvisonPCL)
endif()
