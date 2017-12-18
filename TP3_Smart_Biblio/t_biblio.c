//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi (JAIB06029608) & Felix-Olivier Moreau (MORF30059700)
//Pour le cours ING145

#include "t_biblio.h"

void afficher_menu_bibliotheque(t_bibliotheque * pBibli)
{
    // Déclaration des variables.
	int choix_menu = 0; //choix du menu option
	int lecturefichier=0; //verification de la lecture fichier

	// Initialisation de la fonction rand()
	srand(time(NULL));

	do
	{
	    // Gestion du menu.
		choix_menu = demander_choix_menu();

		switch (choix_menu)
		{
		case 1: afficher_bibliotheque(pBibli); break;
		case 2: lire_fichier(pBibli,&lecturefichier); break;
		case 3: modifier_livre(pBibli); break;
		case 4: retirer_livre(pBibli); break;
		case 5: emprunter_livre(pBibli); break;
		case 6: gerer_retours(pBibli); break;
		case 7: generer_rapport(pBibli); break;
		case 8: sauvegarder_fichier(pBibli); break;
		case 0: break; // Quitter.
		default: exit(0); break;
		}
	} while (choix_menu != 0);

}


void lire_fichier(t_bibliotheque * pBibli, int * lecture)
{

    int cycle=*lecture;

    if(cycle == 0)
    {
        FILE * fichierbiblio; //fichier FILE
        int i; //variable d'incrementation
        int nb_livre;
        int type_livre;
        char data[100]; //pour stocker de l'information
        t_livre livre_temp; //fichier de livre temporaire

        fichierbiblio = fopen(BIBLIO_FICHIER,"r+");

        //verifie si le fichier s'ouvre
        if(fichierbiblio==NULL)
        {
            printf("Erreur de lecture du fichier %s ... \n", FICHIERBIBLIO);
        }

        //Si le fichier s'ouvre et transfert vers livre temporaire
        else
        {
            fgets(data, TAILLE_TITRE, fichierbiblio);

            nb_livre = atoi(data);

            for(i = 0; i < nb_livre; i++)
            {
                fgets(data, TAILLE_TITRE, fichierbiblio);//permet de faire un saut de ligne
                fgets(data, TAILLE_TITRE, fichierbiblio); //genre
                type_livre = atoi(data);

                livre_temp.genre = (t_genre)type_livre;

                fgets(data, TAILLE_TITRE, fichierbiblio); //titre
                strcpy(livre_temp.titre, data);
                retirer_sautligne(livre_temp.titre);

                fgets(data, TAILLE_TITRE, fichierbiblio);
                strcpy(livre_temp.auteur_prenom, data);
                retirer_sautligne(livre_temp.auteur_prenom);

                fgets(data, TAILLE_TITRE, fichierbiblio);
                strcpy(livre_temp.auteur_nom, data);
                retirer_sautligne(livre_temp.auteur_nom);

                fgets(data, TAILLE_TITRE, fichierbiblio);
                livre_temp.nb_pages = atoi(data);

                fgets(data, TAILLE_TITRE, fichierbiblio);
                livre_temp.isbn = atoi(data);

                fgets(data, TAILLE_TITRE, fichierbiblio);
                livre_temp.bEmprunte = atoi(data);

                pBibli->livres[type_livre][pBibli->nb_livres[type_livre]] = livre_temp;
                pBibli->nb_livres[type_livre]++;


                //pour chaque livre analyser, on les classes comme disponible ou emprunter
                if(pBibli->livres[type_livre][i].bEmprunte == 0)
                {
                    pBibli->rapport.nb_livres_dispo++;
                }
                else
                {
                    pBibli->rapport.nb_livres_emprunt++;
                }
            }

            //effet d'attente
            printf("Lecture du fichier de bibliotheque");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf("Done\n");
        }

        fclose(fichierbiblio);//ferme le fichier
        cycle++;
        super_pause();

    }
    //ce else permet d'empecher le reouverture du fichier pour eviter un bug
    else
    {
        printf("Vous avez deja ouvert le fichier %s ...\n",FICHIERBIBLIO);
        super_pause();
    }
    //envois le cycle au pointeur de lecture
    *lecture = cycle;
}


