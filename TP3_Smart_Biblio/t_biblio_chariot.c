//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi (JAIB06029608) & Felix-Olivier Moreau (MORF30059700)
//Pour le cours ING145

#include "t_biblio_chariot.h"


t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, lien * tete)
{
    printf("\nCHARIOT: Chercher livre avec ISBN : %d \nVeuillez patienter...\n", ISBN);

    t_livre temp_livre;
    int etat = 0;
    int vitesse = VITESSE_CHARIOT_DEFAUT;

    vitesse = chariot_get_vitesse();
    vitesse *= MILISECONDES;

    if(chercher_livre(ISBN, pBibli, &temp_livre))
    {
        //etat obtien la valeur de retour de emprunter_livre_isbn
        etat = emprunter_livre_isbn(ISBN, pBibli);

        Sleep(vitesse);

        switch (etat)
		{
            case LIVRE_EMPRUNTE:
                if(chariot_ajouter_livre(tete, temp_livre))
                {
                    trier(*tete);
                    printf("CHARIOT: Le livre \"%s\" a ete rajouter au chariot\n", temp_livre.titre);
                }
                break;
            case LIVRE_NON_DISPONIBLE: printf("CHARIOT: Le livre est non disponible\n"); break;
            case LIVRE_INTROUVABLE: printf("CHARIOT: Le livre est introuvable\n"); break;
		}

    }

    super_pause();
}


void chariot_emprunter_livre(int ISBN, t_bibliotheque * pBibli)
{
    emprunter_livre_isbn(ISBN, pBibli);
}


void chariot_retourner_livres(lien * tete, t_bibliotheque * pBibli)
{
    t_livre temp_livre;
    int isbn = 0;
    int vitesse = VITESSE_CHARIOT_DEFAUT;
    lien liste = *tete;

    vitesse = chariot_get_vitesse();

    vitesse *= MILISECONDES;

    while(liste != NULL)
    {
        isbn = liste->data.isbn;

        if(retourner_livre_isbn(isbn, pBibli))
        {
            //livre enlever du chariot, car il est de retour dans la bibliotheque
            temp_livre = chariot_retirer_livre(tete, isbn, pBibli);
            printf("CHARIOT: Le livre \"%s\" a ete enleve du chariot et remis a la bibliotheque\n", temp_livre.titre);
        }
        else
        {
            //le traitement n'a pas fonctionner
            printf("CHARIOT: Le livre avec le ISBN : \"%d\" n'a pu etre remis a la bibliotheque\n", isbn);
        }

        liste = *tete;
        Sleep(vitesse);
    }

    super_pause();
}


t_livre chariot_retirer_livre(lien * tete, int ISBN, t_bibliotheque * pBibli)
{
    t_livre temp_livre;

    //cherche le livre par le ISBN
    if(chercher_livre(ISBN, pBibli, &temp_livre))
    {
        //retire le livre du haut de la pile
        retire(tete, temp_livre);
    }

    return temp_livre;
}


int chariot_ajouter_livre(lien * tete, t_livre livre)
{
    return insere_au_debut(tete, livre);;
}


void chariot_set_vitesse(int vitesse)
{
    char * data[DATA];
    FILE * fichier_conf_chariot;

    fichier_conf_chariot = fopen(FICHIER_CONFIG_CHARIOT,"w+");

    if(fichier_conf_chariot == NULL)
    {
        printf("Erreur de lecture du fichier %s ... \n", FICHIER_CONFIG_CHARIOT);
    }
    else
    {
        itoa(vitesse, data, 10);
        fputs(data, fichier_conf_chariot);
        fclose(fichier_conf_chariot);
    }
}


int chariot_get_vitesse()
{
    int vitesse = VITESSE_CHARIOT_DEFAUT;
    char * data[DATA];
    FILE * fichier_conf_chariot;

    fichier_conf_chariot = fopen(FICHIER_CONFIG_CHARIOT,"r+");

    if(fichier_conf_chariot == NULL)
    {
        printf("Erreur de lecture du fichier %s ... \n", FICHIER_CONFIG_CHARIOT);
    }
    else
    {
        fgets(data, DATA, fichier_conf_chariot);
        vitesse = atoi(data);
    }

    return vitesse;
}


int chariot_get_pos()
{
    return POS_KIOSK;
}
