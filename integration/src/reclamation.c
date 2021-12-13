#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include <gtk/gtk.h>


void ajouterrec(reclamation t)
{

 FILE *fa;
  fa=fopen("bloc.txt","a+");
  if(fa!=NULL) 
  {
  fprintf(fa,"%s %s %s %d/%d/%d  \n",t.id,t.type,t.reclamation,t.date.jour,t.date.mois,t.date.annee);
  fclose(fa);
}

}


enum   
{       
        EID,
	ETYPE,
	ERECLAMATION,
        EDATE,
     
        COLUMNS
};
void afficherrec(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;
        char id [30];
        char type [30];
	char reclamation [30];
        char date[30] ;
        
        store=NULL;
       FILE *f;
	store=gtk_tree_view_get_model(liste);	
	if (store==NULL)
	{

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id", renderer, "text",EID,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" type ", renderer, "text",ETYPE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" reclamation ", renderer, "text",ERECLAMATION, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);	

	
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("  date", renderer, "text",EDATE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		
               
	
	}

	
	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("bloc.txt", "r");
	
	if(f==NULL)
	{

		return;
	}		
	else 

	{ f = fopen("bloc.txt", "a+");
              while(fscanf(f," %s %s %s %s  \n",id,type,reclamation,date)!=EOF)
		{
	gtk_list_store_append (store, &iter);
	gtk_list_store_set (store, &iter, EID, id, ETYPE, type, ERECLAMATION, reclamation, EDATE, date, -1);
		}
		fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste),  GTK_TREE_MODEL (store));
    g_object_unref (store);
	}
}

void supprimerrec(char idd[])
{

reclamation t;

FILE*fa;
FILE*ffact;

char date[50];
char type[50];
char id[50];
char reclamation[50];



fa = fopen("bloc.txt","r");
ffact = fopen("bloc2.txt","w+");


while (fscanf(fa,"%s %s %s %s  \n",t.id,t.type,t.reclamation,date)!=EOF)
 {

            if(strcmp(t.id,idd)!=0)
            {
                fprintf(ffact,"%s %s %s %s  \n",t.id,t.type,t.reclamation,date);
                
        }
        


    }

    fclose(ffact);
    fclose(fa);

     remove("bloc.txt");
     rename("bloc2.txt","bloc.txt");
}



void modifierrec(  char idd[], char typee[], char reclamationn[], char date1[] )
   {
reclamation t;

FILE*fa;
FILE*ffact;

char date[50];
char type[50];
char id[50];
char reclamation[50];



fa = fopen("bloc.txt","r");
ffact = fopen("bloc2.txt","w+");


while (fscanf(fa,"%s %s %s %s  \n",t.id,t.type,t.reclamation,date)!=EOF)
 {

            if(strcmp(t.id,idd)!=0)
            {
                fprintf(ffact,"%s %s %s %s  \n",t.id,t.type,t.reclamation,date);
            }
	else  
	   {
		fprintf(ffact,"%s %s %s %s  \n",t.id,typee,reclamationn,date1);
	   }

    }

    fclose(ffact);
    fclose(fa);

     remove("bloc.txt");
     rename("bloc2.txt","bloc.txt");
}








int  service_plus_reclame()
{
    FILE *f=NULL;
    f=fopen("bloc.txt","r");
     char id[50];
     char recl[50];
     char typ[50];
     int jour,mois,annee;
      int   nb0=0,nb1=0;
    if (f!=NULL)
    {

        while(fscanf(f,"%s %s %s %d/%d/%d \n",recl,typ,id,&jour,&mois,&annee)!=EOF)

{
       if (strcmp(typ,"FOYER")==0)
       { printf("%s \n",typ);
         nb0++;}

         else 
         if(strcmp(typ,"RESTAURANT")==0)
         { printf("%s \n",typ);
            
            nb1++;
}


    }



} printf("%d \n",nb0);
printf("%d \n",nb1);
if (nb0>nb1)
   

    
    return 0; 

else
   if (nb0<nb1)

 
    return 1; 
    
    else 
    return 2;


    }






int idexistee(char idnada[])
{ reclamation rec;
  FILE *f;
  int res;
  f=fopen("bloc.txt","r");
  
  if (f!=NULL)
  { while (fscanf(f,"%s %s %s %d/%d/%d \n",rec.id,rec.type,rec.reclamation,&(rec.date.jour),&(rec.date.mois),&(rec.date.annee))!=EOF)
  {
  if (strcmp(rec.id,idnada)==0)
  {return 1;}

}}
fclose(f);
return 0;
}















