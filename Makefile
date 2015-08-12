CFLAGS += -std=c11 -Wall

DEBUG = 0
ifeq (${DEBUG},0)
   CFLAGS  += -Os
else
   CFLAGS  += -g
endif

all: cat echo false printf pwd sleep true yes

cat :
	gcc ${CFLAGS} ./src/cat.c -o ./bin/cat

echo :
	gcc ${CFLAGS} ./src/echo.c -o ./bin/echo

false :
	gcc ${CFLAGS} ./src/false.c -o ./bin/false

printf :
	gcc ${CFLAGS} ./src/printf.c -o ./bin/printf

pwd :
	gcc ${CFLAGS} ./src/pwd.c -o ./bin/pwd

sleep :
	gcc ${CFLAGS} ./src/sleep.c -o ./bin/sleep

true :
	gcc ${CFLAGS} ./src/true.c -o ./bin/true

yes :
	gcc ${CFLAGS} ./src/yes.c -o ./bin/yes

clean :
	rm ./bin/*
