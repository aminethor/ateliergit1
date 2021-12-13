#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ichrak.h"
#include<gtk/gtk.h>
char ch[100];
enum
{
  EJOUR,
  ETEMPS,
  EENTREE,
  EPLAT_PRINCIPALE,
  EDESSERT,
  COLUMNS,
};
menu m;
FILE *f;
void ajout_menu(menu m)
{
    FILE *f;
    f=fopen("menu.txt","a+");
    fprintf(f,"%s %s %s %s %s \n",m.jour,m.temps,m.menu.entree,m.menu.plat_principale,m.menu.dessert); 
    fclose(f);
}
void afficher(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char jour[20];
char temps[20];
char entree[50];
char plat_principale[50];
char dessert[50];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text", EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("temps",renderer,"text",ETEMPS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree",renderer,"text",EENTREE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("plat_principale",renderer,"text", EPLAT_PRINCIPALE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert",renderer,"text", EDESSERT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING);
f=fopen("menu.txt","r");  
if(f==NULL)
{
return;
}
else
{
f= fopen("menu.txt","a+");     
while (fscanf(f,"%s %s %s %s %s \n",jour,temps,entree,plat_principale,dessert)!=EOF)  
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EJOUR,jour,ETEMPS,temps,EENTREE,entree,EPLAT_PRINCIPALE,plat_principale,EDESSERT,dessert,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}
void afficher1(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
char jour[20];
char temps[20];
char entree[50];
char plat_principale[50];
char dessert[50];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text", EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("temps",renderer,"text",ETEMPS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("entree",renderer,"text",EENTREE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("plat_principale",renderer,"text", EPLAT_PRINCIPALE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("dessert",renderer,"text", EDESSERT, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 
store = gtk_list_store_new(COLUMNS,G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_STRING,
				     G_TYPE_STRING);
f=fopen("rech2.txt","r");  
if(f==NULL)
{
return;
}
else
{
f= fopen("rech2.txt","a+");     
while (fscanf(f,"%s %s %s %s %s \n",jour,temps,entree,plat_principale,dessert)!=EOF)  
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EJOUR,jour,ETEMPS,temps,EENTREE,entree,EPLAT_PRINCIPALE,plat_principale,EDESSERT,dessert,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
}

void supprimer_menu(menu m)
    {
char jour[20];
char temps[20];
char entree[50];
char plat_principale[50];
char dessert[50];
        FILE *f=NULL;
        FILE *s=NULL;
        f=fopen("menu.txt","r");
        s=fopen("sup.txt","w");
	if(f==NULL )
{
return;
}
else
{
while(fscanf(f,"%s %s %s %s %s\n",jour,temps,entree,plat_principale,dessert)!=EOF)
{
if((strcmp(m.jour,jour)!=0) ||(strcmp(m.temps,temps)!=0)||(strcmp(m.menu.entree,entree)!=0)||(strcmp(m.menu.plat_principale,plat_principale)!=0)||(strcmp(m.menu.dessert,dessert)!=0))
fprintf(s,"%s %s %s %s %s \n",jour,temps,entree,plat_principale,dessert);
}
fclose(f);
fclose(s);
remove("menu.txt");
rename("sup.txt","menu.txt");
}
}



 
void vider (GtkWidget *liste)
{
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store ;
	char jour[20];
	char temps[20];
	char entree[50];
	char plat_principale[50];
	char dessert[50];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",jour,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("temps",renderer,"text",temps,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("entree",renderer,"text",entree,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("plat_principale",renderer,"text",plat_principale,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("dessert",renderer,"text",dessert,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
	}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

gtk_list_store_append(store,&iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);

}

/*menu rechercher_menu(char jour[],char temps[])
    {
        FILE *f=NULL;

        menu m={"",0,{"","",""},0};
        char ch1[200],ch2[200],ch3[200],ch4[200],ch5[200];
        f=fopen("menu.txt","r");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %s %s %s %s \n",&ch1,ch2,ch3,ch4,&ch5)!=EOF)


                if (strcmp(ch1,jour)==0&&strcmp(ch2,temps)==0)
                {
                    strcpy(m.jour,ch1);
                    strcpy(m.temps,ch2);
                    strcpy(m.menu.entree,ch3);
                    strcpy(m.menu.plat_principale,ch4);
                    strcpy(m.menu.dessert,ch5);
                   
            }
        }
         fclose(f);

         return m;

    }*/
void rechercher_menu2(char temps[])
{
FILE *f=NULL;
        FILE *s=NULL;
        char ch2[200],ch3[200],ch4[200],ch5[200],ch1[200];
        int a,b,c,x;
        f=fopen("menu.txt","r");
        s=fopen("rech2.txt","w");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
            {
if ( strcmp(temps,ch1)==0)
{
                    fprintf(s,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5);
}
            }
        }

        fclose(f);
        fclose(s);
}
void meilleur_menu(char meill11[],char meill13[],char meill21[],char meill23[],char meill31[],char meill33[])
    {
        FILE *f=NULL;
	FILE *meill=NULL;
        int a,c,b,j1,j2,m1,m2,m3,j3,cmp1=1000,cmp3=1000,cmp2=1000;
       f=fopen("dechets.txt","r");
        if (f!=NULL)
            while(fscanf(f,"%d %d %d \n",&a,&b,&c)!=EOF)
            {
printf("%d",c);

                 if((cmp1>c)&&(b==1))
                 {
                    cmp1=c;
                    j1=a;
                    m1=b;
                 }
		 if((cmp2>c)&&(b==2))
                 {
                    cmp2=c;
                    j2=a;
                    m2=b;
                 }
		 if((cmp3>c)&&(b==3))
                 {
                    cmp3=c;
                    j3=a;
                    m3=b;
                 }
            }
	
       
	sprintf(meill11,"%d",j1);
	sprintf(meill13,"%d",cmp1);
	sprintf(meill21,"%d",j2);
	sprintf(meill23,"%d",cmp2);
	sprintf(meill31,"%d",j3);
	sprintf(meill33,"%d",cmp3);
 }
void modifier_menu(menu m)
{
FILE *f=NULL;
        FILE *s=NULL;
        char ch2[200],ch3[200],ch4[200],ch5[200],ch1[200];
        int a,b,c,x,test=0;
        f=fopen("menu.txt","r");
        s=fopen("sup.txt","a");
        if(f!=NULL)
        {
            while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
            {
if (strcmp(m.jour,ch1)!=0||strcmp(m.temps,ch2)!=0)
{
                    fprintf(s,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5);
}
else
{
 test=1;
fprintf(s,"%s %s %s %s %s \n",ch1,ch2,m.menu.entree,m.menu.plat_principale,m.menu.dessert);
}

            }
        }

        fclose(f);
        fclose(s);
        remove("menu.txt");
        rename("sup.txt","menu.txt");
if (test==0)
{
printf("le menu n'existe pas\n");
}
    }

int controle(char chjour[],char chtemps[])
{
int x=0;
menu m;
FILE *f;
f=fopen("menu.txt","r");
do
{
fscanf(f,"%s %s %s %s %s \n",m.jour,m.temps,m.menu.entree,m.menu.plat_principale,m.menu.dessert);
if(strcmp(m.jour,chjour)==0 && strcmp(m.temps,chtemps)==0)
{x=1;
}
} 
while(!feof(f));
fclose(f);
return x;
}

menu chercher_menu(char chjour[],char chtemps[])
{
menu m;
FILE *f;
f=fopen("menu.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",m.jour,m.temps,m.menu.entree,m.menu.plat_principale,m.menu.dessert)!=EOF)
{
if (strcmp(chjour,m.jour)==0 && strcmp(chtemps,m.temps)==0)
{
return m;
}
}
}
fclose(f);
}

