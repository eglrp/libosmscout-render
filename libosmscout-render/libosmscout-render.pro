TEMPLATE = app
SUBDIRS = libosmscout-render
TARGET = osmscoutrender
CONFIG += debug
LIBS += -ljansson -losmscout
SOURCES += \
	MapRenderer.cpp \
        RenderStyleConfigReader.cpp \
        test.cpp
HEADERS += \
	MapRenderer.h \
        RenderStyleConfig.hpp \
        RenderStyleConfigReader.h
