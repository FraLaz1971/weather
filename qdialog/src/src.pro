TEMPLATE = app
TARGET = qdialog
DESTDIR = ../bin
CONFIG += qt
CONFIG += qtestlib
QT += xml
MOC_DIR = .moc
OBJECTS_DIR = .obj
QMAKE_CFLAGS += -g \
    -I. \
    -I.. \
    -I../include
QMAKE_CXXFLAGS += -g \
    -I. \
    -I.. \
    -I../include
QMAKE_LFLAGS += -g \
    -L../lib
DEFINES += HAVE_LOCALE

# #### 3RD PARTY #####
HEADERS += 3rdparty/utils.h \
    3rdparty/cxmlbase.h \
    3rdparty/cxmlsettings.h \
    3rdparty/capplication.h \
    sboxoptions.h \
    strutils.h \
    cinputbox.h \
    retcodes.h \
    ccalendarbox.h \
    cfilebox.h \
    ctimebox.h \
    cgaugebox.h \
    cpausebox.h \
    ctextbox.h \
    ctailbox.h \
    cformbox.h \
    fileutils.h \
    3rdparty/ucs2.h \
    3rdparty/defines.h
SOURCES += 3rdparty/utils.cpp \
    3rdparty/cxmlbase.cpp \
    3rdparty/cxmlsettings.cpp \
    3rdparty/capplication.cpp \
    strutils.cpp \
    cinputbox.cpp \
    ccalendarbox.cpp \
    cfilebox.cpp \
    ctimebox.cpp \
    cgaugebox.cpp \
    cpausebox.cpp \
    ctextbox.cpp \
    ctailbox.cpp \
    cformbox.cpp \
    fileutils.cpp

# ####### BASE ########
HEADERS += config.h \
    main.h
SOURCES += main.cpp

# ####### CDialogApp ########
HEADERS += cdialogapp.h \
    cmsgbox.h \
    cmenubox.h
SOURCES += cdialogapp.cpp \
    cmsgbox.cpp \
    cmenubox.cpp

# ##
HEADERS = $$unique(HEADERS)
SOURCES = $$unique(SOURCES)
FORMS = $$unique(FORMS)
RESOURCES = $$unique(RESOURCES)
sources.files = $$SOURCES \
    $$HEADERS \
    $$FORMS \
    $$RESOURCES \
    $$TRANSLATIONS \
    src.pro
