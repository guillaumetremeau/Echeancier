/* #####################################################################
 *								semaine.h
 *
 *
 * Fichier contenant les déclarations relatives à la gestion de la liste des
 * semaines
 *
 * #####################################################################*/


#ifndef __SEMAINE_H_GUILLAUME_FARAH__
#define __SEMAINE_H_GUILLAUME_FARAH__

#include "actions.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


typedef struct semaines {
	char * semaine;
	struct actions * actions;
	struct semaines * semaineSuivante;
}semaines_t;

#define MAXLISTE 19


/*----------------------------------------------------------------------------
 *						createSemaine
 *
 * 		Procédure qui parcours la liste des semaines et ajoute une semaine (si
 * nécessaire) dans l'ordre en fonction de la chaine de caractère complète (ex:
 * 201720114Medecin) puis ajoute l'action correspondant avec la fonction
 * createAction()
 *
 * Entrées
 * 		semaines : pointeur de la liste des semaines
 * 		chaine : chaine de caractère correspondant aux informations d'une action
 * ---------------------------------------------------------------------------*/
void createSemaine(semaines_t *, char *);

/*---------------------------------------------------------------------------
 * 					alloueSemaine
 *
 * 		Fonction qui alloue un élément semaine sur le poiteur passé en paramètre et
 * ajoute le champ semaine
 *
 * Entrées
 * 		ptrSemaine : Pointeur de semaine sur lequel il faut faire l'allocation
 * 		nomSemaine : Nom de la semaine à allouer
 * --------------------------------------------------------------------------*/
void alloueSemaine(semaines_t *, char[]);

/*--------------------------------------------------------------------------
 * 				lireFichier
 *
 * 		Fonction qui lit un fichier donné en paramètre et créer les semaines
 * correspondantes
 *
 * Entrée
 * 		nomFichier : nom du fichier à lire
 *
 * Sortie
 * 		retourne le pointeur de la liste des semaines crée
 * ------------------------------------------------------------------------*/
semaines_t * lireFichier(char *);

/*-----------------------------------------------------------------------------
 *					recherche
 *
 * 		Permet de parcourir la liste des semaines et de trouver la semaine
 * 	correspondante à l'élément recherché
 *
 * Entrées
 * 	semaines : pointeur de la liste des semaines à parcourir
 *	semaine : chaine de caractère correspondant à la semaine à trouver
 *
 * Sortie
 * 	Pointeur de pointeur de l'élément trouvé(peut-être pointeur sur un élément
 * 	NIL
 * ---------------------------------------------------------------------------*/
semaines_t ** recherche(semaines_t *, char *);

/*----------------------------------------------------------------------
 *				sauvegardeSemaine
 *
 *		Fonction qui permet de sauvegarder la structure en parcourant toutes
 *	les semaines et appelant la fonction de sauvegarde sur la liste des
 *	actions
 *
 *	Entrées
 *		listeSemaine : pointeur sur la liste des semaines à sauvegarder
 *		nomFichier : nom du fichier où sauvegarder
 * --------------------------------------------------------------------*/
void sauvegardeSemaine(semaines_t *, char *);

/*--------------------------------------------------------------------------
 *					createListeJourFromActionSemaine
 *
 * 	Fonction qui créer la liste des jours contenant une action donnée en
 * 	parcourant la liste des semaines
 *
 *	Entrées
 *		listeSemaine : pointeur de la liste des semaines à parcourir
 *		action : chaine de caractère à rechercher
 *
 *	Sortie
 *		Chaine de caractère correspondant à la liste des jours résultants
 * -------------------------------------------------------------------------*/
char * createListeJourFromActionsSemaine(semaines_t *, char *);

/*--------------------------------------------------------------------------
 *					supprimeActionInSemaines
 *
 *		Supprime une action de la sdd à partir de l'année, la semaine, le jour
 *	ainsi que l'heure en recherchant la semaine correspondante et appelant la
 *	fonction de suppression sur une liste d'action
 *
 *	Entrées
 *		listeSemaine : pointeur de la liste des semaines à parcourir
 *		chaine : chaine contenant toutes les informations pour supprimer l'élément
 *	-----------------------------------------------------------------------*/
void supprimeActionInSemaines(semaines_t *, char *);

#endif
