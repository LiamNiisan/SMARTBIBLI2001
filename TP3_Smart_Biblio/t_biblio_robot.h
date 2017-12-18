//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include "lib.h"

#ifndef T_BIBLIO_ROBOT_H_INCLUDED
#define T_BIBLIO_ROBOT_H_INCLUDED


/******************************************************************************
// robot_ajouter_livre
// ****************************************************************************
//
// Cette fonction permet de prendre les retours de l'usager au kiosque et
// d'empiler ces livres dans une pile du robot
//
// Paramètres 	: t_livre livre, t_pile * pile_robot, lien * tete
// Retour 		: void
//*****************************************************************************/
void robot_ajouter_livre(t_livre livre, t_pile * pile_robot, lien * tete);


/******************************************************************************
// robot_placer_livre_chariot
// ****************************************************************************
//
// Cette fonction permet de prendre les livres du robot et les mettre sur le chariot
//
// Paramètres 	: t_livre livre, t_pile * pile_robot, lien * tete
// Retour 		: void
//*****************************************************************************/
void robot_placer_livre_chariot(t_pile * pile_robot, lien * tete);



#endif
