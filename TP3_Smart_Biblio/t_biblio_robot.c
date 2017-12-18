//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include "t_biblio_robot.h"


void robot_ajouter_livre(t_livre livre,t_pile * pile_robot, lien * tete){



        empile(pile_robot, livre); //empile les livres

        //mettre un indiquateur qui nous permet de savoir si le chariot est la
        while(chariot_get_pos());

        robot_placer_livre_chariot(pile_robot, tete); //si le chariot est diponible


}

void robot_placer_livre_chariot(t_pile * pile_robot, lien * tete){

    t_livre temp;

    temp = desempile(pile_robot); //prend le livre sur le top pour le mettre sur le chariot

    chariot_ajouter_livre(tete,temp); // fonction qui ajoute le livre sur le chariot

}


