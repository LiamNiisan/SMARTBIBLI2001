//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi (JAIB06029608) & Felix-Olivier Moreau (MORF30059700)
//Pour le cours ING145

#include "lib.h"


#ifndef T_BIBLIO_CHARIOT_H_INCLUDED
#define T_BIBLIO_CHARIOT_H_INCLUDED

#define POS_KIOSK 0
#define POS_DEPLACEMENT 1

#define VITESSE_CHARIOT_DEFAUT 1

#define FICHIER_CONFIG_CHARIOT  "chariot_config.txt"

#define DATA  100

#define MILISECONDES    1000


/******************************************************************************
// chariot_ajouter_livre
// ****************************************************************************
//
// Cette fonction permet d'ajouter un livre sur la pile de livre du chariot
//
// Paramètres 	: lien * tete, t_livre livre
// Retour 		: int
//*****************************************************************************/
int chariot_ajouter_livre(lien * tete, t_livre livre);


/******************************************************************************
// chariot_retirer_livre
// ****************************************************************************
//
// Cette fonction permet de retirer un livre qui se trouve dans le chariot
//
// Paramètres 	: lien * tete, int ISBN, t_bibliotheque * pBibli
// Retour 		: t_livre
//*****************************************************************************/
t_livre chariot_retirer_livre(lien * tete, int ISBN, t_bibliotheque * pBibli);


/******************************************************************************
// chariot_emprunter_livre
// ****************************************************************************
//
// permet de prendre le livre de la bibliotheque avec le ISBN.
//
// Paramètres 	: int ISBN, t_bibliotheque * pBibli
// Retour 		: void
//*****************************************************************************/
void chariot_emprunter_livre(int ISBN, t_bibliotheque * pBibli);


/******************************************************************************
// chariot_retourner_livres
// ****************************************************************************
//
// Cette fonction permet de retourner les livres du chariot a la bibliotheque
//
// Paramètres 	: lien * tete, t_bibliotheque * pBibli
// Retour 		: void
//*****************************************************************************/
void chariot_retourner_livres(lien * tete, t_bibliotheque * pBibli);


/******************************************************************************
// chariot_apporter_livre
// ****************************************************************************
//
// Cette fonction permet au chariot d'aller chercher un livre dans la biblio.
// Verifie si le livre exite et s'il est disponible a l'emprunt.
//
// Paramètres 	: int ISBN, t_bibliotheque * pBibli, lien * tete
// Retour 		: t_livre
//*****************************************************************************/
t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, lien * tete);


/******************************************************************************
// chariot_set_vitesse
// ****************************************************************************
//
// Cette fonction permet de changer la vitesse d'execution du chariot. Cette
// influencera le temps de ceuillette a la bibliotheque
//
// Paramètres 	: int vitesse
// Retour 		: void
//*****************************************************************************/
void chariot_set_vitesse(int vitesse);

/******************************************************************************
// chariot_get_vitesse
// ****************************************************************************
//
// Cette fonction permet de savoir la vitesse d'execution du chariot
//
// Paramètres 	: void
// Retour 		: Int
//*****************************************************************************/
int chariot_get_vitesse();


/******************************************************************************
// chariot_get_vitesse
// ****************************************************************************
//
// Cette fonction permet de savoir la position du chariot
//
// Paramètres 	: void
// Retour 		: void
//*****************************************************************************/
int chariot_get_pos();

#endif

