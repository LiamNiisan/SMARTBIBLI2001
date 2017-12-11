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
            case 2: etudiant_retour_livre(bibli, tete, etudiant);break;
            case 1: etudiant_chercher_livre(bibli, tete);break;
            case 3: etudiant_apporter_livre(bibli, tete, etudiant);break;
            case 4: etudiant_dossier(etudiant);break;
            case 5: afficher_bibliotheque(bibli); break;
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
	printf("3. Demande de livre au chariot\n");
	printf("4. Voir Dossier de l'Etudiant\n");
	printf("5. Voir les livres disponibles a la bibliotheque\n");
	printf("0. Quitter\n\n");

	printf("================================================================================\n");

	do{
        scanf("%d",&choix_user);

    }while(choix_user < 0 || choix_user > 5); //limite du choix de l'utilisateur
}


void etudiant_apporter_livre(t_bibliotheque * biblio, lien * tete, t_etudiant * etudiant)
{
    int  i = 0;
    int j = 0;

    if(verifier_disp_bibliotheque(biblio)){
        int isbn = 0;
        printf("Entrez le ISBN du livre que vous voulez apporter : ");
        scanf("%d",&isbn);
        chariot_apporter_livre(isbn, biblio, tete);
   }
   else{

        printf("Veuillez actualiser votre fichier biblio avant de pouvoir louer un livre...\n");
        printf("1- Bibliotheque... 2- Lire le fichier bibliotheque\n");
        super_pause();
   }
}

void etudiant_retour_livre(t_bibliotheque * biblio, lien * tete, t_etudiant * etudiant)
{
    int i=0;
    int j=0;
    int isbn=0;
    //chariot_retourner_livres(tete, biblio);

 //if(etudiant->livre_empreunter!=0){
    printf("Entrez le ISBN du livre que vous voulez retourner : ");
    scanf("%d",&isbn);



     for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < biblio->nb_livres[i]; j++)
            {
                if(biblio->livres[i][j].isbn == isbn)
                {
                    etudiant->livre_empreunter++;
                    robot_ajouter_livre(biblio->livres[i][j]);


                }
            }
        }

    //}
   // else{

        //printf("vous avez aucun livre empreunter a votre dossier...\n");

    //}

    //super_pause();
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

