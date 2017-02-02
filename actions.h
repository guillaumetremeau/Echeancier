#define __ACTIONS_H_FARAH__
#ifndef __ACTIONS_H_FARAH__

typedef struct actions{
   char[3] jour_heure;
   char[10] nom_action;
   struct actions * actions;
}

#endif