#include <gtk/gtk.h>
typedef struct
{

        int jour;
	int mois;
	int annee;


}date_de_validite;


typedef struct
{
	char id [30];
        char reclamation [30];
        char type [30];
	
	date_de_validite date;


}reclamation;



void ajouterrec(reclamation t);
void afficherrec(GtkWidget *liste);
void modifierrec(  char id[], char typee[], char reclamationn[], char date1[] );
void supprimerrec(char id[]);
int  service_plus_reclame();
int idexistee(char id[]);