void super_pause()
{
	printf("Appuyez sur une touche pour continuer! \n");
	_getch();
}

void retirer_sautligne(char * chaine)
{
	int pos = strlen(chaine) - 1;
	if (chaine != NULL && chaine[pos] == '\n')
		chaine[pos] = '\0'; // Si on trouve \n à la fin, on le remplace par \0
}


int demander_choix_menu(){
    system("cls");//efface l'ecran

    int choix_user=0; //variable pour le choix

	printf("================================================================================\n");
	printf("                                SMART Bibliotheque 2000 ULTRA\n");
	printf("================================================================================\n");

	printf("1 - Afficher Bibliotheque\n");
	printf("2 - Lire Fichier Bibliotheque\n");
	printf("3 - Modifier Livre\n");
	printf("4 - Retirer Livre\n");
	printf("5 - Generer Rapport\n");
	printf("6 - Sauvegarder Bibliotheque\n");
    printf("0 - Quitter");
    printf("\n\n");

	printf("================================================================================\n");

    do{
        scanf("%d",&choix_user);

    }while(choix_user < 0 || choix_user > 9); //limite du choix de l'utilisateur

}


void initialiser_bibliotheque(t_bibliotheque * pBibli)
{
    int i;

    for(i = 0; i < NB_GENRES; i++)
    {
        pBibli->nb_livres[i] = 0;
    }

    biblio_agrandir_etagere(pBibli, NB_LIVRES_MAX_RANGEE);
}

void initialiser_rapport(t_bibliotheque * pBibli)
{
    pBibli->rapport.nb_livres_dispo=0;
    pBibli->rapport.nb_livres_emprunt=0;
}

void sauvegarder_fichier(t_bibliotheque * pBibli)
{

    if(verifier_disp_bibliotheque(pBibli))
    {

        FILE * fichierbiblio; //fichier de biblio.txt
        int i; //variable d'incrementation
        int j; //variable d'incrementation
        int nb_livre = 0;
        char data[DATA];

        fichierbiblio = fopen(BIBLIO_FICHIER,"w+"); //ouvre le fichier pour ecriture W+

        //permet de verifier si le fichier ouvre
        if(fichierbiblio==NULL){
            printf("Erreur de lecture du fichier %s ... \n", FICHIERBIBLIO);
        }

        //si le fichier ouvre...
        else{

            for(i = 0; i < NB_GENRES; i++)
            {
                nb_livre += pBibli->nb_livres[i];
            }

            itoa(nb_livre, data, 10);
            fputs(data, fichierbiblio);
            fputs("\n\n", fichierbiblio);

            for(i = 0; i < NB_GENRES; i++)
            {
                for(j = 0; j < pBibli->nb_livres[i]; j++)
                {


                    itoa((int)pBibli->livres[i][j].genre, data, 10);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    strcpy(data, pBibli->livres[i][j].titre);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    strcpy(data, pBibli->livres[i][j].auteur_prenom);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    strcpy(data, pBibli->livres[i][j].auteur_nom);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    itoa(pBibli->livres[i][j].nb_pages, data, 10);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    itoa(pBibli->livres[i][j].isbn, data, 10);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    itoa(pBibli->livres[i][j].bEmprunte, data, 10);
                    fputs(data, fichierbiblio);
                    fputs("\n", fichierbiblio);

                    fputs("\n", fichierbiblio);
                }
            }
            //effet de chargement
            printf("Sauvegarde en cours");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf(".");
            Sleep(500);
            printf("Done\n");
        }

        fclose(fichierbiblio);//ferme le fichier biblio.txt
        super_pause();
    }
    //message si la lecture n'a pas ete fait
    else
    {
        printf("Vous ne pouvez pas sauvegarder vos modificiations avant d'avoir ouvert le fichier...\n");
        super_pause();
    }

}


