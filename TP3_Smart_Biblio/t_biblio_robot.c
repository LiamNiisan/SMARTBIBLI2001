#include "t_biblio_robot.h"



void robot_ajouter_livre(t_livre livre,t_pile * pile_robot){


        empile(pile_robot, livre);
        super_pause();
}

void robot_placer_livre_chariot(t_pile * pile_robot){


    //mettre un indiquateur qui nous permet de savoir si le chariot est la

    desempile(pile_robot);

    //mettre une pile pour le chariot pour empiler


}


