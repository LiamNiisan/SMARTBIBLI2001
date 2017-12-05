#include "t_biblio.h"

#ifndef _T_BIBLIO_CHARIOT__
#define _T_BIBLIO_CHARIOT__

#define POS_KIOSK 0
#define POS_DEPLACEMENT 1


int chariot_ajouter_livre(t_livre livre);

void chariot_retirer_livre(int ISBN, t_bibliotheque * pBibli);

void chariot_emprunter_livre(int ISBN, t_bibliotheque * pBibli);

void chariot_retourner_livre(int ISBN, t_bibliotheque * pBibli);

int chariot_get_pos();

t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, t_livre * chariot_livres, int * compteur_nb_livre_chariot);

void chariot_get_vitesse(int vitesse);

int chariot_set_vitesse();

#endif

