//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

#define MAX_OPTION_CHOIX 2
#define MAX_CHOIX 4
#define MIN_CHOIX 0

//void remise_partielle(t_bibliotheque * pbiblio);


int main()
{
    t_etudiant etudiant;
    //t_bibliotheque biblio;

    t_bibliotheque bibli; //fichier principale de bibliotheque

    //pile pour le robot
    t_pile * pile_robot;

    //tete de la chaine dynamique chariot
    lien  tete;
    creer(&tete);

    //Initialiser la vitess du chariot
    int vitesse_chariot;
    chariot_set_vitesse(VITESSE_CHARIOT_DEFAUT);

    int position_chariot = POS_KIOSK;

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
            case 4: options(&bibli, &tete);break;
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
	printf("4 - Options\n");
    printf("0 - Quitter");
    printf("\n\n");

	printf("================================================================================\n");

    do{
        scanf("%d",&choix_user);

    }while(choix_user < MIN_CHOIX || choix_user > MAX_CHOIX); //limite du choix de l'utilisateur
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



void options(t_bibliotheque * pbiblio, lien * tete)
{
    int choix_menu = 0;

    do
	{
	    // Gestion du menu.
		choix_menu = afficher_menu_options();

		switch (choix_menu)
		{
            case 1: options_vitesse(); break;
            case 2: printf("BOOM"); break;
            case 0: break; // Quitter.
            default: exit(0); break;
		}
	} while (choix_menu != 0);
}


void afficher_menu_options()
{
    system("cls");//efface l'ecran

    int choix_user=0; //variable pour le choix

	printf("================================================================================\n");
	printf("                           OPTIONS \n");
	printf("================================================================================\n");

	printf("1 - Vitesse du chariot\n");
	printf("2 - Grandeur des etageres de la bibliotheque \n");
    printf("0 - Quitter");
    printf("\n\n");

	printf("================================================================================\n");

    do{
        scanf("%d",&choix_user);

    }while(choix_user < MIN_CHOIX || choix_user > MAX_OPTION_CHOIX); //limite du choix de l'utilisateur
}



void options_vitesse()
{
    int vitesse = VITESSE_CHARIOT_DEFAUT;
    printf("Quel est la vitesse (secondes) que vous voulez asigner au chariot?\n");
    scanf("%d", &vitesse);

    chariot_set_vitesse(vitesse);

    printf("\nLa vitesse a ete asignee avec succes\n");
    super_pause();
}
