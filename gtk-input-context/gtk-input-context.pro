include(../config.pri)

TEMPLATE = subdirs

system(pkg-config gtk+-2.0) {
    SUBDIRS *= src
    SUBDIRS += client-gtk
    client-gtk.CONFIG *= CONFIG
}

system(pkg-config gtk+-3.0) {
    SUBDIRS *= src
    SUBDIRS += client-gtk3
    client-gtk3.CONFIG *= CONFIG
}
