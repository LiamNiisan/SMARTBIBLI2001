#include "t_biblio.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define FICHIERBIBLIO "biblio.txt"


 int lecturefichier=0; //verification de la lecture fichier

void retirer_sautligne(char * chaine)
{
	int pos = strlen(chaine) - 1;
	if (chaine != NULL && chaine[pos] == '\n')
		chaine[pos] = '\0'; // Si on trouve \n � la fin, on le remplace par \0
}

void super_pause()
{
	printf("Appuyez sur une touche pour continuer! \n");
	_getch();
}

void initialiser_bibliotheque(t_bibliotheque * pBibli)
{
    int i;

    for(i = 0; i < NB_GENRES; i++)
    {
        pBibli->nb_livres[i] = 0;
    }
}

void initialiser_rapport(t_bibliotheque * pBibli)
{
    pBibli->rapport.nb_livres_dispo=0;
    pBibli->rapport.nb_livres_emprunt=0;
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

void lire_fichier(t_bibliotheque * pBibli, int * lecture)
{

    int cycle=*lecture;

    if(cycle == 0)
    {
        FILE * fichierbiblio;//fichier FILE
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




