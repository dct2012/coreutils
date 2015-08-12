CFLAGS += -std=c11 -Wall

DEBUG = 0
ifeq (${DEBUG},0)
   CFLAGS  += -Os
else
   CFLAGS  += -g
endif

SRCDIR = src
BINDIR = bin

SRC := $(wildcard $(SRCDIR)/*.c)
BIN := $(SRC:$(SRCDIR)/%.c=$(BINDIR)/%)

all : $(BIN)

$(BINDIR)/% : $(SRCDIR)/%.c
	gcc ${CFLAGS} $< -o $@

clean :
	rm ./bin/*
