#include "lib.h"

#ifndef T_BIBLIO_H_INCLUDED
#define T_BIBLIO_H_INCLUDED

#define NB_LIVRES_MAX_RANGEE        100
#define NB_GENRES                   6
#define BIBLIO_FICHIER				"biblio.txt"

#define FICHIERBIBLIO               "biblio.txt"


#define TAILLE_TITRE	80
#define TAILLE_NOM		30
#define TAILLE_PRENOM	30


#define MAX_ISBN		9999

#define SIMULATION      1

#define EMPRUNT         1
#define DISPONIBLE      0

#define LIVRE_INTROUVABLE         0
#define LIVRE_NON_DISPONIBLE      1
#define LIVRE_EMPRUNTE            2
#define LIVRE_REMIS               1


#define RECHERCHE_ISBN    0
#define RECHERCHE_AUTEUR  1
#define RECHERCHE_TITRE   2
#define RECHERCHE_GENRE   3

#define PARAMETRES_RECHERCHE 4

//typedef enum { AUCUN = 0, FICTION = 1, HISTOIRE = 2, SCIENCE = 3, ENFANTS = 4, INFORMATIQUE = 5 } t_genre;

typedef struct
{
	int nb_livres_dispo;
	int nb_livres_emprunt;
} t_rapport;



/*typedef struct
{
	t_genre genre;
	int nb_pages;
	char auteur_prenom[TAILLE_PRENOM];
	char auteur_nom[TAILLE_NOM];
	char titre[TAILLE_TITRE];
	int isbn;
	int bEmprunte; // 1: Le livre a ete emprunte, 0: le livre est disponible.
} t_livre;*/



typedef struct
{
	t_livre livres[NB_GENRES][NB_LIVRES_MAX_RANGEE];
	int nb_livres[NB_GENRES];
	//t_pile retours;
	t_rapport rapport;
} t_bibliotheque;


/******************************************************************************
//demander_choix_menu
// ****************************************************************************
//
// Fonction qui permet a l'utilisateur de choisir une option dans le menu
// integration d'une limite si les choix sont hors demande
// Retour 		: Void.
//*****************************************************************************/
int demander_choix_menu();


/******************************************************************************
//Initialiser_bibliotheque
// ****************************************************************************
//
//Permet de mettre a 0 tous les livres de tous les genres
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void initialiser_bibliotheque(t_bibliotheque * pBibli);


/******************************************************************************
//initialiser rapport d'emprunt et de disponibilite
// ****************************************************************************
//
// La fonction permet de lire le fichier biblio.txt qui se trouve dans le
// dossier du programme.Ensuite, il est enregistrer dans un tableau bibli.
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void initialiser_rapport(t_bibliotheque * pBibli);


/******************************************************************************
//Sauvegarder_fichier
// ****************************************************************************
//
// permet de prendre les modifications du tableau de bibli et de les sauvegarder
// dans le fichier de biblio.txt
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void sauvegarder_fichier(t_bibliotheque * pBibli);


/******************************************************************************
//Lire_Fichier
// ****************************************************************************
//
// La fonction permet de lire le fichier biblio.txt qui se trouve dans le
// dossier du programme.Ensuite, il est enregistrer dans un tableau bibli.
// Paramètres 	: t_bibliotheque * pBibli, int * lecture.
// Retour 		: Void.
//*****************************************************************************/
void lire_fichier(t_bibliotheque * pBibli, int * lecture);

void simuler_lire_fichier(t_bibliotheque * pBibli);


/******************************************************************************
//Trier_livres
// ****************************************************************************
//
// Cette fonction est pour le Bonus. Il permet de trier les livre en ordre
// croissant.
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void trier_livres(t_bibliotheque * pBibli);


/******************************************************************************
//afficher_bibliotheque
// ****************************************************************************
//
//Fonction avec des boucles afin d'afficher a l'utilisateur tous les livres.
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void afficher_bibliotheque(t_bibliotheque * pBibli);


/******************************************************************************
//Generer rapport
// ****************************************************************************
//
// Cette fonction permet d'afficher le rapport avec les informations que nous
// avons enregistrer dans la biblio
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void generer_rapport(t_bibliotheque * pBibli);


/******************************************************************************
//emprunter_livre
// ****************************************************************************
//
// Fonction qui permet de gerer l'emprunt des livres
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void emprunter_livre(t_bibliotheque * pBibli);


/******************************************************************************
//gerer_retours
// ****************************************************************************
//
// Permet de remettre le rapport d'emprunt a 0
// Permet de remettre disponible les livres de la bibliotheque
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void gerer_retours(t_bibliotheque * pBibli);


/******************************************************************************
//retirer_livre
// ****************************************************************************
//
// Cette fonction permet de retirer un livre de la bibliotheque
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void retirer_livre(t_bibliotheque * pBibli);


/******************************************************************************
//modifier_livre
// ****************************************************************************
//
//Cette fonction permet de choisir un livre par son ISBN et de modifier son contenue
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: Void.
//*****************************************************************************/
void modifier_livre(t_bibliotheque * pBibli);


/******************************************************************************
//retirer_sautligne
// ****************************************************************************
//
// Permet de garder une chaine de caracteres en une seule ligne
//*****************************************************************************/
void retirer_sautligne(char * chaine);


/******************************************************************************
//Super_Pause
// ****************************************************************************
//
// Permet d'avoir un option "Touch Key for Continued"
//*****************************************************************************/
void super_pause();


/******************************************************************************
//verifier_disp_bibliotheque
// ****************************************************************************
//
// Cette fonction est tres utiliser dans plusieurs des fonctions. Permet de verifier
// si la le fichier biblio.txt a ete lu dans l'option 2 de choix menu
//
// Paramètres 	: t_bibliotheque * pBibli.
// Retour 		: int.
//*****************************************************************************/
int verifier_disp_bibliotheque(t_bibliotheque * pBibli);

int chercher_livre(int isbn, t_bibliotheque * pBibli, t_livre * temp_livre);

int emprunter_livre_isbn(int isbn, t_bibliotheque * pBibli);

void chercher_livre_moteur(char * param, t_bibliotheque * pBibli, int option, t_pile * pile);


#endif


