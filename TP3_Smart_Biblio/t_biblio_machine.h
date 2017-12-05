#include "t_biblio.h"

#ifndef _T_BIBLIO_MACHINE__
#define _T_BIBLIO_MACHINE__

#define ID_MAX 1000000
#define ID_MIN 1

#define DATE_MIN 2000
#define DATE_MAX 2017
#define MAX_LIVRE 5

typedef struct {

    int no_etudiant;
    int date_etude;
    int livre_empreunter;
    t_rapport * livre;

}t_etudiant;



int afficher_menu_kiosque();

void etudiant_servir(t_etudiant * etudiant, t_bibliotheque * bibli, t_livre * chariot_livres, int * nb_livres_chariot);

void etudiant_apporter_livre(t_bibliotheque * biblio, t_livre * chariot_livres, int * nb_livres_chariot);

void etudiant_retour_livre(t_bibliotheque * biblio);

void etudiant_chercher_livre(t_bibliotheque * biblio, t_livre chariot_livres[], int nb_livres_chariot);

void etudiant_dossier(t_etudiant * etudiant);

void etudiant_random_test(t_etudiant * etudiant);

void afficher_livres_chariot(t_bibliotheque * biblio, t_livre chariot_livres[], int nb_livres_chariot);

int afficher_menu_recherche();

#endif
