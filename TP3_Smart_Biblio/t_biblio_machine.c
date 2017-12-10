#include "t_biblio_machine.h"
#include "t_biblio_chariot.h"
#include "t_chaine.h"


void etudiant_random_test(t_etudiant * etudiant){

    srand((unsigned)time(0));

        int date=0;
        int id_etudiant=0;

        date = rand() %(DATE_MAX - DATE_MIN);
        date+=2000;
        etudiant->date_etude = date;



        id_etudiant = rand() % (ID_MAX - ID_MIN);
        etudiant->no_etudiant = id_etudiant;

        etudiant->livre_empreunter = 0;


         printf("Date d'inscription : %d\n",etudiant->date_etude);
         printf("Numero permanent de l'etudiant : %d\n",etudiant->no_etudiant);

}


void etudiant_servir(t_etudiant * etudiant, t_bibliotheque * bibli, lien * tete)
{
    int etudiant_id=0;


    printf("================================================================================\n");
	printf("                                Kiosque Biblio Virtuel\n");
	printf("================================================================================\n");

	etudiant_random_test(etudiant);
	printf("\n\n");

	do{
        printf("Entrez un numero d'etudiant valide : ");
        scanf("%d",&etudiant_id);
	}
	while(etudiant_id != etudiant->no_etudiant);


    int choix_menu =0;

	do
	{
	    // Gestion du menu.
		choix_menu = afficher_menu_kiosque(etudiant);

		switch (choix_menu)
		{
            case 2: etudiant_retour_livre(bibli, tete);break;
            case 1: etudiant_chercher_livre(bibli, tete);break;
            case 3: etudiant_apporter_livre(bibli, tete);break;
            case 4: etudiant_dossier(etudiant);break;
            case 0: break; // Quitter.
            default: exit(0); break;
		}
	} while (choix_menu != 0);

}


int afficher_menu_kiosque(t_etudiant * etudiant)
{
    system("cls");//efface l'ecran

    int choix_user=0; //variable pour le choix


    printf("================================================================================\n");
	printf("                                Kiosque Biblio Virtuel\n");
	printf("================================================================================\n");

    printf("\n\nBonjour Etudiant No.%d - Comment puis-je vous aider aujourd'hui ?\n\n\n",etudiant->no_etudiant);
	printf("1. Chercher livre\n");
	printf("2. Retourner livre\n");
	printf("3. Apporter livre\n");
	printf("4. Voir Dossier de l'Etudiant\n");
	printf("0. Quitter\n\n");

	printf("================================================================================\n");

	do{
        scanf("%d",&choix_user);

    }while(choix_user < 0 || choix_user > 4); //limite du choix de l'utilisateur
}


void etudiant_apporter_livre(t_bibliotheque * biblio, lien * tete)
{

    int isbn = 0;
    printf("Entrez le ISBN du livre que vous voulez apporter : ");
    scanf("%d",&isbn);

    chariot_apporter_livre(isbn, biblio, tete);
}

void etudiant_retour_livre(t_bibliotheque * biblio, lien * tete)
{
    chariot_retourner_livres(tete, biblio);
}

void etudiant_chercher_livre(t_bibliotheque * biblio, lien * tete)
{
    int choix_menu =0;

	do
	{
	    // Gestion du menu.
		choix_menu = afficher_menu_recherche();

		switch (choix_menu)
		{
            case 1: afficher_livres_chariot(biblio, tete);break;
            case 2: printf("To be continued");break;
            case 0: break; // Quitter.
            default: exit(0); break;
		}
	} while (choix_menu != 0);
}

void etudiant_dossier(t_etudiant * etudiant){

    printf("\n---Dossier---\n");
    printf("Date d'inscription : %d\n",etudiant->date_etude);
    printf("Numero permanent de l'etudiant : %d\n",etudiant->no_etudiant);
    printf("Nombre de livre empreunte : %d\n\n",etudiant->livre_empreunter);
    super_pause();
}


int afficher_menu_recherche()
{
    system("cls");//efface l'ecran

    int choix_user=0; //variable pour le choix


    printf("================================================================================\n");
	printf("                                Kiosque Biblio Virtuel\n");
	printf("================================================================================\n");

    printf("\n\n---------Chercher un livre---------\n\n");
	printf("1. Regarder le chariot\n");
	printf("2. Moteur de recherche\n");
	printf("0. Quitter\n\n");

	printf("================================================================================\n");

	do{
        scanf("%d",&choix_user);

    }while(choix_user < 0 || choix_user > 2); //limite du choix de l'utilisateur
}


void afficher_livres_chariot(t_bibliotheque * biblio, lien * tete)
{
    /*int i = 0;
    for(i = 0; i < (nb_livres_chariot + 1); i++)
    {
        printf("-------------------------------\n");
        printf("Titre: %s \n", chariot_livres[i].titre);
        printf("Auteur: %s %s \n", chariot_livres[i].auteur_prenom, chariot_livres[i].auteur_nom);
        printf("Genre: %d \n", chariot_livres[i].genre);
        printf("Pages: %d \n", chariot_livres[i].nb_pages);
        printf("ISBN: %d \n", chariot_livres[i].isbn);
        printf("Emprunte: %d \n", chariot_livres[i].bEmprunte);
        printf("-------------------------------\n");
    }*/

    afficher(*tete);

    super_pause();
}

