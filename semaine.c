#define __SEMAINE_C_GUILLAUME__
#ifndef __SEMAINE_C_GUILLAUME__

#include "semaine.h"
#include "actions.h"
#include <stdlib.h>
#include <string.h>

/*Procédure qui parcours la liste des semaines et ajoute une semaine (si
nécessaire) dans l'ordre en fonction de la chaine de caractère complète (ex:
201720114Medecin) puis ajoute l'action correspondant avec la fonction
createAction()*/
void createSemaine(semaines_t * semaines, char * chaine){
	char semaine[6];
	char actions[13];
	int cmp=0;
	semaines_t * ptrSemaine;

	for(cmp=0;cmp<19;cmp++){/*Separation de la chaine de caractère*/
		if(cmp < 6){
			semaine[cmp]=chaine[cmp];
		}else actions[cmp-6] = chaine[cmp];
	}

	ptrSemaine = recherche(semaines,semaine);
	if ( ptrSemaine != NULL ){
		if (strcmp(ptrSemaine->semaine, semaine) != 0){
			alloueSemaine(ptrSemaine, semaine);
		}
	}else{
			alloueSemaine(ptrSemaine, semaine);
	}

	createAction(ptrSemaine->actions, actions);
}

/*Fonction qui alloue un élément semaine sur le poiteur passé en paramètre et
ajoute le champ semaine*/
void alloueSemaine(semaines_t * ptrSemaine, char * nomSemaine){
	semaines_t * nouvSemaine = (semaines_t *) malloc(sizeof(semaines_t));
	nouvSemaine->semaine = nomSemaine;
	nouvSemaine->semaineSuivante = ptrSemaine;
	ptrSemaine = nouvSemaine;
}

/*Renvoie le pointeur sur  soit l'élément correspondant à la bonne semaine
soit l'emplacement ou inserer un nouvel élément*/
semaines_t * recherche(semaines_t * semaines, char * semaine){
	semaines_t ** ptrCour = &semaines;
	while ((*ptrCour != NULL) && (strcmp((*ptrCour)->semaine,semaine)<0)){
		ptrCour = (*ptrCour)->semaineSuivante;
	}
	return *ptrCour;
}

/*Fonction qui lit un fichier donné en paramètre et créer les semaines
correspondantes*/
semaines_t * lireFichier(char * nomFichier){
	semaines_t * listeSemaine = NULL;
	FILE* file = NULL;
	char chaine[MAXLISTE] = "";

	file = fopen(nomfichier, "r");

	if (file != NULL){
		while(fgets(chaine, MAXLISTE,file) != NULL){
			createSemaine(listeSemaine,chaine);
		}
		fclose(file);
	}
	return listeSemaine;
}

void sauvegardeSemaine(semaines_t * listeSemaine, char * nomFichier){
	FILE* file = NULL;
	semaines_t * ptrCour = listeSemaine;
	file = fopen(nomfichier, "r");
	if (file != NULL){
		while (ptrCour != NULL){
			sauvegarde(file, ptrCour->actions, ptrCour->semaine);
			ptrCour = ptrCour->semaineSuivante;
		}
		fclose(file);
	}
}

#endif
