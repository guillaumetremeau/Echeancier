

#include "semaine.h"
#include <stdlib.h>
#include <string.h>

//Procédure qui parcours la liste des semaines et ajoute une semaine (si
//nécessaire) dans l'ordre en fonction de la chaine de caractère complète (ex:
//201720114Medecin) puis ajoute l'action correspondant avec la fonction
//createAction()
void createSemaine(semaines_t semaines, char * chaine){
	char[6] semaine;
	char[13] actions;
	int cmp=0;
	semaines_t semaineTrouvee;
	
	for(cmp=0;cmp<19;cmp++){
		if(cmp < 6){
			semaine[cmp]=chaine[cmp];
		}else action[cmp] = chaine[cmp];
	}
	
	semaineTrouvee = recherche(semaines,semaine);
	if (strcmp(semaineTrouvee.semaineSuivante.semaine, semaine) == 0){
		semaineTrouvee = semaineTrouvee.semaineSuivante;
	}else{//allocation
		
	}
	
	createAction(semaineTrouvee, actions);
}

//Renvoie l'élément précédant soit l'élément correspondant à la bonne semaine
//soit l'emplacement ou inserer un nouvel élément
semaines_t recherche(semaines_t semaines, char * semaine){
	
	semaines_t semaineCourante = semaines;
	cond = strcmp(semaineCourante.semaine, semaine)
	while ((semaineCourant != NULL) and (cond < 0)){
		semaineCourant = semaineCourant.semaineSuivante;
		cond = strcmp(semaineCourante.semaine, semaine)
	}
}
