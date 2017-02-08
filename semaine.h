#define __SEMAINE_H_GUILLAUME___
#ifndef __SEMAINE_H_GUILLAUME__

typedef struct semaines{
	int[6] semaine;
	struct actions * actions;
	struct semaine * semaine;
}semaines_t;

//Fonction qui créer une semaine à partir d'une chaine de caractère récupérer
//d'un fichier
void createSemaine(semaines_t, char *);
#endif
