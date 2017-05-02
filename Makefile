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
LIBDIR = lib
BUILDDIR = build
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.cpp)
BIN := $(SRC:$(SRCDIR)/%.cpp=$(BINDIR)/%)

LIBS := $(shell find $(LIBDIR) -type f -name *.cpp)
LIBOBJ := $(patsubst $(LIBDIR)/%,$(BUILDDIR)/%,$(LIBS:.cpp=.o))

INC := -I include

build/%.o : lib/File/%.cpp
	g++ ${CPPFLAGS} $(INC) -c $< -o $@

cp : build/FileReader.o build/FileCreator.o
	g++ ${CPPFLAGS} $(INC) -c src/cp.cpp -o build/cp.o
	g++ ${CPPFLAGS} -o bin/cp build/cp.o build/FileReader.o build/FileCreator.o

all : $(cp) $(LIBOBJ)

# $(BINDIR)/% : $(SRCDIR)/%.cpp
# 	g++ ${CPPFLAGS} $< -o $@

clean :
	rm bin/*
	rm build/*

.PHONY: all LIBOBJ cp
