#include <stdio.h>
#include <stdlib.h>

#include "t_biblio.h"
#include "t_biblio_chariot.h"
#include "t_biblio_machine.h"
#include "t_biblio_robot.h"
#include "t_pile.h"


void remise_partielle(t_bibliotheque * pbiblio);


int main()
{
    t_etudiant etudiant;
    t_bibliotheque biblio;

    //menu fonctionelle avec generation d'un user random
    etudiant_servir(&etudiant,&biblio);
    //remise_partielle(&biblio);







    return 0;
}

void remise_partielle(t_bibliotheque * pbiblio){

    int lecturefichier=0; //verification de la lecture fichier

    initialiser_bibliotheque(&pbiblio);
    initialiser_rapport(&pbiblio);
    lire_fichier(&pbiblio,&lecturefichier);
    generer_rapport(&pbiblio);
    emprunter_livre(&pbiblio);
    generer_rapport(&pbiblio);


}
