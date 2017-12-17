//TP3 idee originale de Yannick Roy
//Realiser par Badr Jaidi & Felix-Olivier Moreau
//Pour le cours ING145

#include "t_chaine.h"


/********************************************************************/
/*					           	PROGRAMME PRINCIPAL 					             	*/
/********************************************************************/

/*int main(void)
{  lien  tete;    //pointeur sur la tete de la liste

   creer(&tete);                  afficher(tete);  getch();
   insere_au_debut(&tete, 75);    afficher(tete);  getch();
   insere_a_la_fin(&tete,  5);    afficher(tete);  getch();
   insere(&tete, 25);             afficher(tete);  getch();
   retire(&tete, 40);             afficher(tete);  getch();
   retire(&tete, 41);             afficher(tete);  getch();
   retire_du_debut(&tete);        afficher(tete);  getch();
   retire_de_la_fin(&tete);       afficher(tete);  getch();
   trier(tete);                   afficher(tete);  getch();
   return 0;
}*/

/********************************************************************/
/*						         DEFINITION DES FONCTIONS				            	*/
/********************************************************************/

//Fonction qui va créer la liste suivante: 50 --> 40 --> 30 --> 20 --> 10 --> NULL
void creer(lien *tete)
{
    lien p;
    p = NULL;
}

/********************************************************************/
//Fonction qui va compter le nombre d'éléments dans la liste chaînée
int compte(lien tete)
{  lien p=tete;
   int  n=0;

   while (p != NULL) {
	   n++;
	   p = p->suivant;
   }
   return n;
}

/********************************************************************/
//Fonction qui va afficher le contenu de la liste
void afficher(lien tete)
{
   lien p=tete;
   while (p != NULL) {
	   printf("-------------------------------\n");
       printf("Titre: %s \n",     p->data.titre);
       printf("Auteur: %s %s \n", p->data.auteur_prenom, p->data.auteur_nom);
       printf("Genre: %d \n",     p->data.genre);
       printf("Pages: %d \n",     p->data.nb_pages);
       printf("ISBN: %d \n",      p->data.isbn);
       printf("-------------------------------\n");
	   p = p->suivant;
   }
   printf("\n\nLe chariot contient %d livre(s)\n\n\n", compte(tete));
}

/********************************************************************/
//Fonction qui crée un nouveau noeud avec la valeur "x" et qui va
//placer ce noeud DEVANT la tete de liste reçue en paramètre
int insere_au_debut(lien *tete, objet x)
{ lien p;

  p = (lien) malloc(sizeof(struct noeud));
  if (p == NULL)  return NULL;   //valider l'allocation dynamique

  p->data    = x;
  p->suivant = *tete;
  *tete      = p;

  return 1;
}

/********************************************************************/
//Fonction qui crée un nouveau noeud avec la valeur "x" et qui va
//placer ce noeud à la fin de la liste reçue en paramètre
void insere_a_la_fin(lien *tete, objet x)
{ lien p, q;

  p = (lien) malloc(sizeof(struct noeud));
  if (p == NULL)  return;   //valider l'allocation dynamique

  p->data = x;
  if (*tete == NULL) {   //si la liste reçue est vide..
     *tete       = p;
     p->suivant = NULL;
  }
  else {                 //sinon, on va ajouter à la fin
     q = *tete;
     while (q->suivant != NULL)  //boucle pour aller jusqu'au DERNIER noeud
	     q = q->suivant;

     p->suivant = NULL;
     q->suivant = p;
  }
}

/********************************************************************/
//Fonction qui insérer un nouveau noeud avec la valeur "x" dans la
//liste reçue en paramètre de façon à ce que cette liste reste
//ordonnée en ordre DÉCROISSANT
void insere(lien *tete, objet x)
{ lien  ici, next, p;

  p = (lien) malloc(sizeof(struct noeud));
  if (p == NULL)  return;   //valider l'allocation dynamique

  p->data = x;
  ici = NULL;
  next = *tete;
  while ((next != NULL) && (next->data.isbn > x.isbn)) {  //trouver position oû on va insérer
    ici = next;
    next = next->suivant;
  }

  if (ici == NULL) {      //on va insérer au début d la liste
    p->suivant = *tete;
    *tete = p;
  }
  else {                  //sinon, on insère dans la liste
    p->suivant = ici->suivant;
    ici->suivant = p;
  }
}

/********************************************************************/
//Fonction qui enlève le PREMIER noeud de la liste reçue en parametre
void retire_du_debut(lien *tete)
{ lien p= *tete;
  if (*tete != NULL)
	{ *tete = p->suivant;  free(p); }
}


/********************************************************************/
//Fonction qui enlève le noeud de la liste qui contient la valeur "n"
void retire(lien *tete, objet n)
{ lien ici= *tete, avant=NULL;

  if (ici == NULL)
    printf("\nOn ne peut pas retire l'objet %d: la liste est vide\n\n", n);
  else {
    /* Boucle pour retrouver la valeur "n" dans la liste */
    while ((ici != NULL) && (ici->data.isbn != n.isbn)) {
      avant = ici;
      ici = ici->suivant;
    }

    if (ici == NULL)
       printf("\nERREUR:Il n'y a pas de livre avec le ISBN : %d !!!\n\n", n.isbn);
    else {
	   //Rétablir les liens avant de détruire ce noeud..
       if (ici == *tete) *tete = ici->suivant;
       else     avant->suivant = ici->suivant;
       free(ici);
    }
  }
}

/********************************************************************/
//Fonction qui enlève le DERNIER noeud de la liste reçue en parametre
void retire_de_la_fin(lien *tete)
{ lien ici= *tete, avant=NULL;

  if (ici == NULL)
    printf("\nOn ne peut pas retire d'objet: la liste est vide\n\n");
  else {
    while (ici->suivant != NULL) {  //trouver le DERNIER noeud
      avant = ici;
      ici = ici->suivant;
    }

    if (ici == *tete) *tete = NULL;
    else     avant->suivant = NULL;
    free(ici);
  }
}

/********************************************************************/
//Fonction qui échange deux valeurs (pour le tri)
void permute(objet *a, objet *b){
  objet temp=*a;
  *a = *b; *b = temp;
}

/********************************************************************/
//Fonction qui va trier une liste chaînée avec l'algorithme
//du Tri par Sélection.
//PARAMETRE:  liste - pointeur vers la liste à trier
void trier(lien liste){
  lien p=liste, q, min;   /* "p" pointe sur le premier noeud */

  while (p->suivant != NULL) {    /* on ira jusqu'au dernier noeud */
    q = p->suivant;
    min = p;

    /* boucle pour trouver la valeur minimale du reste de la liste */
    while (q != NULL) {
      if (q->data.isbn < min->data.isbn) min = q;
      q = q->suivant;
    }

    /* On échange ce minimum avec le .data du noeud pointé par "p" */
    permute(&p->data, &min->data);
    p = p->suivant;     /* on passe au noeud suivant.. */
  }
}
/********************************************************************/
/********************************************************************/
