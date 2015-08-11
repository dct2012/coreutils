all: echo cat

echo :
	gcc -std=c11 ./src/echo.c -o ./bin/echo

cat :
	gcc -std=c11 ./src/cat.c -o ./bin/cat

clean :
	rm ./bin/*
