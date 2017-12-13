#include "t_biblio.h"
#include "t_chaine.h"
#include "t_pile.h"

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



int afficher_menu_kiosque(t_etudiant * etudiant);

void etudiant_servir(t_etudiant * etudiant, t_bibliotheque * bibli, lien * tete, t_pile * pile_robot);

void etudiant_apporter_livre(t_bibliotheque * biblio, lien * tete, t_etudiant * etudiant);

void etudiant_retour_livre(t_bibliotheque * biblio, t_pile * pile_robot);

void etudiant_chercher_livre(t_bibliotheque * biblio, lien * tete);

void etudiant_dossier(t_etudiant * etudiant);

void etudiant_random_test(t_etudiant * etudiant);

void afficher_livres_chariot(t_bibliotheque * biblio, lien * tete);

int afficher_menu_recherche();

void rechercher_livre(t_bibliotheque * biblio);

int afficher_menu_moteur_recherche();

void moteur_recherche(t_bibliotheque * biblio, int option);



#endif
