#-------------------------------------------------
#
# Project created by QtCreator 2019-03-17T21:40:30
#
#-------------------------------------------------

QT       += core gui widgets dbus thelib ModemManagerQt NetworkManagerQt network

TARGET = tsnm
TEMPLATE = lib
CONFIG += plugin

INCLUDEPATH += ../../shell/statuscenter/

LIBS += -L$$OUT_PWD/../../theshell-lib/

INCLUDEPATH += $$PWD/../../theshell-lib
DEPENDPATH += $$PWD/../../theshell-lib

blueprint {
    DEFINES += "BLUEPRINT"

    DEFINES += "SHAREDIR=\\\"/usr/share/theshellb/tsnm/\\\""
} else {
    DEFINES += "SHAREDIR=\\\"/usr/share/theshell/tsnm/\\\""
}

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

TRANSLATIONS += translations/vi_VN.ts \
    translations/da_DK.ts \
    translations/es_ES.ts \
    translations/lt_LT.ts \
    translations/nl_NL.ts \
    translations/pl_PL.ts \
    translations/pt_BR.ts \
    translations/ru_RU.ts \
    translations/sv_SE.ts \
    translations/en_AU.ts \
    translations/en_US.ts \
    translations/en_GB.ts \
    translations/en_NZ.ts \
    translations/de_DE.ts \
    translations/id_ID.ts \
    translations/au_AU.ts \
    translations/it_IT.ts \
    translations/nb_NO.ts \
    translations/no_NO.ts \
    translations/ro_RO.ts \
    translations/cy_GB.ts \
    translations/fr_FR.ts

qtPrepareTool(LUPDATE, lupdate)
genlang.commands = "$$LUPDATE -no-obsolete -source-language en_US $$_PRO_FILE_"

qtPrepareTool(LRELEASE, lrelease)
rellang.commands = "$$LRELEASE -removeidentical $$_PRO_FILE_"
QMAKE_EXTRA_TARGETS = genlang rellang
PRE_TARGETDEPS = genlang rellang

unix {
    translations.files = translations/*.qm

    blueprint {
        target.path = /usr/lib/theshellb/panes/
        translations.path = /usr/share/theshellb/tsnm/translations
    } else {
        target.path = /usr/lib/theshell/panes/
        translations.path = /usr/share/theshell/tsnm/translations
    }
    INSTALLS += target translations
}

HEADERS += \
    networkmanager/connectioneditor/connectioneditor.h \
    networkmanager/connectioneditor/devicesettings.h \
    networkmanager/connectioneditor/devicesettingsmodel.h \
    networkmanager/connectioneditor/panes/gsmsettingspane.h \
    networkmanager/connectioneditor/panes/settingpane.h \
    networkmanager/connectioneditor/panes/simpinpane.h \
    networkmanager/devicepanel.h \
    networkmanager/enums.h \
    networkmanager/popovers/simpinrequest.h \
    plugin.h \
    networkmanager/availablenetworkslist.h \
    networkmanager/networkwidget.h \
    networkmanager/savednetworkslist.h \
    networkmanager/chunkwidget.h \
    networkmanager/securityinformationwidget.h \
    networkmanager/editwidget.h

SOURCES += \
    networkmanager/connectioneditor/connectioneditor.cpp \
    networkmanager/connectioneditor/devicesettings.cpp \
    networkmanager/connectioneditor/devicesettingsmodel.cpp \
    networkmanager/connectioneditor/panes/gsmsettingspane.cpp \
    networkmanager/connectioneditor/panes/settingpane.cpp \
    networkmanager/connectioneditor/panes/simpinpane.cpp \
    networkmanager/devicepanel.cpp \
    networkmanager/popovers/simpinrequest.cpp \
    plugin.cpp \
    networkmanager/availablenetworkslist.cpp \
    networkmanager/networkwidget.cpp \
    networkmanager/savednetworkslist.cpp \
    networkmanager/chunkwidget.cpp \
    networkmanager/securityinformationwidget.cpp \
    networkmanager/editwidget.cpp

DISTFILES += \
    NetworkPane.json

FORMS += \
    networkmanager/connectioneditor/connectioneditor.ui \
    networkmanager/connectioneditor/devicesettings.ui \
    networkmanager/connectioneditor/panes/gsmsettingspane.ui \
    networkmanager/connectioneditor/panes/simpinpane.ui \
    networkmanager/devicepanel.ui \
    networkmanager/networkwidget.ui \
    networkmanager/chunkwidget.ui \
    networkmanager/popovers/simpinrequest.ui \
    networkmanager/securityinformationwidget.ui \
    networkmanager/editwidget.ui

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += ModemManager libnm
