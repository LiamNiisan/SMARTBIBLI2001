#include <stdio.h>
#include <stdlib.h>

#include "t_biblio.h"
#include "t_biblio_chariot.h"
#include "t_biblio_machine.h"
#include "t_biblio_robot.h"
#include "t_pile.h"
#include "t_chaine.h"


//void remise_partielle(t_bibliotheque * pbiblio);


int main()
{


    t_etudiant etudiant;
    //t_bibliotheque biblio;

    t_bibliotheque bibli; //fichier principale de bibliotheque

    t_livre * chariot_livres;

    t_pile * pile_robot;

    int compteur_nb_noeudlivre_chariot = 0;

    lien  tete;
    creer(&tete);

    /*t_livre test;

    strcpy(test.auteur_nom, "YO");
    strcpy(test.auteur_prenom, "LO");
    strcpy(test.titre, "BOOM");
    test.isbn = 666;*/

    /*insere_au_debut(&tete, test);
    afficher(tete);  getch()*/;

    //menu fonctionelle avec generation d'un user random
    //etudiant_servir(&etudiant,&biblio);
    //remise_partielle(&biblio);

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
            case 2: etudiant_servir(&etudiant,&bibli, &tete); break;
            case 3: simulateur(&bibli, &tete); break;
            case 0: break; // Quitter.
            default: exit(0); break;
		}
	} while (choix_menu != 0);

    return 0;
}


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

    }while(choix_user < 0 || choix_user > 3); //limite du choix de l'utilisateur
}

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
