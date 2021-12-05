paint.out: main.o
	gcc -g -Wall -Werror -Wextra -o paint.out main.o

main.o: main.c
	gcc -g -Wall -Werror -Wextra -c main.c

clean: 
	rm -rf *.o *.out