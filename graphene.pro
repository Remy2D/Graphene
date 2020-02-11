#-------------------------------------------------
#
# Project created by QtCreator 2019-03-16T00:18:46
#
#-------------------------------------------------

QT       += core gui designer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = graphene
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(src/text/GrapheneTextEdit.pri)
include(src/view/GrapheneListView.pri)

CONFIG += c++11 designer plugin

SOURCES += \
    src/window/graphenewindow.cpp \
    src/main.cpp \
    build-graphene-debug/moc_graphenewindow.cpp \
    cmake-build-debug/CMakeFiles/3.13.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.14.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.14.5/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.15.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/feature_tests.cxx \
    cmake-build-debug/Graphene_autogen/ML7GKOQR6K/moc_graphenewindow.cpp \
    cmake-build-debug/Graphene_autogen/ML7GKOQR6K/moc_GrapheneWindow.cpp \
    cmake-build-debug/Graphene_autogen/UVLADIE3JM/moc_graphenewindow.cpp \
    cmake-build-debug/Graphene_autogen/mocs_compilation.cpp \
    src/model/Note.cpp \
    src/model/NoteListModel.cpp \
    src/timer/TimerService.cpp \
    src/window/GrapheneWindow.cpp \
    src/main.cpp \
    cmake-build-debug/CMakeFiles/3.13.2/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.14.3/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.14.5/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.15.3/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/feature_tests.c \
    build-graphene-debug/moc_graphenewindow.cpp \
    cmake-build-debug/CMakeFiles/3.13.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.14.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.14.5/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.15.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/feature_tests.cxx \
    cmake-build-debug/Graphene_autogen/ML7GKOQR6K/moc_graphenewindow.cpp \
    cmake-build-debug/Graphene_autogen/ML7GKOQR6K/moc_GrapheneWindow.cpp \
    cmake-build-debug/Graphene_autogen/UVLADIE3JM/moc_graphenewindow.cpp \
    cmake-build-debug/Graphene_autogen/mocs_compilation.cpp \
    src/model/Note.cpp \
    src/model/NoteListModel.cpp \
    src/timer/TimerService.cpp \
    src/window/GrapheneWindow.cpp \
    src/main.cpp \
    cmake-build-debug/CMakeFiles/3.13.2/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.14.3/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.14.5/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.15.3/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/feature_tests.c \
    src/text/GrapheneTextEdit.cpp \
    build-graphene-debug/moc_graphenewindow.cpp \
    cmake-build-debug/CMakeFiles/3.13.2/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.14.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.14.5/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/3.15.3/CompilerIdCXX/CMakeCXXCompilerId.cpp \
    cmake-build-debug/CMakeFiles/feature_tests.cxx \
    cmake-build-debug/Graphene_autogen/ML7GKOQR6K/moc_graphenewindow.cpp \
    cmake-build-debug/Graphene_autogen/mocs_compilation.cpp \
    src/model/Note.cpp \
    src/model/NoteListModel.cpp \
    src/text/GrapheneTextEdit.cpp \
    src/timer/TimerService.cpp \
    src/window/graphenewindow.cpp \
    src/main.cpp \
    cmake-build-debug/CMakeFiles/3.13.2/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.14.3/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.14.5/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/3.15.3/CompilerIdC/CMakeCCompilerId.c \
    cmake-build-debug/CMakeFiles/feature_tests.c

HEADERS += \
    src/window/graphenewindow.h \
    build-graphene-debug/moc_predefs.h \
    build-graphene-debug/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/build-graphene-debug/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/cmake-build-debug/Graphene_autogen/include/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/moc_predefs.h \
    src/model/Note.h \
    src/model/NoteListModel.h \
    src/timer/TimerService.h \
    src/window/GrapheneWindow.h \
    build-graphene-debug/moc_predefs.h \
    build-graphene-debug/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/build-graphene-debug/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/cmake-build-debug/Graphene_autogen/include/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/moc_predefs.h \
    src/model/Note.h \
    src/model/NoteListModel.h \
    src/timer/TimerService.h \
    src/window/GrapheneWindow.h \
    src/text/GrapheneTextEdit.h \
    src/window/graphenewindow.h \
    build-graphene-debug/moc_predefs.h \
    build-graphene-debug/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/include/build-graphene-debug/ui_graphenewindow.h \
    cmake-build-debug/Graphene_autogen/moc_predefs.h \
    src/model/Note.h \
    src/model/NoteListModel.h \
    src/text/GrapheneTextEdit.h \
    src/timer/TimerService.h \
    src/window/graphenewindow.h

FORMS += \
    src/window/graphenewindow.ui \
    src/window/graphenewindow.ui \
    src/window/graphenewindow.ui \
    src/window/graphenewindow.ui \
    src/window/graphenewindow.ui \
    src/window/graphenewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    graphene.pro \
    graphene.pro

DISTFILES += \
    build-graphene-debug/graphene \
    CMakeLists.txt \
    CMakeLists.txt \
    src/text/GrapheneTextEdit.pri \
    src/text/GrapheneListView.pri \
    resources/images/checked.png \
    resources/images/unchecked.png \
    CMakeLists.txt

RESOURCES += \
    resources.qrc \
    resources.qrc
