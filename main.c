/* #######################################################################
 *									main.c
 *
 * Fichier contenant la fonction principal ainsi que les fonctions de test
 *
 * #######################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include "actions.h"
#include "semaine.h"


int main(){/*Décommenter la fonction à tester */

	/* testFonctionLireFichier();*/
	/* testCreateSemaine(); */
	/* testCreateSemaineDoublon(); */
	/* testCreateSemaineMemeJour(); */
	/* testSauvegardeSemaine(); */
	/* testSauvegardeSemaineMauvaisNomFichier(); */
	/* testCreateListeJourFromActionsSemaine(); */
	/* testCreateListeJourFromActionsSemaineSansJours(); */
	/* testSupprimeActionInSemaines(); */
	/* testSupprimeActionInSemainesSansActions(); */

	return 0;
}



/*---------------------------------------------------------------------
 * 					afficheStructure
 *
 * Fonction permettant d'afficher l'état actuel de la structure
 * Permettra de vérifier le résultat d'un jeux de test
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
			ptrAction = ptrAction->suiv;
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
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	structure = lireFichier("liste_agenda"); /* élément récupérant
	la structure après lecture */
	afficheStructure(structure);
}

/* -------------------------------------------------------------------
 * 					testFonctionLireMauvaisNomFichier
 *
 * Fonction qui test la lecture d'un fichier dans le cas d'un mauvais
 * nom de fichier
 * -------------------------------------------------------------------- */
void testFonctionLireMauvaisNomFichier(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	structure = lireFichier("nom_errone"); /* élément récupérant
	la structure après lecture (ici lecture impossible) */
	afficheStructure(structure);
}

/* ------------------------------------------------------------------
 *					testCreateSemaine
 *
 * Fonction qui test la création d'une semaine dans la structure dans
 * le cas normale
 * ------------------------------------------------------------------*/
void testCreateSemaine(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	afficheStructure(structure);
}

/* ------------------------------------------------------------------
 *					testCreateSemaineDoublon
 *
 * Fonction qui test la création d'une semaine dans la structure dans
 * le cas où la plage horaire n'est pas disponible
 * ------------------------------------------------------------------*/
void testCreateSemaineDoublon(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201742413Medecin");
	afficheStructure(structure);
}

/* ------------------------------------------------------------------
 *					testCreateSemaineMemeJour
 *
 * Fonction qui test la création d'une semaine dans la structure dans
 * le cas où il y a déjà une action la même semaine et le même jour
 * ------------------------------------------------------------------*/
void testCreateSemaineMemeJour(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201742416Medecin");
	afficheStructure(structure);
}

/* ---------------------------------------------------------------------
 *					testSauvegardeSemaine
 *
 * Fonction qui test la sauvegarde de la structure dans un fichier
 * ---------------------------------------------------------------------*/
void testSauvegardeSemaine(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Voyage Pau");
	createSemaine(structure, "201742416Restaurant");
	sauvegardeSemaine(structure, "testSauvegarde.txt");
	afficheStructure(structure);
}

/* ---------------------------------------------------------------------
 *					testSauvegardeSemaineMauvaisNomFichier
 *
 * Fonction qui test la sauvegarde de la structure dans un fichier avec
 * un mauvais nom
 * ---------------------------------------------------------------------*/
void testSauvegardeSemaineMauvaisNomFichier(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Voyage Pau");
	createSemaine(structure, "201742416Restaurant");
	sauvegardeSemaine(structure, "nom_errone.txt");
	afficheStructure(structure);
}

/* ----------------------------------------------------------------------
 * 					testCreateListeJourFromActionsSemaine
 *
 * Fonction qui test la création d'une liste de jours suivant une chaine
 * passée en paramètre
 * ---------------------------------------------------------------------*/
void testCreateListeJourFromActionsSemaine(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	/*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Partiels");
	createSemaine(structure, "201742416Restaurant");
	printf("%s\n\n", createListeJourFromActionsSemaine(structure, "Partiels"));
	afficheStructure(structure);
}

/* ----------------------------------------------------------------------
 * 					testCreateListeJourFromActionsSemaineSansJours
 *
 * Fonction qui test la création d'une liste de jours suivant une chaine
 * passée en paramètre dans le cas où il n'y a pas d'action correspondante
 * ---------------------------------------------------------------------*/
void testCreateListeJourFromActionsSemaineSansJours(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	/*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Partiels");
	createSemaine(structure, "201742416Restaurant");
	printf("%s\n\n", createListeJourFromActionsSemaine(structure, "Medecine"));
	afficheStructure(structure);
}

/* ----------------------------------------------------------------------
 * 						testSupprimeActionInSemaines
 *
 * Fonction qui test la supression d'une action à partir de sa date et
 * son heure
 * ----------------------------------------------------------------------*/
void testSupprimeActionInSemaines(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Partiels");
	createSemaine(structure, "201742416Restaurant");
	supprimeActionInSemaines(structure, "201732209");
	afficheStructure(structure);
}

/* ----------------------------------------------------------------------
 * 						testSupprimeActionInSemainesSansActions
 *
 * Fonction qui test la supression d'une action à partir de sa date et
 * son heure dans le cas où il n'y a rien à supprimer
 * ----------------------------------------------------------------------*/
void testSupprimeActionInSemainesSansActions(){
	semaines_t * structure = (semaines_t *) malloc(sizeof(semaines_t));
	 /*Structure de test */
	createSemaine(structure, "201742413Partiels");
	createSemaine(structure, "201732209Partiels");
	createSemaine(structure, "201742416Restaurant");
	supprimeActionInSemaines(structure, "201932210");
	afficheStructure(structure);
}
