paint.out: main.o
	gcc -g -Wall -Werror -Wextra -o paint.out main.o

main.o: main.c
	gcc -g -Wall -Werror -Wextra -c main.c

board.c: board.c board.h
	gcc -Wall -Werror -c board.h

inputHandling.c: inputHandling.c inputHandling.h
	gcc -Wall -Werror -c inputHandling.h

clean: 
	rm -rf *.o *.out