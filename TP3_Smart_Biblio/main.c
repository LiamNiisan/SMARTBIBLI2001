#include <stdio.h>
#include <stdlib.h>

#include "t_biblio.h"
#include "t_biblio_chariot.h"
#include "t_biblio_machine.h"
#include "t_biblio_robot.h"
#include "t_pile.h"


//void remise_partielle(t_bibliotheque * pbiblio);


int main()
{
    t_etudiant etudiant;
    //t_bibliotheque biblio;

    t_bibliotheque bibli; //fichier principale de bibliotheque

    t_livre * chariot_livres;

    int compteur_nb_livre_chariot = 0;

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
            case 2: etudiant_servir(&etudiant,&bibli, chariot_livres, &compteur_nb_livre_chariot); break;
            case 3: simulateur(&bibli); break;
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


void simulateur(t_bibliotheque * pbiblio){

    int lecturefichier=0; //verification de la lecture fichier

    initialiser_bibliotheque(&pbiblio);
    initialiser_rapport(&pbiblio);
    lire_fichier(&pbiblio,&lecturefichier);
    generer_rapport(&pbiblio);
    emprunter_livre(&pbiblio);
    generer_rapport(&pbiblio);
}
