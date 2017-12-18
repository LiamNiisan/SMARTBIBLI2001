//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#ifndef T_BIBLIO_MACHINE_H_INCLUDED
#define T_BIBLIO_MACHINE_H_INCLUDED

#include "lib.h"

#define CHOIX_MIN 0
#define CHOIX_MAX 5

#define CHOIX_CHARIOT_MAX   2
#define CHOIX_MOTEUR_MAX    4
#define CHOIX_CHARIOT_MENU  3

#define ID_MAX 1000000
#define ID_MIN 1

#define DATE_MIN 2000
#define DATE_MAX 2017
#define ANNEE 2000
#define MAX_LIVRE 5

typedef struct {

    int no_etudiant;
    int date_etude;
    int livres_empreunter;
    t_livre livres[MAX_LIVRE];

}t_etudiant;


/******************************************************************************
// afficher_menu_kiosque
// ****************************************************************************
//
// Cette fonction permet d'afficher le menu kiosque pour que l'utilisateur.
//
//
// Paramètres 	: t_etudiant * etudiant
// Retour 		: int
//*****************************************************************************/
int afficher_menu_kiosque(t_etudiant * etudiant);


/******************************************************************************
// etudiant_servir
// ****************************************************************************
//
// Cette fonction permet d'avoir access au compte de l'etudiant aleatoire et ainsi
// que toutes les demandes d'emprunts et de retours que l'etudiant peut faire
//
// Paramètres 	: t_etudiant * etudiant, t_bibliotheque * bibli, lien * tete, t_pile * pile
// Retour 		: void
//*****************************************************************************/
void etudiant_servir(t_etudiant * etudiant, t_bibliotheque * bibli, lien * tete, t_pile * pile_robot);


/******************************************************************************
// etudiant_apporter_livre
// ****************************************************************************
//
// Cette fonction permet d'envoyer le chariot chercher les choix de l'etudiant
//
// Paramètres 	: t_bibliotheque * biblio, lien * tete, t_etudiant * etudiant
// Retour 		: void
//*****************************************************************************/
void etudiant_apporter_livre(t_bibliotheque * biblio, lien * tete, t_etudiant * etudiant);


/******************************************************************************
// etudiant_retour_livre
// ****************************************************************************
//
// Cette fonction permet de gerer les retour de l'etudiant des livres au kiosque
//
// Paramètres 	: t_bibliotheque * biblio, t_pile * pile_robot, lien * tete, t_etudiant * etudiant
// Retour 		: void
//*****************************************************************************/
void etudiant_retour_livre(t_bibliotheque * biblio, t_pile * pile_robot, lien * tete, t_etudiant * etudiant);


/******************************************************************************
// etudiant_chercher_livre
// ****************************************************************************
//
//  Cette fonction permet a l'etudiant de chercher un livre dans le chariot
//
//
// Paramètres 	: t_bibliotheque * biblio, lien * tete
// Retour 		: void
//*****************************************************************************/
void etudiant_chercher_livre(t_bibliotheque * biblio, lien * tete);

void etudiant_dossier(t_etudiant * etudiant);


/******************************************************************************
// etudiant_random_test
// ****************************************************************************
//
// Cette fonction est un generateur d'etudiant qui nous permet de de generer
// un etudiant avec un dossier aleatoire : ID et date d'inscription
//
// Paramètres 	: t_etudiant * etudiant
// Retour 		: void
//*****************************************************************************/
void etudiant_random_test(t_etudiant * etudiant);

/******************************************************************************
// afficher_livres_chariot
// ****************************************************************************
//
// Cette fonction permet d'afficher les livres sur le chariot
//
// Paramètres 	: t_bibliotheque * biblio, lien * tete
// Retour 		: void
//*****************************************************************************/
void afficher_livres_chariot(t_bibliotheque * biblio, lien * tete);


/******************************************************************************
// afficher_menu_recherche
// ****************************************************************************
//
// Cette fonction permet de chercher un livre sur le chariot ou dans la biblio
// avec le moteur de recherche avec les shortkeys
//
// Paramètres 	:
// Retour 		: int
//*****************************************************************************/
int afficher_menu_recherche();


/******************************************************************************
// rechercher_livre
// ****************************************************************************
//
//  Cette fonction permet la recherche dans le moteur de recherche
//
// Paramètres 	: t_bibliotheque * biblio, lien * tete
// Retour 		: void
//*****************************************************************************/
void rechercher_livre(t_bibliotheque * biblio, lien * tete);


/******************************************************************************
// afficher_menu_moteur_recherche
// ****************************************************************************
//
// Cette fonction permet d'avoir acces a un autre menu a l'interieur du moteur
// de recherche. On peut y trouver la recherche par ISBN,Auteur,Genre et titre
//
// Paramètres 	:
// Retour 		: int
//*****************************************************************************/
int afficher_menu_moteur_recherche();


/******************************************************************************
// moteur_recherche
// ****************************************************************************
//
// Cette fonction represente le coeur du moteur de recherche
//
// Paramètres 	: t_bibliotheque * biblio, int option, lien * tete
// Retour 		: void
//*****************************************************************************/
void moteur_recherche(t_bibliotheque * biblio, int option, lien * tete);


/******************************************************************************
// etudiant_chariot_menu
// ****************************************************************************
//
// Gere l'acces de l'etudiant au chariot, il permet aussi d'emprunter des livres
// a partir de celui-ci.
//
// Paramètres 	: t_etudiant * etudiant, t_bibliotheque * biblio, lien * tete
// Retour 		: void
//*****************************************************************************/
void etudiant_chariot_menu(t_etudiant * etudiant, t_bibliotheque * biblio, lien * tete);


/******************************************************************************
// afficher_chariot_menu
// ****************************************************************************
//
// Affiche le menu chariot de l'etudiant.
//
// Paramètres 	: void
// Retour 		: int
//*****************************************************************************/
int afficher_chariot_menu();


/******************************************************************************
// etudiant_emprunter_livre_chariot
// ****************************************************************************
//
// Permet de voir les livres sur le chariot et de les emprunter.
//
// Paramètres 	: t_etudiant * etudiant, t_bibliotheque * biblio, lien * tete
// Retour 		: void
//*****************************************************************************/
void etudiant_emprunter_livre_chariot(t_etudiant * etudiant, t_bibliotheque * biblio, lien * tete);



#endif
