all: cat echo false true yes

cat :
	gcc -std=c11 ./src/cat.c -o ./bin/cat

echo :
	gcc -std=c11 ./src/echo.c -o ./bin/echo

false :
	gcc -std=c11 ./src/false.c -o ./bin/false

true :
	gcc -std=c11 ./src/true.c -o ./bin/true

yes :
	gcc -std=c11 ./src/yes.c -o ./bin/yes

clean :
	rm ./bin/*
