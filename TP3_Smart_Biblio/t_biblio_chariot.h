#include "lib.h"


#ifndef T_BIBLIO_CHARIOT_H_INCLUDED
#define T_BIBLIO_CHARIOT_H_INCLUDED

#define POS_KIOSK 0
#define POS_DEPLACEMENT 1


int chariot_ajouter_livre(lien * tete, t_livre livre);

t_livre chariot_retirer_livre(lien * tete, int ISBN, t_bibliotheque * pBibli);

void chariot_emprunter_livre(int ISBN, t_bibliotheque * pBibli);

void chariot_retourner_livres(lien * tete, t_bibliotheque * pBibli);

int chariot_get_pos();

t_livre chariot_apporter_livre(int ISBN, t_bibliotheque * pBibli, lien * tete);

void chariot_set_vitesse(int vitesse);

int chariot_get_vitesse();

#endif

