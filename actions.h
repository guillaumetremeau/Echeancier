/*------------------------------------------------------------------------------*/
/*	actions.h		fichier contenant la déclaration de la structure*/
/*			de la liste chainée qui les actions et la 		*/
/*			déclaration des fonctions utilisées			*/
/*------------------------------------------------------------------------------*/

#ifndef __ACTIONS_H_GUILLAUME_FARAH__
#define __ACTIONS_H_GUILLAUME_FARAH__

/*#include "semaine.h"
#include "main.c"*/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



typedef struct actions{
   char * jour_heure;
   char * nom_action ;
   struct actions * suiv;
} actions_t;





/*------------------------------------------------------------------------------*/
/*CreateAction		Insérer une nouvelle action à la suite de l'agenda	*/
/*										*/
/*En sortie:		la fonction retourne une nouvelle liste chainée contenant*/
/*		une nouvelle action si la plage horaire n'est pas déjà occupée	*/
/*------------------------------------------------------------------------------*/

void CreateAction(actions_t *, char *);





/*------------------------------------------------------------------------------*/
/*AlloueAction		Allouer de l'espace mémoire à la suite du pointeur 	*/
/*			Insérer le nouvel élément dans cet espace mémoire	*/
/*										*/
/*En sortie:		la fonction retourne une nouvelle liste chainée contenant*/
/*		un nouvel espace mémoire et une nouvelle action			*/
/*------------------------------------------------------------------------------*/

void AlloueAction( actions_t *, char [3], char [10]);





/*------------------------------------------------------------------------------*/
/*Recherche		Rechercher une valeur dans une liste chaînée		*/
/*										*/
/*En sortie:		la fonction retourne l'adresse de l'élément précédent 	*/
/*			où il faut insérer la nouvelle valeur			*/
/*------------------------------------------------------------------------------*/

actions_t ** Recherche ( actions_t *, char [3]);





/*------------------------------------------------------------------------------*/
/*Sauvegarde		fonction qui sauvegarde la SDD sous la forme d'un fichier*/
/*										*/
/*En sortie:		Renvoit un fichier contenant une sauvegarde de la SDD	*/
/*------------------------------------------------------------------------------*/

void Sauvegarde ( FILE *, actions_t *, char *);





/*------------------------------------------------------------------------------*/
/*Sauvegarde		Fonction qui cherche si une action est présente dans 	*/
/*			l'agenda						*/
/*										*/
/*En sortie:		Renvoit, si l'action est présente, les jours qui 	*/
/*		contiennent une ou plusieurs fois cette action sous forme de 	*/
/*		tableau de caractères						*/
/*------------------------------------------------------------------------------*/

char * CreateListeFromActions ( actions_t *, char *);





/*------------------------------------------------------------------------------*/
/*SupprimeAction	Fonction qui supprime une action en connaissant  	*/
/*			la date et l'heure					*/
/*										*/
/*En sortie:		la fonction retourne une nouvelle liste chainée ne 	*/
/*		contenant plus l'action à supprimer si elle existe		*/
/*------------------------------------------------------------------------------*/
void SupprimeAction ( actions_t *, char [3]);





/*------------------------------------------------------------------------------*/
/*LibererAction		Supprimer un élément en libérant de l'espace mémoire	*/
/*										*/
/*En sortie:		la fonction retourne une nouvelle liste chainée contenant*/
/*		une action en moins						*/
/*------------------------------------------------------------------------------*/

void LibererAction ( actions_t *);


#endif