void afficher_bibliotheque(t_bibliotheque * pBibli)
{
    int i; //variable d'incrementation
    int j; //variable d'incrementation


	if(verifier_disp_bibliotheque(pBibli))
    {
        system("cls"); //efface l'ecran

        //va chercher tous les livres de toutes les categories
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                printf("-------------------------------\n");
                printf("Titre: %s \n", pBibli->livres[i][j].titre);
                printf("Auteur: %s %s \n", pBibli->livres[i][j].auteur_prenom, pBibli->livres[i][j].auteur_nom);
                printf("Genre: %d \n", pBibli->livres[i][j].genre);
                printf("Pages: %d \n", pBibli->livres[i][j].nb_pages);
                printf("ISBN: %d \n", pBibli->livres[i][j].isbn);
                printf("Emprunte: %d \n", pBibli->livres[i][j].bEmprunte);
                printf("-------------------------------\n");
            }
        }
    }
    //le message est si la lecture du fichier biblio.txt n'a pas ete fait
    else
    {
        printf("Bibliotheque vide, veuillez l'actualiser... \n");
    }

    super_pause();
}


void generer_rapport(t_bibliotheque * pBibli)
{
    printf("#######################################\n");
	printf("Nombre de livres disponibles : %d\n",pBibli->rapport.nb_livres_dispo);
	printf("Nombre de livres emprunts : %d\n",pBibli->rapport.nb_livres_emprunt);
    printf("#######################################\n");
    super_pause();
}


void emprunter_livre(t_bibliotheque * pBibli)
{
    int isbn=0;
    int i=0; //variable d'incrementation
    int j=0; //variable d'incrementation
    int resultat=100;

    if(verifier_disp_bibliotheque(pBibli)){

        resultat = 0;
        //le choix du ISBN de l'utilisateur
        printf("Entrez le ISBN du livre que vous voulez emprunter : ");
        scanf("%d",&isbn);

        //verifie chaque livre afin de voir si le ISBN de l'utilsateur existe
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                if(pBibli->livres[i][j].isbn == isbn)
                {

                    if(pBibli->livres[i][j].bEmprunte == 1)
                    {
                            resultat = 2;
                    }

                    if(pBibli->livres[i][j].bEmprunte == 0)
                    {
                        pBibli->livres[i][j].bEmprunte = 1 ;
                        resultat = 1;
                    }

                }
            }
        }

        //si le ISBN de l'utilisateur est disponible
        if(resultat == 1 )
        {
            pBibli->rapport.nb_livres_emprunt++;
            pBibli->rapport.nb_livres_dispo--;

            printf("le livre de ISBN %d est maintenant emprunter!...\n",isbn);

        }
        //si le ISBN de l'utilisateur est deja emprunter
        if(resultat == 2)
        {
            printf("Le livre de ISBN %d est deja emprunter ... \n",isbn);
        }

        //si le ISBN de l'utilisateur est pas trouvable
        if(resultat == 0)
        {
            printf("le livre de ISBN %d est introuvable dans le fichier %s ...\n",isbn,FICHIERBIBLIO);
        }
    }
    //ce message est si le fichier biblio.txt n'a pas ete lu
    else
    {
        printf("Pour emprunter un livre, vous devez ouvrir le fichier bibliotheque %s...\n",FICHIERBIBLIO);
    }

	super_pause();
}


void gerer_retours(t_bibliotheque * pBibli)
{
    int i=0; //variable d'incrementation
    int j=0; //variable d'incrementation

    //si le fichier biblio.txt a ete lu
    if(verifier_disp_bibliotheque(pBibli))
    {
        pBibli->rapport.nb_livres_dispo += pBibli->rapport.nb_livres_emprunt;//livre disponible obtient la valeur de livre emprunter
        pBibli->rapport.nb_livres_emprunt=0; //livre emprunter devient 0

        //tous les livres de tous les genres mettre leur valeur d'emprunter a 0
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                    pBibli->livres[i][j].bEmprunte=0;
            }
        }

       printf("Tous les livres sont retourner et disponible ...\n");

	}
    //si le fichier biblio.txt n'a pas ete lu
	else{

        printf("Vous devez lire le fichier %s avant de faire des retours ...\n",FICHIERBIBLIO);
	}


    super_pause();

}


