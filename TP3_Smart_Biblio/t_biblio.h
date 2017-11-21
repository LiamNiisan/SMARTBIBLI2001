



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
