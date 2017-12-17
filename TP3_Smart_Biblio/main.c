//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


#define MAX_CHOiX 3
#define MIN_CHOIX 0

//void remise_partielle(t_bibliotheque * pbiblio);


int main()
{
    t_etudiant etudiant;
    //t_bibliotheque biblio;

    t_bibliotheque bibli; //fichier principale de bibliotheque

    //livre pour le chariot
    t_livre * chariot_livres;


    //pile pour le robot
    t_pile * pile_robot;

    int compteur_nb_noeudlivre_chariot = 0;

    lien  tete;
    creer(&tete);

    // Initialisation de la bibliotheque
	initialiser_bibliotheque(&bibli);

    //initialisation du rapport
    initialiser_rapport(&bibli);

    int choix_menu = 0;

    do
	{
	    // Gestion du menu.
		choix_menu = afficher_menu_principal();

		switch (choix_menu)
		{
            case 1: afficher_menu_bibliotheque(&bibli); break;
            case 2: etudiant_servir(&etudiant,&bibli, &tete, &pile_robot); break;
            case 3: simulateur(&bibli, &tete); break;
            case 0: break; // Quitter.
            default: exit(0); break;
		}
	} while (choix_menu != 0);

    return 0;
}


/******************************************************************************
// afficher_menu_principale
// ****************************************************************************
//
// Permet d'affichier a l'usager le menu principale
//
// Paramètres 	:
// Retour 		: void
//*****************************************************************************/

void afficher_menu_principal()
{
    system("cls");//efface l'ecran

    int choix_user=0; //variable pour le choix

	printf("================================================================================\n");
	printf("                           SMART Bibliotheque 2000 ULTRA\n");
	printf("================================================================================\n");

	printf("1 - Bibliotheque\n");
	printf("2 - Kiosque\n");
	printf("3 - Simulateur\n");
    printf("0 - Quitter");
    printf("\n\n");

	printf("================================================================================\n");

    do{
        scanf("%d",&choix_user);

    }while(choix_user < MIN_CHOIX || choix_user > MAX_CHOiX); //limite du choix de l'utilisateur
}





/******************************************************************************
// simulateur de remise partielle
// ****************************************************************************
//
//  Cette fonction etait pour le simulateur de la remise partielle
//
// Paramètres 	: t_bibliotheque * pbiblio, lien * tete
// Retour 		: void
//*****************************************************************************/


//remise partielle
void simulateur(t_bibliotheque * pbiblio, lien * tete){

    int lecturefichier=0; //verification de la lecture fichier

    printf("\nInitialisation en cours...\n");
    initialiser_bibliotheque(&pbiblio);
    initialiser_rapport(&pbiblio);

    printf("Lecture en cours...\n");
    lire_fichier(&pbiblio,&lecturefichier);

    printf("Generer le rapport initial\n");
    generer_rapport(&pbiblio);

    printf("Emprunt du livre avec ISBN : 1234\n");
    chariot_apporter_livre(1234, pbiblio, tete);

    printf("Emprunt du livre avec ISBN : 111\n");
    chariot_apporter_livre(111, pbiblio, tete);

    printf("Emprunt du livre avec ISBN : 1001\n");
    chariot_apporter_livre(1001, pbiblio, tete);


    printf("Voici les livres dispobible sur le chariot\n");
    afficher_livres_chariot(pbiblio, tete);

    printf("Generer le rapport final\n");
    generer_rapport(&pbiblio);
}
