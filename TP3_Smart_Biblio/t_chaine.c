// Exemple de gestion d'une liste cha�n�e simple

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define  MAX  10

/********************************************************************/
/*					            DEFINITION DES TYPES						            */
/********************************************************************/

typedef int            objet;
typedef struct noeud * lien;

struct noeud {
   objet data;
   lien  suivant;
};

/********************************************************************/
/*          D�clarations des fonctions de gestion de liste          */
/********************************************************************/

   void ajouter(lien *, lien *, objet);
   int  retire_le_i(const lien *, int, objet *);
   void retire_du_debut(lien *);

/********************************************************************/
/*					           	PROGRAMME PRINCIPAL 					             	*/
/********************************************************************/

int main(void)
{  lien  tete=NULL, fin;  //pointeur sur la tete et la fin de la liste
   int   nbelem=0,        //nombre d'�l�ments de la liste
		     i, valeur;

   srand(time(NULL));

	 //remplir la liste al�atoirement
	 for (i=0; i<MAX; i++){
		 valeur = rand() % 100;
		 ajouter(&tete, &fin, valeur);
     nbelem++;
	 }

	 //afficher la liste
   for (i=0; i<nbelem; i++){
     retire_le_i(&tete, i, &valeur);
		 printf("%d --> ", valeur);
	 }
	 printf("NULL\n");

   //tester quelques requ�tes
	 if (retire_le_i(&tete, 6, &valeur))
		 printf("\nLe #6 est %d\n", valeur);

   if (retire_le_i(&tete, 11, &valeur))
		 printf("\nLe #11 est %d\n", valeur);

	 //effacer la liste
	 while (nbelem){
     retire_du_debut(&tete);
		 nbelem--;
	 }

	 system("pause");
	 return 0;
}

/********************************************************************/
/*						         DEFINITION DES FONCTIONS				            	*/
/********************************************************************/

/********************************************************************/
//Fonction qui cr�e un nouveau noeud avec la valeur "x" et qui va
//placer ce noeud � la fin de la liste re�ue en param�tre
void ajouter(lien *tete, lien *fin, objet x)
{ lien p, q;

  p = (lien) malloc(sizeof(struct noeud));
  if (p == NULL)  return;   //valider l'allocation dynamique

  p->data = x;
  if (*tete == NULL) {   //si la liste re�ue est vide..
     *tete = *fin = p;     //ce premier noeud est la tete ET la fin de liste
     p->suivant = NULL;
  }
  else {                 //sinon, on va ajouter � la fin
     q = *fin;

     p->suivant = NULL;
     q->suivant = p;
		 *fin = p;           //d�placer la fin de liste
  }
}


/********************************************************************/
//Fonction qui enl�ve le PREMIER noeud de la liste re�ue en parametre
void retire_du_debut(lien *tete)
{ lien p= *tete;

  if (*tete != NULL) {
     *tete = p->suivant;
     free(p);
  }
}


/********************************************************************/
//Fonction qui r�cup�re la valeur du noeud #n de la liste
int retire_le_i(const lien *tete, int n, objet *val)
{ lien ici = *tete;  //pointeur temporaire pour traverser la liste
  int  no=0;

	if (ici == NULL){
		printf("\nOn ne peut pas retirer l'objet #%d: la liste est vide\n\n", n);
		return 0;
	}
  else {
    /* Boucle pour retrouver la valeur #n dans la liste */
    while ((ici != NULL) && (no < n)) {
      ici = ici->suivant;
			no++;
    }
		if (ici == NULL){
       printf("\nIl n'y a pas d'item numero %d !!!\n\n", n);
       return 0;
		}
    else {
	     *val = ici->data;  //on r�cup�re cette valeur
			 return 1;
    }
  }
}

