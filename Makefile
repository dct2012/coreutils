CFLAGS += -std=c11 -Wall
CPPFLAGS += -std=c++11 -Wall

DEBUG = 1
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

build/%.o : lib/%.cpp
	g++ ${CPPFLAGS} $(INC) -c $< -o $@

build/%.o : lib/File/%.cpp
	g++ ${CPPFLAGS} $(INC) -c $< -o $@

build/%.o : lib/Argument/%.cpp
	g++ ${CPPFLAGS} $(INC) -c $< -o $@

bin/cp : build/FileOperations.o build/TextOperations.o build/FileReader.o build/FileCreator.o build/FileStat.o
	g++ ${CPPFLAGS} $(INC) -c src/cp.cpp -o build/cp.o
	g++ ${CPPFLAGS} -o bin/cp build/cp.o build/FileOperations.o build/TextOperations.o build/FileReader.o build/FileCreator.o build/FileStat.o

bin/cat : build/FileOperations.o build/TextOperations.o build/FileReader.o build/FileCreator.o build/FileStat.o
	g++ ${CPPFLAGS} $(INC) -c src/cat.cpp -o build/cat.o
	g++ ${CPPFLAGS} -o bin/cat build/cat.o build/FileOperations.o build/TextOperations.o build/FileReader.o build/FileCreator.o build/FileStat.o

bin/date :
	g++ ${CPPFLAGS} -o bin/date src/date.cpp

bin/echo : build/TextOperations.o
	g++ ${CPPFLAGS} $(INC) -c src/echo.cpp -o build/echo.o
	g++ ${CPPFLAGS} -o bin/echo build/echo.o build/TextOperations.o

bin/false :
	g++ ${CPPFLAGS} -o bin/false src/false.cpp

bin/mkdir : build/ArgumentCollection.o build/HelpMessage.o build/FileOperations.o build/TextOperations.o build/FileReader.o build/FileCreator.o build/FileStat.o build/Command.o
	g++ ${CPPFLAGS} $(INC) -c src/mkdir.cpp -o build/mkdir.o
	g++ ${CPPFLAGS} -o bin/mkdir build/mkdir.o build/ArgumentCollection.o build/HelpMessage.o build/FileOperations.o build/TextOperations.o build/FileReader.o build/FileCreator.o build/FileStat.o build/Command.o

bin/true :
	g++ ${CPPFLAGS} -o bin/true src/true.cpp

bin/yes :
	g++ ${CPPFLAGS} -o bin/yes src/yes.cpp

clean :
	rm bin/*
	rm build/*

.PHONY: cp echo
