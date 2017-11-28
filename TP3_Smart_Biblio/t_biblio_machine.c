#include "t_biblio_machine.h"


void etudiant_random_test(t_etudiant * etudiant){

    srand((unsigned)time(0));

        int date=0;
        int id_etudiant=0;

        date = rand() %(DATE_MAX - DATE_MIN);
        date+=2000;
        etudiant->date_etude = date;



        id_etudiant = rand() % (ID_MAX - ID_MIN);
        etudiant->no_etudiant = id_etudiant;

        etudiant->livre_empreunter = 0;


         printf("Date d'inscription : %d\n",etudiant->date_etude);
         printf("Numero permanent de l'etudiant : %d\n",etudiant->no_etudiant);

}


void etudiant_servir(t_etudiant * etudiant, t_bibliotheque * biblio)
{
    int etudiant_id=0;


    printf("================================================================================\n");
	printf("                                Kiosque Biblio Virtuel\n");
	printf("================================================================================\n");

	etudiant_random_test(etudiant);
	printf("\n\n");

	do{
	printf("Entrez un numero d'etudiant valide : ");
	scanf("%d",&etudiant_id);
	}
	while(etudiant_id != etudiant->no_etudiant);


	printf("\n\nBonjour Etudiant No.%d - Comment puis-je vous aider aujourd'hui ?\n");
	printf("1. Chercher livre\n");
	printf("2. Retourner livre\n");
	printf("3. Apporter livre\n");
	printf("4. Voir Dossier de l'Etudiant\n\n");


    int choix=0;

    scanf("%d",&choix);

	switch(choix)
	{
	    case 1: etudiant_chercher_livre();break;
	    case 2: etudiant_retour_livre();break;
	    case 3: etudiant_apporter_livre();break;
	    case 4: etudiant_dossier(etudiant);break;
	    default : break;
	}


}



void etudiant_chercher_livre(){

    printf("To be continued...");

}

void etudiant_retour_livre(){

    printf("To be continued...");

}

void etudiant_apporter_livre(){

    printf("To be continued...");

}

void etudiant_dossier(t_etudiant * etudiant){

    printf("\n---Dossier---\n");
    printf("Date d'inscription : %d\n",etudiant->date_etude);
    printf("Numero permanent de l'etudiant : %d\n",etudiant->no_etudiant);
    printf("Nombre de livre empreunter : %d\n\n",etudiant->livre_empreunter);



}

