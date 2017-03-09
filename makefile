
all: echeancier

echeancier: semaine.o actions.o main.o
	gcc -o echeancier semaine.o actions.o main.o

actions.o: actions.c
	gcc -o actions.o -c actions.c -Wall -Wextra -ansi -pedantic

semaine.o: semaine.c
	gcc -o semaine.o -c semaine.c -Wall -Wextra -ansi -pedantic
  
main.o: main.c semaine.h actions.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf echeancier
				