void modifier_livre(t_bibliotheque * pBibli)
{
    int resultat = 0; //varible qui permet d'avoir des conditions
    int ISBN = 0;

    if(verifier_disp_bibliotheque(pBibli))
    {
        int i; //variable d'incrementation
        int j; //variable d'incrementation
        int int_data;
        char char_data[100];

        system("cls"); //efface l'ecran

        //enregistre le choix de l'utilisateur dans la variable ISBN
        printf("Entrez le ISBN du livre a modifier : ");
        scanf("%d", &ISBN);

        //trouve le ISBN de l'utilisateur parmis le tableau des livres
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                if(pBibli->livres[i][j].isbn == ISBN)
                {
                    printf("----------------- \n");
                    printf("Titre: %s \n", pBibli->livres[i][j].titre);
                    printf("Auteur: %s %s \n", pBibli->livres[i][j].auteur_prenom, pBibli->livres[i][j].auteur_nom);
                    printf("Genre: %d \n", pBibli->livres[i][j].genre);
                    printf("Pages: %d \n", pBibli->livres[i][j].nb_pages);
                    printf("ISBN: %d \n", pBibli->livres[i][j].isbn);
                    printf("Emprunte: %d \n", pBibli->livres[i][j].bEmprunte);
                    printf("-----------------\n");

                    //section de modification du livre de l'utilisateur
                    do{
                        printf("Entrez le nouveau genre: ");
                        scanf(" %d", &int_data);
                    }
                    while(int_data < 0 || int_data > 5);

                    pBibli->livres[i][j].genre = (t_genre)int_data;

                    printf("Ecrivez le nouveau titre du livre: ");
                    scanf (" %[^\n]%*c", char_data);
                    strcpy(pBibli->livres[i][j].titre, char_data);

                    printf("Ecrivez le nouveau nom de l'auteur du livre: ");
                    scanf(" %s", char_data);
                    strcpy(pBibli->livres[i][j].auteur_nom, char_data);

                    printf("Ecrivez le nouveau prenom de l'auteur du livre: ");
                    scanf(" %s", char_data);
                    strcpy(pBibli->livres[i][j].auteur_prenom, char_data);

                    do{
                        printf("Entrez le nouveau nombre de pages: ");
                        scanf(" %d", &int_data);
                    }
                    while(int_data<0);

                    pBibli->livres[i][j].nb_pages = int_data;

                    resultat++;// si un livre a ete trouve, on le signale

                    printf("\nVous avez modifie le livre avec le ISBN: %d\n", ISBN);
                    super_pause();

                }
            }
        }

        //si le ISBN de l'utilisateur est introuvable
        if(resultat == 0)
        {
            printf("ISBN %d est introuvable...\n",ISBN);
            super_pause();
        }
    }
    //si le fichier biblio.txt n'a pas ete lu
    else
    {
        printf("Veuillez charger la bibliotheque avant de faire des modifications...\n");
        super_pause();
    }


}


void retirer_livre(t_bibliotheque * pBibli)
{
        //si la lecture du fichier biblio.txt a ete lu
        if(verifier_disp_bibliotheque(pBibli))
        {
            int ISBN = 0;
            int i; //variable d'incrementation
            int j; //variable d'incrementation
            int k; //variable d'incrementation
            t_livre null_livre;
            int dispo = 0;

            //choix de l'tulisateur sur le ISBN a suprimer
            printf("Entrez le ISBN du livre a modifier : ");
            scanf("%d", &ISBN);

            for(i = 0; i < NB_GENRES; i++)
            {
                for(j = 0; j < pBibli->nb_livres[i]; j++)
                {
                    if(pBibli->livres[i][j].isbn == ISBN)
                    {
                        //Mettre a jour le rapport selon le status du livre
                        if(pBibli->livres[i][j].bEmprunte)
                        {
                            pBibli->rapport.nb_livres_emprunt--;
                        }
                        else
                        {
                            pBibli->rapport.nb_livres_dispo--;
                        }


                        //Pousser toutes les cases de livres a gauche a la place du livre enleve
                        for(k = j; k < (pBibli->nb_livres[i] - 1); k++)
                        {
                            pBibli->livres[i][k] = pBibli->livres[i][k + 1];
                        }

                        pBibli->livres[i][pBibli->nb_livres[i]] = null_livre;
                        pBibli->nb_livres[i]--;
                    }
                }
            }


        }

        //si le fichier biblio.txt n'a pas ete lu
        else{
            printf("Pour retirer un livre, vous devez lire le fichier de bibliotheque %s \n",FICHIERBIBLIO);
            super_pause();
        }
}

