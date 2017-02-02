#define "actions.h"
#define "semaine.h"
#define "main.c"

#define TAILLE_LISTE_AGENDA 100

void createAction(actions_t, char * chaine_actions){
  int i;
  int j;
  int jour_heure[3];
  char nom_action[10];
  
  for (i=0; i<3; i++){
    jour_heure[i] = chaine_actions[i];
  }
  
  for (i=3; i<13; i++){
    for (j=0; i<10; i++){
      nom_action[j] = chaine_actions[i];
    }
  }
  
  
}


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