
all: echeancier

echeancier: semaine.o actions.o main.o
	gcc -o echeancier semaine.o actions.o main.o

semaine.o: semaine.c
	gcc -o semaine.o -c semaine.c -W -Wall -ansi -pedantic
  
actions.o: actions.c
	gcc -o actions.o -c actions.c -W -Wall -ansi -pedantic

main.o: main.c semaine.h action.h
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic

clean:
	rm -rf *.o

mrproper: clean
	rm -rf echeancier
				
