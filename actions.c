#include "actions.h"
#include "semaine.h"
#include "main.c"

#define TAILLE_LISTE_AGENDA 100

void createAction(actions_t * liste_actions, char * chaine_actions){
  int i;
  int jour_heure[3];
  char nom_action[10];
  actions_t * ptrAction;
  
  for (i=0; i<3; i++){					//on divise la case chaine_actions avec le jour et l'heure d'un côté 
    if (i<3){						//et le nom de l'action de l'autre
      jour_heure[i] = chaine_actions[i];
    }
    else{
      nom_action[i-3] = chaine_actions[i];
    }
  }
  
  ptrAction = Recherche( liste_actions, jour_heure);	//ptrAction représente la case précédente avant laquelle 
							//il faut insérer la nouvelle action
  if (* ptrAction != NULL){
    if (jour_heure != prec->suiv->jour_heure){
      alloueAction( ptrAction, jour_heure, nom_action);	//on alloue un nouvel élément
    }
    else{
      printf("La plage horaire est deja occupee, vous ne pouvez pas ajouter d'autres elements");    
    }
  }
  else{
    alloueAction( ptrAction, jour_heure, nom_action);
  }
  
}

//fonction qui alloue de la place à la suite du pointeur et qui insère le nouvel élément à la suite
void alloueAction( actions_t * ptrAction, int [] jour, char [] nom){
  actions_t *nouv;
  nouv = (actions_t) * malloc(sizeof(actions_t));
  chaine_actions.suiv = * ptrAction;
  ptrAction = chaine_actions;
}


//fonction de recherche 
//renvoit l'adresse de l'élément précédent où il faut insérer la nouvelle valeur
actions_t Recherche ( actions_t * tete_liste, int [] val){
  actions_t ** cour = &tete_liste;
  
  while ( *cour != NULL ) && ( *cour->suiv->jour_heure != val) && ( *cour->suiv->jour_heure < val){ //ou strcmp + include "string.h"
    *cour -> suiv;
  }
  return cour;
}


//fonction de lecture du fichier
int lire_fichier(){
  File* fichier = NULL;
  
  char chaine[19] = "";
  fichier = fopen("liste_agenda", "r");
  
  if (fichier != NULL){
    fgets(chaine, TAILLE_LISTE_AGENDA, fichier)
    createSemaine(chaine);
  }
  else{
    printf("Impossible d'ouvrir le fichier 'liste_agenda'");
  }
  
  return 0;
}