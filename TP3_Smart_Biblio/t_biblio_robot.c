#include "t_biblio_robot.h"
#include "t_pile.h"



void robot_ajouter_livre(t_livre livre,t_pile * pile_robot){


        //printf("Vous avez retourne au robot le livre de ISBN : %d\n",livre.isbn);

        empile(pile_robot, livre);
        super_pause();
}

void robot_placer_livre_chariot(){







}


