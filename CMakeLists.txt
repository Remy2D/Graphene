cmake_minimum_required(VERSION 3.5)
project(Graphene)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_PREFIX_PATH  "/home/remy/Qt/5.12.1/gcc_64/lib/cmake")

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES src/main.cpp src/graphenewindow.cpp src/graphenewindow.h src/model/note.h)
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(Graphene ${SOURCE_FILES})

target_link_libraries(Graphene Qt5::Core Qt5::Widgets Qt5::Sql Qt5::Gui)