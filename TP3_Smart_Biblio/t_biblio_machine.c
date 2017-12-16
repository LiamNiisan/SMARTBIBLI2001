#include "t_biblio_machine.h"






void etudiant_random_test(t_etudiant * etudiant)
{
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


void etudiant_servir(t_etudiant * etudiant, t_bibliotheque * bibli, lien * tete, t_pile * pile_robot)
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
            case 2: etudiant_retour_livre(bibli,pile_robot);break;
            case 1: etudiant_chercher_livre(bibli, tete);break;
            case 3: etudiant_apporter_livre(bibli, tete, etudiant);break;
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

    }while(choix_user < 0 || choix_user > 5); //limite du choix de l'utilisateur
}


void etudiant_apporter_livre(t_bibliotheque * biblio, lien * tete, t_etudiant * etudiant)
{
    int isbn = 0;
    printf("Entrez le ISBN du livre que vous voulez que le chariot vous apporte : ");
    scanf("%d",&isbn);
    chariot_apporter_livre(isbn, biblio, tete);
}

void etudiant_retour_livre(t_bibliotheque * biblio, t_pile* pile_robot)
{
    t_livre livretemp;

    int i = 0;
    int j = 0;
    int isbn = 0;

    printf("Entrez le ISBN du livre que vous voulez retourner a la bibliotheque : ");
    scanf("%d",&isbn);

    chercher_livre(isbn,biblio,&livretemp);
    printf("Vous retourner au kiosque : \n");
    printf("%s\n",livretemp.titre);
    printf("%s, ",livretemp.auteur_nom);
    printf("%s\n",livretemp.auteur_prenom);
    printf("Nombre de pages : %d\n",livretemp.nb_pages);
    printf("ISBN : %d\n\n",livretemp.isbn);



    empile(pile_robot,livretemp);

    super_pause();

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
            case 2: rechercher_livre(biblio, tete);break;
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
    afficher(*tete);

    super_pause();
}


void rechercher_livre(t_bibliotheque * biblio, lien * tete)
{
    int choix_menu =0;

	do
	{
	    // Gestion du menu.
		choix_menu = afficher_menu_moteur_recherche();

		switch (choix_menu)
		{
            case 1: moteur_recherche(biblio, RECHERCHE_ISBN, tete);break;
            case 2: moteur_recherche(biblio, RECHERCHE_GENRE, tete);break;
            case 3: moteur_recherche(biblio, RECHERCHE_AUTEUR, tete);break;
            case 4: moteur_recherche(biblio, RECHERCHE_TITRE, tete);break;
            case 0: break; // Quitter.
            default: exit(0); break;
		}
	} while (choix_menu != 0);
}



int afficher_menu_moteur_recherche()
{
    system("cls");//efface l'ecran

    int choix_user=0; //variable pour le choix


    printf("================================================================================\n");
	printf("                                Kiosque Biblio Virtuel\n");
	printf("================================================================================\n");

    printf("\n\n---------Moteur de recherche---------\n\n");
	printf("1. Chercher par ISBN\n");
	printf("2. Chercher par genre\n");
	printf("3. Chercher par auteur\n");
	printf("4. Chercher par titre\n");
	printf("0. Quitter\n\n");

	printf("================================================================================\n");

	do{
        scanf("%d",&choix_user);

    }while(choix_user < 0 || choix_user > 4); //limite du choix de l'utilisateur
}



void moteur_recherche(t_bibliotheque * biblio, int option, lien * tete)
{
    char * genres[PARAMETRES_RECHERCHE] = {"ISBN", "auteur", "titre", "genre"};
    char parametre[100];

    int nb_livres;
    int i;
    int choix = 0;

    t_livre * resultat;
    t_livre dernier_element;

    t_pile pile;

    printf("Veuillez specifier quel %s vous desire chercher\n", genres[option]);

    switch (option)
	{
        case RECHERCHE_AUTEUR:
        case RECHERCHE_TITRE:
        case RECHERCHE_ISBN:
            scanf(" %[^\n]%*c", parametre);
        break;

        case RECHERCHE_GENRE:
            printf("0 - AUCUN\n");
            printf("1 - FICTION\n");
            printf("2 - HISTOIRE\n");
            printf("3 - SCIENCE\n");
            printf("4 - ENFANTS\n");
            printf("5 - INFORMATIQUE\n");
            scanf("%s", parametre);

        break;
	}

	chercher_livre_moteur(parametre, biblio, option, &pile);

	nb_livres = pile.sommet;

    resultat = (t_livre *)malloc(nb_livres * sizeof(t_livre));

    for(i = 0; i < nb_livres; i++)
    {
        dernier_element = desempile(&pile);
        resultat[i] = dernier_element;
        printf("-------- %d --------- \n", i + 1);
        printf("Titre: %s \n", dernier_element.titre);
        printf("Auteur: %s %s \n", dernier_element.auteur_prenom, dernier_element.auteur_nom);
        printf("Genre: %d \n", dernier_element.genre);
        printf("Pages: %d \n", dernier_element.nb_pages);
        printf("ISBN: %d \n", dernier_element.isbn);
        printf("Emprunte: %d \n", dernier_element.bEmprunte);
        printf("-----------------\n");
    }

    if(nb_livres < 0)
    {
        printf("\nAucun livre avec les parametres rentre n'a ete trouve\n");
    }
    else
    {
        printf("\n%d resultats on ete trouve\n", nb_livres + 1);
        printf("Voulez vous demander au chariot d'aller chercher un de ces livres?\n");
        printf("1- Oui\n");
        printf("2- Non\n");
        scanf("%d", &choix);

        if(choix == 1)
        {
            printf("Quel est le numero dans la liste du livre que vous desirez?\n");
            scanf("%d", &choix);

            if(resultat[choix - 1].bEmprunte)
            {
                printf("\nCe livre est deja emprunte\n");
            }
            else
            {
                chariot_apporter_livre(resultat[choix - 1].isbn, biblio, tete);
            }
        }
    }
}