int verifier_disp_bibliotheque(t_bibliotheque * pBibli)
{
    int i; //variable d'incrementation
    int rempli = 0; //variable de return pour savoir si le fichier est lu ou pas
    for(i = 0; i < NB_GENRES; i++)
    {
        if (pBibli->nb_livres[i] != 0)
        {
            rempli++; //s'il y a pas de 0, alors fichier lu
        }
    }

    return rempli;
}


int chercher_livre(int isbn, t_bibliotheque * pBibli, t_livre * temp_livre)
{
    int i = 0;
    int j = 0;

    if(verifier_disp_bibliotheque(pBibli))
    {
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                if(pBibli->livres[i][j].isbn == isbn)
                {
                    strcpy(temp_livre->titre, pBibli->livres[i][j].titre);
                    strcpy(temp_livre->auteur_nom, pBibli->livres[i][j].auteur_nom);
                    strcpy(temp_livre->auteur_prenom, pBibli->livres[i][j].auteur_nom);
                    temp_livre->isbn = pBibli->livres[i][j].isbn;
                    temp_livre->nb_pages = pBibli->livres[i][j].nb_pages;
                    temp_livre->bEmprunte = pBibli->livres[i][j].bEmprunte;
                    temp_livre->genre = pBibli->livres[i][j].genre;

                    return 1;
                }
            }
        }

        printf("BIBLIO: Livre introuvable...\n");
        return NULL;
    }
    else
    {
        printf("BIBLIO: Pour retirer un livre, vous devez lire le fichier de bibliotheque %s \n",FICHIERBIBLIO);
        return NULL;
    }
}

int emprunter_livre_isbn(int isbn, t_bibliotheque * pBibli)
{
    int i=0; //variable d'incrementation
    int j=0; //variable d'incrementation
    int resultat = LIVRE_INTROUVABLE;

    if(verifier_disp_bibliotheque(pBibli))
    {
        //verifie chaque livre afin de voir si le ISBN de l'utilsateur existe
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                if(pBibli->livres[i][j].isbn == isbn)
                {

                    if(pBibli->livres[i][j].bEmprunte == 1)
                    {
                        resultat = LIVRE_NON_DISPONIBLE;
                    }

                    if(pBibli->livres[i][j].bEmprunte == 0)
                    {
                        pBibli->livres[i][j].bEmprunte = 1 ;
                        pBibli->rapport.nb_livres_emprunt++;
                        pBibli->rapport.nb_livres_dispo--;
                        resultat = LIVRE_EMPRUNTE;
                    }

                }
            }
        }

    }
    //ce message est si le fichier biblio.txt n'a pas ete lu
    else
    {
        printf("BIBLIO: Pour emprunter un livre, vous devez ouvrir le fichier bibliotheque %s...\n",FICHIERBIBLIO);
    }

	return resultat;
}


int retourner_livre_isbn(int isbn, t_bibliotheque * pBibli)
{
    int i=0; //variable d'incrementation
    int j=0; //variable d'incrementation
    int resultat = LIVRE_INTROUVABLE;

    if(verifier_disp_bibliotheque(pBibli))
    {
        //verifie chaque livre afin de voir si le ISBN de l'utilsateur existe
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                if(pBibli->livres[i][j].isbn == isbn)
                {
                        pBibli->livres[i][j].bEmprunte = 0 ;
                        pBibli->rapport.nb_livres_emprunt--;
                        pBibli->rapport.nb_livres_dispo++;
                        resultat = LIVRE_REMIS;
                }
            }
        }

    }
    //ce message est si le fichier biblio.txt n'a pas ete lu
    else
    {
        printf("BIBLIO: Pour remttre un livre, vous devez ouvrir le fichier bibliotheque %s...\n",FICHIERBIBLIO);
    }

	return resultat;
}


