#include "actions.h"
#include "semaine.h"
#include "main.c"

#define TAILLE_LISTE_AGENDA 100





/*------------------------------------------------------------------------------*/
/*createAction		Insérer une nouvelle action à la suite de l'agenda	*/
/*										*/
/*En entrée:		liste_actions	Structure de type actions_t		*/
/*			chaine_actions	Chaine de caractères 			*/
/*										*/
/*En sortie:		la fonction retourne une nouvelle liste chainée contenant*/
/*		une nouvelle action si la plage horaire n'est pas déjà occupée	*/
/*------------------------------------------------------------------------------*/

void createAction(actions_t * liste_actions, char * chaine_actions)
{
  int 			i;
  int 			jour_heure[3];
  char 			nom_action[10];
  actions_t 	* 	ptrAction;
  
  for (i=0; i<3; i++)
  {					//on divise la case chaine_actions avec le jour et l'heure d'un côté 
    if (i<3)
    {						//et le nom de l'action de l'autre
      jour_heure[i] = chaine_actions[i];
    }
    else
    {
      nom_action[i-3] = chaine_actions[i];
    }
  }
  
  ptrAction = Recherche( liste_actions, jour_heure);	//ptrAction représente la case précédente avant laquelle 
							//il faut insérer la nouvelle action
  if (* ptrAction != NULL)
  {
    if (jour_heure != prec->suiv->jour_heure)
    {
      alloueAction( ptrAction, jour_heure, nom_action);	//on alloue un nouvel élément
    }
    else
    {
      printf("La plage horaire est deja occupee, vous ne pouvez pas ajouter d'autres elements");    
    }
  }
  else
  {
    alloueAction( ptrAction, jour_heure, nom_action);
  }
  
}





/*------------------------------------------------------------------------------*/
/*alloueAction		Allouer de l'espace mémoire à la suite du pointeur 	*/
/*			Insérer le nouvel élément dans cet espace mémoire	*/
/*										*/
/*En entrée:		ptrAction	Adresse de l'élément précédent		*/
/*			jour		Entier représentant le jour et l'heure	*/
/*			nom		Chaine de caractères représentant le 	*/
/*					nom de l'action				*/
/*										*/
/*En sortie:		la fonction retourne une nouvelle liste chainée contenant*/
/*		un nouvel espace mémoire et une nouvelle action			*/
/*------------------------------------------------------------------------------*/

void alloueAction( actions_t * ptrAction, int [] jour, char [] nom)
{
  actions_t 	*	nouv;
  
  nouv = (actions_t) * malloc(sizeof(actions_t));
  chaine_actions.suiv = * ptrAction;
  ptrAction = chaine_actions;
}





//fonction de recherche 
//renvoit l'adresse de l'élément précédent où il faut insérer la nouvelle valeur
/*------------------------------------------------------------------------------*/
/*Recherche		Rechercher une valeur dans une liste chaînée		*/
/*										*/
/*En entrée:		tete_liste	Structure de type actions_t		*/
/*			val		Entier représentant le jour et l'heure 	*/
/*										*/
/*En sortie:		la fonction retourne l'adresse de l'élément précédent 	*/
/*			où il faut insérer la nouvelle valeur			*/
/*------------------------------------------------------------------------------*/

actions_t Recherche ( actions_t * tete_liste, int [] val)
{
  actions_t ** cour = &tete_liste;
  
  while ( *cour != NULL ) && ( *cour->suiv->jour_heure != val) && ( *cour->suiv->jour_heure < val)
  { //ou strcmp + include "string.h"
    *cour -> suiv;
  }
  return cour;
}






/*------------------------------------------------------------------------------*/
/*lire_fichier		Lire fichier texte représentant notre liste chainée	*/
/*------------------------------------------------------------------------------*/

int lire_fichier()
{
  File* fichier = NULL;
  
  char chaine[19] = "";
  fichier = fopen("liste_agenda", "r");
  
  if (fichier != NULL)
  {
    fgets(chaine, TAILLE_LISTE_AGENDA, fichier)
    createSemaine(chaine);
  }
  else
  {
    printf("Impossible d'ouvrir le fichier 'liste_agenda'");
  }
  
  return 0;
}