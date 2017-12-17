//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include "t_biblio_robot.h"

/******************************************************************************
// robot_ajouter_livre
// ****************************************************************************
//
// Cette fonction permet de prendre les retours de l'usager au kiosque et
// d'empiler ces livres dans une pile du robot
//
// Paramètres 	: t_livre livre, t_pile * pile_robot
// Retour 		: void
//*****************************************************************************/

void robot_ajouter_livre(t_livre livre,t_pile * pile_robot){



        empile(pile_robot, livre); //empile les livres
        super_pause();
        robot_placer_livre_chariot(pile_robot); //si le chariot est diponible


}

void robot_placer_livre_chariot(t_pile * pile_robot){

    t_livre temp;
    lien * tete;

    //mettre un indiquateur qui nous permet de savoir si le chariot est la


    temp = desempile(pile_robot); //prend le livre sur le top pour le mettre sur le chariot

    chariot_ajouter_livre(tete,temp); // fonction qui ajoute le livre sur le chariot


}