void chercher_livre_moteur(char * param, t_bibliotheque * pBibli, int option, t_pile * pile)
{
    char data[DATA];
    int i = 0;
    int j = 0;


    init_pile(pile);

    if(verifier_disp_bibliotheque(pBibli))
    {
        for(i = 0; i < NB_GENRES; i++)
        {
            for(j = 0; j < pBibli->nb_livres[i]; j++)
            {
                switch (option)
                {
                    case RECHERCHE_ISBN:
                        itoa(pBibli->livres[i][j].isbn, data, 10);
                    break;

                    case RECHERCHE_GENRE:
                        itoa((int)pBibli->livres[i][j].genre, data, 10);
                    break;

                    case RECHERCHE_AUTEUR:
                        strcpy(data, pBibli->livres[i][j].auteur_prenom);
                        strcat(data, " ");
                        strcat(data, pBibli->livres[i][j].auteur_nom);
                    break;

                    case RECHERCHE_TITRE:
                        strcpy(data, pBibli->livres[i][j].titre);
                    break;
                }

                /*if(strstr(data, param) != NULL)
                {
                    empile(pile, pBibli->livres[i][j]);
                }*/

                if(comparer_string(param, data))
                {
                    empile(pile, pBibli->livres[i][j]);
                }
            }
        }
    }
    else
    {
        printf("BIBLIO: Pour retirer un livre, vous devez lire le fichier de bibliotheque %s \n",FICHIERBIBLIO);
    }
}

void biblio_agrandir_etagere(t_bibliotheque * pBibli, int grandeur)
{
    int i = 0;
    int j = 0;
    t_livre temp_tab[pBibli->nb_livres_rangee];

    for(i = 0; i < NB_GENRES; i++)
    {
        for(j = 0; j < pBibli->nb_livres_rangee; j++)
        {
            temp_tab[j] = pBibli->livres[i][j];
        }

        pBibli->livres[i] = (t_livre *)malloc(grandeur * sizeof(t_livre));

        for(j = 0; j < pBibli->nb_livres_rangee; j++)
        {
            pBibli->livres[i][j] = temp_tab[j];
        }
    }

    pBibli->nb_livres_rangee = grandeur;
}


int est_minuscule(char lettre)
{
    //regarder si la valeur ascii de la lettre est minuscule
    if(lettre >= 'a' && lettre <= 'z')
        return 1;
    else
        return 0;
}

int est_majuscule(char lettre)
{
    //regarder si la valeur ascii de la lettre est majuscule
    if(lettre >= 'A' && lettre <= 'B')
        return 1;
    else
        return 0;
}

int vers_majuscule(char lettre)
{
    //difference de 32 entre les deux
    return lettre - 32;
}


int vers_minuscule(char lettre)
{
    //difference de 32 entre les deux
    return lettre + 32;
}

int inverser_maj_min(char lettre)
{
    if(est_majuscule(lettre))
    {
        return vers_minuscule(lettre);
    }
    else if(est_minuscule(lettre))
    {
        return vers_majuscule(lettre);
    }

    return lettre;
}


int comparer_string(char * param, char * titre)
{
    int i = 0;
    int j = 0;
    int pareil = 1;
    char char_inv;

    while(titre[i] != '\0')
    {
        pareil = 1;
        j = 0;

        //On regarde chacune des positions dans la chaine si elle correspond au parametre de recherche
        while(param[j] != '\0')
        {
            //Pour ne pas perdre de temps
            if(pareil)
            {
                if(param[j] != titre[i + j])
                {
                    char_inv = inverser_maj_min(param[j]);
                    if(char_inv != titre[i + j])
                    {
                        //Si un des chars n'est pas egal, c'est automatiquement considere non egal, on attend alors le prochain
                        //tour de boucle pour retester
                        pareil = 0;
                    }
                }
            }
            j++;
        }

        if(pareil)
        {
            //Si c'est pareil une fois alors automatiquement c'est bon donc on peux sortir
            return pareil;
        }
        i++;
    }
    return NULL;
}



