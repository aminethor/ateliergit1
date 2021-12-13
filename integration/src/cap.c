#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "cap.h"


enum{
	EID,
	ETYPE,
	EMARQUE,
	EETAT,
	EDATE,
	EPRIX,
	EVALEUR,
	ECOLUMNS,
};
void ajouter_capteur(capteur c){
    FILE *f;
    f = fopen("capteur.txt","a");
    if(f!= NULL){
        fprintf(f,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,c.d.j,c.d.m,c.d.a,c.prix,c.valeur);
    }
    fclose(f);
}


/* ------------------------------------------------ */ 


void modifier_capteur(capteur y){
    capteur c;
    FILE *f;
    FILE *g;
    f = fopen("capteur.txt","r");
    g = fopen("tmp.txt","a");
    while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,&(c.d.j),&(c.d.m),&(c.d.a),&(c.prix),&(c.valeur)) != EOF){
        if(strcmp(c.id,y.id) != 0){
        	fprintf(g,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,c.d.j,c.d.m,c.d.a,c.prix,c.valeur);    
	}
        else{
            fprintf(g,"%s %s %s %s %d %d %d %d %d\n",y.id,y.type,y.marque,y.etat,y.d.j,y.d.m,y.d.a,y.prix,y.valeur);
	}
    }
    fclose(f);
    fclose(g);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");
}


/* ------------------------------------------------ */ 

void supprimer_capteur(char id[]){
    capteur c;
    FILE *f1;
    FILE *f2;
    f1 = fopen("capteur.txt","r");
    f2 = fopen("tmp.txt","a+");
    if(f1 != NULL && f2 != NULL){
        while(fscanf(f1,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,&(c.d.j),&(c.d.m),&(c.d.a),&(c.prix),&(c.valeur)) != EOF){
        	if(strcmp(c.id,id) != 0){
            fprintf(f2,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,c.d.j,c.d.m,c.d.a,c.prix,c.valeur);
        }
    }
    fclose(f1);
    fclose(f2);
    remove("capteur.txt");
    rename("tmp.txt","capteur.txt");
    }
}



/* ------------------------------------------------ */ 

capteur chercher_capteur(char id[]){
    capteur c;
    FILE *f;
    f = fopen("capteur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,&(c.d.j),&(c.d.m),&(c.d.a),&(c.prix),&(c.valeur)) != EOF){
        	if(strcmp(c.id,id) == 0){
       		     return c;
        	}
    	}
}
    fclose(f);
    return;
}
/* ------------------------------------------------ */ 
int idExiste(char id[]){
    capteur c;
    FILE *f;
    f = fopen("capteur.txt","r");
    if(f != NULL){
    	while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,&(c.d.j),&(c.d.m),&(c.d.a),&(c.prix),&(c.valeur)) != EOF){
        	if(strcmp(c.id,id) == 0){
       		     return 1;
        	}
    	}
}
    fclose(f);
    return 0;
}

/* -------------------------------------------------------- */ 

void afficher_capteur(GtkWidget *liste){
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
   
	capteur c;
	char date[30],valeur[20],prix[20];
    FILE *f;
    store = NULL;
    store = gtk_tree_view_get_model(liste);

    if(store == NULL){
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",EID,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Type",renderer,"text",ETYPE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Marque",renderer,"text",EMARQUE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Prix",renderer,"text",EPRIX,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Valeur",renderer,"text",EVALEUR,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Etat",renderer,"text",EETAT,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Date d'acquisition",renderer,"text",EDATE,NULL);
        column = gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

        

    }
	store = gtk_list_store_new(ECOLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
    
    
    	f = fopen("capteur.txt","r");
	if(f == NULL){
        	return;
    	}
	else{
        	while(fscanf(f,"%s %s %s %s %d %d %d %d %d\n",c.id,c.type,c.marque,c.etat,&(c.d.j),&(c.d.m),&(c.d.a),&(c.prix),&(c.valeur)) != EOF){
        	
			sprintf(valeur,"%d",c.valeur);
			sprintf(date,"%d/%d/%d",c.d.j,c.d.m,c.d.a); 
			sprintf(prix,"%d",c.prix);          		
			gtk_list_store_append(store,&iter);
            		gtk_list_store_set(store,&iter,EID,c.id,ETYPE,c.type,EMARQUE,c.marque,EPRIX,prix,EVALEUR,valeur,EETAT,c.etat,EDATE,date,-1);
            		
        	}
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		g_object_unref(store);
        	fclose(f);
    	}
    
}
