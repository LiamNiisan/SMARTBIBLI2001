//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include "t_biblio_chariot.h"

/******************************************************************************
// chariot_apporter_livre
// ****************************************************************************
//
// Cette fonction permet au chariot d'aller chercher un livre dans la biblio.
// Verifie si le livre exite et s'il est disponible a l'emprunt.
//
// Paramètres 	: int ISBN, t_bibliotheque * pBibli, lien * tete
// Retour 		: t_livre
//*****************************************************************************/

t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, lien * tete)
{
    printf("\nCHARIOT: Chercher livre avec ISBN : %d \nVeuillez patienter...\n", ISBN);

    t_livre temp_livre;
    int etat = 0;

    if(chercher_livre(ISBN, pBibli, &temp_livre))
    {
        //etat obtien la valeur de retour de emprunter_livre_isbn
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

/******************************************************************************
// chariot_emprunter_livre
// ****************************************************************************
//
// permet de prendre le livre de la bibliotheque avec le ISBN.
//
// Paramètres 	: int ISBN, t_bibliotheque * pBibli
// Retour 		: void
//*****************************************************************************/

void chariot_emprunter_livre(int ISBN, t_bibliotheque * pBibli)
{
    emprunter_livre_isbn(ISBN, pBibli);
}

/******************************************************************************
// chariot_retourner_livres
// ****************************************************************************
//
// Cette fonction permet de retourner les livres du chariot a la bibliotheque
//
// Paramètres 	: lien * tete, t_bibliotheque * pBibli
// Retour 		: void
//*****************************************************************************/

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
    }

    super_pause();
}


/******************************************************************************
// chariot_retirer_livre
// ****************************************************************************
//
// Cette fonction permet de retirer un livre qui se trouve dans le chariot
//
// Paramètres 	: lien * tete, int ISBN, t_bibliotheque * pBibli
// Retour 		: t_livre
//*****************************************************************************/

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

/******************************************************************************
// chariot_ajouter_livre
// ****************************************************************************
//
// Cette fonction permet d'ajouter un livre sur la pile de livre du chariot
//
// Paramètres 	: lien * tete, t_livre livre
// Retour 		: int
//*****************************************************************************/

int chariot_ajouter_livre(lien * tete, t_livre livre)
{
    return insere_au_debut(tete, livre);;
}

/******************************************************************************
// chariot_set_vitesse
// ****************************************************************************
//
// Cette fonction permet de changer la vitesse d'execution du chariot. Cette
// influencera le temps de ceuillette a la bibliotheque
//
// Paramètres 	: int vitesse
// Retour 		: void
//*****************************************************************************/

void chariot_set_vitesse(int vitesse)
{
    printf("BOOM");
}
