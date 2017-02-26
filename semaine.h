#define __SEMAINE_H_GUILLAUME__
#ifndef __SEMAINE_H_GUILLAUME__

typedef struct semaines {
	char * semaine;
	struct actions * actions;
	struct semaines * semaineSuivante;
}semaines_t;

#define MAXLISTE 19


/*Fonction qui créer une semaine à partir d'une chaine de caractère récupérer
d'un fichier*/
void createSemaine(semaines_t *, char *);

void alloueSemaine(semaines_t *, char[]);

semaines_t * lireFichier(char *);

/*Fonction qui recherche  un élément dans la sdd*/
semaines_t * recherche(semaines_t *, char *);

/*Fonction qui enregistre la sdd dans un fichier*/
void sauvegardeSemaine(semaines_t *, char *);

/*Fonction qui créer la liste des jours contenant une action donnée*/
char * createListeJourFromActionsSemaine(semaines_t *, char *);

/*Supprime une action de la sdd à partir de l'année, la semaine, le jour
ainsi que l'heure*/
void supprimeActionInSemaines(semaines_t *, char *);

#endif
