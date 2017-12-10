#include "t_biblio_chariot.h"


t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, lien * tete)
{
    printf("\nCHARIOT: Chercher livre avec ISBN : %d \nVeuillez patienter...\n", ISBN);

    t_livre temp_livre;
    int etat = 0;

    if(chercher_livre(ISBN, pBibli, &temp_livre))
    {
        etat = emprunter_livre_isbn(ISBN, pBibli);

        switch (etat)
		{
            case LIVRE_EMPRUNTE:
                if(chariot_ajouter_livre(tete, temp_livre))
                {
                    trier(*tete);
                    printf("CHARIOT: Le livre \"%s\" a ete rajouter au chariot\n", temp_livre.titre);
                }
                break;
            case LIVRE_NON_DISPONIBLE: printf("CHARIOT: Le livre est non disponible"); break;
            case LIVRE_INTROUVABLE: printf("CHARIOT: Le livre est introuvable"); break;
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
    lien liste = *tete;

    while(liste != NULL)
    {
        isbn = liste->data.isbn;

        if(retourner_livre_isbn(isbn, pBibli))
        {
            temp_livre = chariot_retirer_livre(tete, isbn, pBibli);
            printf("CHARIOT: Le livre \"%s\" a ete enleve du chariot et remis a la bibliotheque\n", temp_livre.titre);
        }
        else
        {
            printf("CHARIOT: Le livre avec le ISBN : \"%d\" n'a pu etre remis a la bibliotheque\n", isbn);
        }

        liste = *tete;
    }

    super_pause();
}



t_livre chariot_retirer_livre(lien * tete, int ISBN, t_bibliotheque * pBibli)
{
    t_livre temp_livre;

    if(chercher_livre(ISBN, pBibli, &temp_livre))
    {
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
    printf("BOOM");
}