void meilleur_menu1(char text1[],char text2[],char text3[],char text4[])
{  
   int min1,min2,min3,min4;
    int posMin1=0,posMin2=0,posMin3=0,posMin4=0;
    int i;

    FILE *f;
    f= fopen("dechets.txt","r");  

char c;
int nbs=0;
while((c=fgetc(f))!=EOF)
if (c == '\n')
nbs++;
fseek(f,0,SEEK_SET);
dechet * d = malloc(nbs*sizeof(dechet));

if(f != NULL )
    {  
for (int i=0;i<nbs;i++)
{
    fscanf(f,"%d %d %f \n",&d[i].jd,&d[i].td,&d[i].kgd);
}
         min1=d[0].kgd;
         for (int i=1;i<8;i++)
         {
            if (d[i].kgd < min1 )
            {
            min1 = d[i].kgd;
    posMin1=i;
            }
          }
         min2=d[7].kgd;
  for (int i=8;i<16;i++)
         {
            if (d[i].kgd < min2 )
            {
            min2 = d[i].kgd;
    posMin2=i;
            }
          }
         min3=d[15].kgd;
for (int i=16;i<22;i++)
         {
            if (d[i].kgd < min3 )
            {
            min3 = d[i].kgd;
    posMin3=i;
            }
          }
         min4=d[21].kgd;
for (int i=22;i<29;i++)
         {
            if (d[i].kgd < min4 )
            {
            min4 = d[i].kgd;
    posMin4=i;
            }
          }
sprintf(text1,"le meilleur menu de la 1ére semaine est dans le jours %d et du dechets %f",d[posMin1].jd,d[posMin1].kgd);
sprintf(text2,"le meilleur menu de la 2éme semaine est dans le jours %d et du dechets %f",d[posMin2].jd,d[posMin2].kgd);
sprintf(text3,"le meilleur menu de la 3éme semaine est dans le jours %d et du dechets %f",d[posMin3].jd,d[posMin3].kgd);
sprintf(text4,"le meilleur menu de la 4éme semaine est dans le jours %d et du dechets %f",d[posMin4].jd,d[posMin4].kgd);

     }
    fclose(f);
}



























