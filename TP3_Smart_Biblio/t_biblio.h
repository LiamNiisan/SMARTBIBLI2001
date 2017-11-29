#ifndef _T_BIBLIO__
#define _T_BIBLIO__


#define NB_LIVRES_MAX_RANGEE        100
#define NB_GENRES                   6
#define BIBLIO_FICHIER				"biblio.txt"

#define TAILLE_TITRE	80
#define TAILLE_NOM		30
#define TAILLE_PRENOM	30


#define MAX_ISBN		9999

#define SIMULATION      1

#define EMPRUNT         1
#define DISPONIBLE      0

typedef enum { AUCUN = 0, FICTION = 1, HISTOIRE = 2, SCIENCE = 3, ENFANTS = 4, INFORMATIQUE = 5 } t_genre;

typedef struct
{
	int nb_livres_dispo;
	int nb_livres_emprunt;
} t_rapport;



typedef struct
{
	t_genre genre;
	int nb_pages;
	char auteur_prenom[TAILLE_PRENOM];
	char auteur_nom[TAILLE_NOM];
	char titre[TAILLE_TITRE];
	int isbn;
	int bEmprunte; // 1: Le livre a ete emprunte, 0: le livre est disponible.
} t_livre;



typedef struct
{
	t_livre livres[NB_GENRES][NB_LIVRES_MAX_RANGEE];
	int nb_livres[NB_GENRES];
	//t_pile retours;
	t_rapport rapport;
} t_bibliotheque;





void initialiser_bibliotheque(t_bibliotheque * pBibli);

void initialiser_rapport(t_bibliotheque * pBibli);

void generer_rapport(t_bibliotheque * pBibli);

int verifier_disp_bibliotheque(t_bibliotheque * pBibli);

void lire_fichier(t_bibliotheque * pBibli, int * lecture);

void emprunter_livre(t_bibliotheque * pBibli);

void retirer_sautligne(char * chaine);

void super_pause();



#endif


