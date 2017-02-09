#define __ACTIONS_H_FARAH__
#ifndef __ACTIONS_H_FARAH__

typedef struct actions{
   char[3] jour_heure;
   char[10] nom_action;
   struct suiv * actions;
} actions_t;

//fonctions du actions.c

//fonction qui cree une action (separation jour/heure et dénomination)
void createAction(actions_t *, char *);

//fonction qui alloue de la place et insère un nouvel élément
void alloueAction( actions_t *, int [], char []);

//fonction recherche qui renvoit l'ément précédent à la valeur à insérer ou NULL
actions_t Recherche ( actions_t *, int []);

//fonction de lecture du fichier
int lire_fichier();

//fonction de suppression d'une action en connaissant année, semaine,...

#endif

