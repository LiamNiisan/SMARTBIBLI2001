#include "t_biblio_chariot.h"
#include "t_biblio.h"



t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, t_livre * chariot_livres, int * compteur_nb_livre_chariot)
{
    printf("Chariot: Chercher livre avec ISBN : %d \nVeuillez patienter...", ISBN);

    //chariot_emprunter_livre(ISBN, pBibli);
    t_livre temp_livre;
    chercher_livre(ISBN, pBibli, &temp_livre);

    int chariot_position = *(compteur_nb_livre_chariot);
    chariot_livres = (t_livre *)malloc((chariot_position + 1) * sizeof(t_livre));
    chariot_livres[chariot_position] = temp_livre;

    super_pause();
}


void chariot_emprunter_livre(int ISBN, t_bibliotheque * pBibli)
{
    emprunter_livre_isbn(ISBN, pBibli);
}



void chariot_retourner_livre(int ISBN, t_bibliotheque * pBibli)
{
    printf("BOOM");
}



void chariot_retirer_livre(int ISBN, t_bibliotheque * pBibli)
{
    printf("BOOM");
}
