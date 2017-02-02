

#define "semaine.h"
#define <stdlib.h>

//Procédure qui parcours la liste des semaines et ajoute une semaine (si
//nécessaire) dans l'ordre en fonction de la chaine de caractère complète (ex:
//201720114Medecin) puis ajoute l'action correspondant avec la fonction
//createAction()
void createSemaine(semaines_t semaines, char * chaine){
	int[6] semaine;
	char[13] actions;
	int cmp=0;
	}while(chaine[cmp] != '\0');
	for(cmp=0;cmp<19;cmp++){
		if(cmp < 6){
			semaine[cmp]=chaine[cmp];
		}else action[cmp] = chaine[cmp];
	}



	

	createAction(ptrsemaine, actions);
}
