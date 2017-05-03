CFLAGS += -std=c11 -Wall
CPPFLAGS += -std=c++11 -Wall

DEBUG = 0
ifeq (${DEBUG},0)
   CFLAGS  += -Os
   CPPFLAGS += -Os
else
   CFLAGS  += -g
   CPPFLAGS += -g
endif

SRCDIR = src
BUILDDIR = build
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.cpp)
BIN := $(SRC:$(SRCDIR)/%.cpp=$(BINDIR)/%)

INC := -I include

all : $(BIN)

build/%.o : lib/File/%.cpp
	g++ ${CPPFLAGS} $(INC) -c $< -o $@

bin/cp : build/FileOperations.o build/FileReader.o build/FileCreator.o
	g++ ${CPPFLAGS} $(INC) -c src/cp.cpp -o build/cp.o
	g++ ${CPPFLAGS} -o bin/cp build/cp.o build/FileOperations.o build/FileReader.o build/FileCreator.o

bin/echo : build/FileOperations.o build/FileReader.o build/FileCreator.o
	g++ ${CPPFLAGS} $(INC) -c src/echo.cpp -o build/echo.o
	g++ ${CPPFLAGS} -o bin/echo build/echo.o build/FileOperations.o build/FileReader.o build/FileCreator.o

clean :
	rm bin/*
	rm build/*

.PHONY: cp echo
