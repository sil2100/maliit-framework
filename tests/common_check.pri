QMAKE_EXTRA_TARGETS += check
check.target = check
check.commands = \
    TESTING_IN_SANDBOX=1 \
    TESTPLUGIN_PATH=../plugins \
    TESTDATA_PATH=$$IN_PWD \
    LD_LIBRARY_PATH=../../input-method-quick:../../src:../../input-context/:../../passthroughserver/:../../maliit:../plugins:$(LD_LIBRARY_PATH) \
    ./$$TARGET

check.depends += $$TARGET

QMAKE_EXTRA_TARGETS += check-xml
check-xml.target = check-xml
check-xml.commands = ../rt.sh $$TARGET
check-xml.depends += $$TARGET

# coverage flags are off per default, but can be turned on via qmake COV_OPTION=on
for(OPTION,$$list($$lower($$COV_OPTION))){
    isEqual(OPTION, on){
        QMAKE_CXXFLAGS += -ftest-coverage -fprofile-arcs
        LIBS += -lgcov
    }
}
QMAKE_CLEAN += $$OBJECTS_DIR/*.gcno $$OBJECTS_DIR/*.gcda
