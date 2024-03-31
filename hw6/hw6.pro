TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        HashTable.cpp \
        PrimeNumberGenerator.cpp \
        Word.cpp \
        WordCounter.cpp \
        main.cpp

HEADERS += \
    HashTable.h \
    PrimeNumberGenerator.h \
    Word.h \
    WordCounter.h
