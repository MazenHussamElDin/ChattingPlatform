cmake_minimum_required(VERSION 3.5)

project(ChattingPlatform VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainpage.cpp
        mainpage.h
        mainpage.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ChattingPlatform
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        loginpage.h loginpage.cpp loginpage.ui
        signuppage.h signuppage.cpp signuppage.ui
        Chat.cpp Chat.hpp Hmap.cpp Hmap.hpp LinkedList.cpp LinkedList.hpp main.cpp Makefile Message.cpp Message.hpp Person.cpp SystemManager.cpp SystemManager.hpp User.cpp User.hpp userdata.txt

        chatpage.h chatpage.cpp chatpage.ui
        addaccountpage.h addaccountpage.cpp addaccountpage.ui
        newuserpage.h newuserpage.cpp newuserpage.ui
        createchatpage.h createchatpage.cpp createchatpage.ui



    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ChattingPlatform APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ChattingPlatform SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ChattingPlatform
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ChattingPlatform PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.ChattingPlatform)
endif()
set_target_properties(ChattingPlatform PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ChattingPlatform
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ChattingPlatform)
endif()
