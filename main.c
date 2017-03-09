/* #######################################################################
 *									main.c
 *
 * Fichier contenant la fonction principal ainsi que les fonctions de test
 *
 * #######################################################################*/

#include "actions.h"
#include "semaine.h"


int main(){

	return 0;
}



/*---------------------------------------------------------------------
 * 					afficheStructure
 *
 * Fonction permettant d'afficher l'état actuel de la structure
 *
 * Entrée
 * 		semaines : structure à afficher
 * ------------------------------------------------------------------*/
void afficheStructure(semaines_t * semaines){
	semaines_t	* ptrSemaine = semaines;  /* variable de parcours de la liste des semaines*/
	actions_t 	* ptrAction; 							/* variable de parcours des listes d'actions */
	while(ptrSemaine != NULL){
		printf("%s :\n", ptrSemaine->semaine );
		ptrAction = ptrSemaine->actions;
		while(ptrAction != NULL){
			printf("    %s %s\n", ptrAction->jour_heure, ptrAction->nom_action);
			ptrAction = ptrAction->actions;
		}
		ptrSemaine = ptrSemaine->semaineSuivante;
	}
}

/* -------------------------------------------------------------------
 * 					testFonctionLireFichier
 *
 * Fonction qui test la lecture d'un fichier dans le cas normale
 * -------------------------------------------------------------------- */
void testFonctionLireFichier(){
	semaines_t * structure = lireFichier("liste_agenda");
	afficheStructure(structure);
}

/* -------------------------------------------------------------------
 * 					testFonctionLireMauvaisNomFichier
 *
 * Fonction qui test la lecture d'un fichier dans le cas d'un mauvais
 * nom de fichier
 * -------------------------------------------------------------------- */
void testFonctionLireFichier(){
	semaines_t * structure = lireFichier("nom_erroné");
}

void testCreateSemaine(){
	semaines_t * structure;
	createSemaine(structure, "201742413Partiels");
	afficheStructure(structure);
}

void testSauvegardeSemaine(){
	semaines_t * structure;
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Voyage Pau");
	createSemaine(structure, "201742413Restaurant");
	sauvegardeSemaine(structure, "testSauvegarde.txt");
	afficheStructure(structure);
}

void testCreateListeJourFromActionsSemaine(){
	semaines_t * structure;
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Partiels");
	createSemaine(structure, "201742413Restaurant");
	createListeJourFromActionsSemaine(structure, "Partiels");
	afficheStructure(structure);
}

void testSupprimeActionInSemaines(){
	semaines_t * structure;
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Partiels");
	createSemaine(structure, "201742413Restaurant");
	supprimeActionInSemaines(structure, "201732209");
	afficheStructure(structure);
}
