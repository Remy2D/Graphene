cmake_minimum_required(VERSION 3.5)
project(Graphene)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_PREFIX_PATH  "/home/remy/Qt/5.12.1/gcc_64/lib/cmake")

# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(DEPENDENCIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(SOURCE_FILES
    src/main.cpp

    src/common/Configuration.cpp
    src/common/Configuration.h
    src/common/Logger.cpp
    src/common/Logger.h

    src/dao/Bind.h
    src/dao/Bind.cpp
    src/dao/NoteBuilder.h
    src/dao/NoteBuilder.cpp
    src/dao/NoteListRepository.h
    src/dao/NoteListRepository.cpp

    src/model/Note.h
    src/model/NoteListModel.h
    src/model/NoteListModel.cpp
    src/model/Note.cpp

    src/text/GrapheneTextEdit.cpp
    src/text/GrapheneTextEdit.h
    src/text/HackishAsFuckHtmlFormatter.h
    src/text/HackishAsFuckHtmlFormatter.cpp

    src/timer/SaveEventHandler.cpp
    src/timer/SaveEventHandler.h

    src/utils/NoteListManager.h
    src/utils/NoteListManager.cpp
    src/utils/Digest.h
    src/utils/Digest.cpp

    src/window/graphenewindow.cpp
    src/window/graphenewindow.h
)

set(Boost_ROOT_DIR "/home/remy/workspace/pko/lib-boost")
set(Boost_INCLUDE_DIR "/home/remy/workspace/pko/lib-boost")
find_package(Boost 1.69.0 COMPONENTS system chrono filesystem date_time REQUIRED)

include_directories(
    src/
    ${Boost_INCLUDE_DIR}
)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Gui REQUIRED)

add_executable(Graphene ${SOURCE_FILES})

target_link_libraries(Graphene Qt5::Core Qt5::Widgets Qt5::Sql Qt5::Gui Boost::chrono Boost::filesystem Boost::date_time)