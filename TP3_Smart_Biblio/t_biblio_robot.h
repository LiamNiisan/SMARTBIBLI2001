#include "t_biblio.h"

#ifndef _T_BIBLIO_ROBOT__
#define _T_BIBLIO_ROBOT__


typedef struct{

    t_livre * top;

}t_pile_robot;







void robot_ajouter_livre(t_livre livre, t_pile_robot * pile);

void robot_placer_livre_chariot();



#endif
