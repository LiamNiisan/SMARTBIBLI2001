//TO BE CONTINUED

#include "t_biblio_machine.c"


typedef struct {

    int no_etudiant;
    t_livre * livre_emprunter;

}t_etudiant;


void etudiant_servir(t_etudiant * etudiant);

void etudiant_chercher_livre();

void etudiant_retour_livre();

void etudiant_apporter_livre();

void etudiant_dossier();
