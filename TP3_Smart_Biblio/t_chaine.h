// Exemple de gestion d'une liste cha�n�e simple ordonn�e en ordre d�croissant
#include "lib.h"

#ifndef T_CHAINE_H_INCLUDED
#define T_CHAINE_H_INCLUDED

/********************************************************************/
/*********  D�clarations des types pour la liste cha�n�e  *********/

typedef t_livre        objet;
typedef struct noeud * lien;

struct noeud {
   objet data;
   lien  suivant;
};

/*********  D�clarations des fonctions de gestion de liste  *********/
void creer            (lien *);
void afficher         (lien);
void insere           (lien *, objet);
int insere_au_debut   (lien *, objet);
void insere_a_la_fin  (lien *, objet);
void retire           (lien *, objet);
void retire_du_debut  (lien *);
void retire_de_la_fin (lien *);
void trier(lien);



#endif

