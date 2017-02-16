/*------------------------------------------------------------------------------*/
/*	actions.h		fichier contenant la déclaration de la structure*/
/*			de la liste chainée contenant les actions et la 	*/
/*			déclaration des fonctions utilisées			*/
/*------------------------------------------------------------------------------*/

#define __ACTIONS_H_FARAH__
#ifndef __ACTIONS_H_FARAH__

typedef struct actions{
   char[3] jour_heure;
   char[10] nom_action;
   struct suiv * actions;
} actions_t;


/*déclaration des fonctions utilisées*/

void createAction(actions_t *, char *);

void alloueAction( actions_t *, int [], char []);

actions_t Recherche ( actions_t *, int []);

int lire_fichier();

/*fonction de sauvegarde du fichier en sdd qui prend en paramètre un fichier*/
/*et la chiane de caracteres representant la semaine*/
void sauvegarde ( file, actions_t *, char *);

/*liste contigue des jours comprenant l'action "char"*/
/*renvoit jour où une action est présente*/
char * createListefromActions ( actions_t *, char *);

/*supprimer une action en fonction de different parametre*/
void supprimeAction(actions_t *, int []);


#endif

