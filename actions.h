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


//déclaration des fonctions utilisées

void createAction(actions_t *, char *);

void alloueAction( actions_t *, int [], char []);

actions_t Recherche ( actions_t *, int []);

int lire_fichier();


#endif

