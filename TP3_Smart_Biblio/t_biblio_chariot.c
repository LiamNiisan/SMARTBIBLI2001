#include "t_biblio_chariot.h"
#include "t_biblio.h"



t_livre chariot_apporter_livre(int ISBN)
{
    printf("Chariot: Chercher livre avec ISBN : %d \nVeuillez patienter...", ISBN);

    chariot_emprunter_livre(ISBN);

    t_livre temp_livre = chercher_livre(ISBN);

}


void chariot_emprunter_livre(int ISBN)
{
    emprunter_livre(ISBN);
}



void chariot_retourner_livre(int ISBN)
{
    printf("BOOM");
}



void chariot_retirer_livre(int ISBN)
{
    printf("BOOM");
}
