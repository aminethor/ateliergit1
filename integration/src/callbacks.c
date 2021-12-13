#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction_etudiant.h"
#include "reclamation.h"
#include <stdio.h>
#include <string.h>
#include "ichrak.h"
#include "talbi.h"
#include "cap.h"
#include "fonction.h"
int n,nada;
int xx,z;
int x1=1,y1=1;
char ch[100];
menu me;
int t[2]={0,0,0};
int h;
int to[3]={0,0,0};
int xo=1;
/////////////////////////login/////////////////
void
on_button_login_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *user,*pass,*info1,*info2,*info3,*info4,*info5,*info6,*info7,*window1,*window2,*window3,*window4,*window5,*window6,*treeview15;
char username[20];
char password[20];
user= lookup_widget(button,"entry_login_username");
pass= lookup_widget(button,"entry_login_password");
strcpy(username,gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass)));
if ((strcmp(username,"amine")==0)&&(strcmp(password,"amine")==0))
{
info1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Role identifié: admin \n redirection vers espace admin");
switch (gtk_dialog_run(GTK_DIALOG(info1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info1);
window1=create_Gestion();
gtk_widget_show(window1);
GtkWidget *tous;
    tous=lookup_widget(button,"login");
    gtk_widget_destroy(tous);

////////////////////////////////////////////////////////////
break;

}
}
else if ((strcmp(username,"fedi")==0)&&(strcmp(password,"fedi")==0))
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Role identifié: agent foyer \n redirection vers espace hebergement");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
window2=create_window_etudiant();
gtk_widget_show(window2);
treeview15=lookup_widget(window2,"treeview1");
afficher_etudiant(treeview15);
GtkWidget *tous;
    tous=lookup_widget(button,"login");
    gtk_widget_destroy(tous);
////////////////////////////////////////////////////////////yallllllllllla
break;

}
}
else if ((strcmp(username,"chahine")==0)&&(strcmp(password,"chahine")==0))
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Role identifié: technicien \n redirection vers espace capteur");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
window3=create_tech();
gtk_widget_show(window3);
GtkWidget *tous;
    tous=lookup_widget(button,"login");
    gtk_widget_destroy(tous);
////////////////////////////////////////////////////////////
break;

}
}
else if ((strcmp(username,"nada")==0)&&(strcmp(password,"nada")==0))
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Role identifié: reclamation \n redirection vers service reclamation");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
window4=create_choisir();
gtk_widget_show(window4);
GtkWidget *tous;
    tous=lookup_widget(button,"login");
    gtk_widget_destroy(tous);
////////////////////////////////////////////////////////////
break;

}
}
else if ((strcmp(username,"hela")==0)&&(strcmp(password,"hela")==0))
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Role identifié: stock \n redirection vers espace stock");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
window5=create_menu();
gtk_widget_show(window5);
GtkWidget *tous;
    tous=lookup_widget(button,"login");
    gtk_widget_destroy(tous);
////////////////////////////////////////////////////////////
break;

}
}
else if ((strcmp(username,"ichrak")==0)&&(strcmp(password,"ichrak")==0))
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Role identifié: nutritionniste \n redirection vers espace nutritionniste");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
window6=create_window1menu();
gtk_widget_show(window6);
GtkWidget *tous;
    tous=lookup_widget(button,"login");
    gtk_widget_destroy(tous);
////////////////////////////////////////////////////////////
break;

}
}
else 
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"verifier votre saisie ");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
////////////////////////////////////////////////////////////
break;

}
}
}

///////////////////fedi////////////////////////////////////////////////////////////////////////
void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
///////////////////////
etudiant e;
GtkTreeIter iter;
gchar* id;
gchar* cin;
gchar* nom;
gchar* prenom;
gchar* sexe;
gchar* email;
gchar* tel;

gint* etage;

gint* chambre;

gint* jours;
gint* mois;
gint* annee;
gchar* classe;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id,1, &cin, 2, &nom, 3, &prenom, 4, &sexe, 5 ,&email, 6, &tel, 7 , &etage, 8 , &chambre, 9 , &jours, 10 , &mois, 11 , &annee, 12 , &classe, -1);
strcpy(e.id,id);
strcpy(e.cin,cin);

strcpy(e.nom,nom);
strcpy(e.prenom,prenom);
strcpy(e.classe,classe);
strcpy(e.sexe,sexe);
strcpy(e.email,email);
strcpy(e.tel,tel);
e.chambre=chambre;
e.etage=etage;
e.dn.jours=jours;
e.dn.mois=mois;
e.dn.annee=annee;
supprimer_etudiant(e);

afficher_etudiant(treeview);
/*FILE *f;
f=fopen("tmp2.txt","a+");
fprintf(f,"%s %s %s %s %d %d %d %s \n",e.id,e.nom,e.nom,e.sexe,e.dn.jours,e.dn.mois,e.dn.annee,e.classe);
*/
}
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview2;

treeview2=lookup_widget(objet_graphique,"treeview1");
afficher_etudiant(treeview2);
}


void
on_button3_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
//modif
GtkWidget *windowajouter;

windowajouter=create_window_etudiant_modifier();
gtk_widget_show(windowajouter);

}


void
on_button4_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
//fenetre recherche
GtkWidget *windowajouter;

windowajouter=create_window3();
gtk_widget_show(windowajouter);
}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
///fenetre ajout
GtkWidget *windowajouter;

windowajouter=create_window_etudiant_ajouter();
gtk_widget_show(windowajouter);
}


void
on_button1_clicked                     (GtkWidget       *objet_graphique,

                                        gpointer         user_data)
{
GtkWidget *windowetudiant;
    GtkWidget *tous;
    windowetudiant=lookup_widget(objet_graphique,"window_etudiant");
    gtk_widget_destroy(windowetudiant);
    tous=lookup_widget(objet_graphique,"tous");
    tous=create_tous();
    gtk_widget_show(tous);
}


void
on_button2_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(objet_graphique,"window_etudiant");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(objet_graphique,"login");
    dashboard=create_login();
    gtk_widget_show(dashboard);
}


void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

FILE *f=NULL;
GtkWidget *info5,*id,*nom,*prenom,*email,*tel,*spin_etage,*spin_chambre,*calendar,*cin,*classe;
char nom1[30];
char prenom1[30];
char id1[9];
char classe1[30];
char sexe1[30];
int etage1;
int chambre1;
char cin1[9];
int jours1,mois1,annee1;
char tel2[30];
char email1[30];
//-------association-----------------
calendar = lookup_widget(objet_graphique, "calendar1");
nom = lookup_widget (objet_graphique, "entry_etudiant_ajouter_nom");
prenom = lookup_widget (objet_graphique, "entry_etudiant_ajouter_prenom");
classe = lookup_widget (objet_graphique, "comboboxentry1");
id = lookup_widget (objet_graphique, "entry_etudiant_ajouter_id");
cin = lookup_widget (objet_graphique, "entry_etudiant_ajouter_cin");
spin_etage=lookup_widget(objet_graphique,"spinbutton1");
spin_chambre=lookup_widget(objet_graphique,"spinbutton2");
email=lookup_widget(objet_graphique,"entry_etudiant_ajouter_email");
tel=lookup_widget(objet_graphique,"entry_etudiant_ajouter_tel");

///////////////////////////
gtk_calendar_get_date(GTK_CALENDAR(calendar),&jours1,&mois1,&annee1);
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin)));
strcpy(email1, gtk_entry_get_text(GTK_ENTRY(email)));
strcpy(tel2, gtk_entry_get_text(GTK_ENTRY(tel)));
strcpy(classe1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe)));
if (x==1)

{
strcpy(sexe1,"homme");
}
 else 

{
strcpy(sexe1,"femme");
}

etage1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_etage));
chambre1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_chambre));

mois1+=1;

printf("\n%s",nom1);
printf("\n%s",prenom1);
printf("\n%s",id1);
printf("\n%s",cin1);
printf("\n%s",sexe1);
printf("\n%d",jours1);
printf("\n%d",mois1);
printf("\n%d",annee1);
printf("\n%d",etage1);
printf("\n%d",chambre1);
printf("\n%s",classe1);
printf("\n%s",email1);
printf("\n%s",tel2);


//ouvrir le fichier 
f=fopen("utilisateur.txt","a+");
if(f!=NULL)
{
//ecrire dans le fichier
fprintf(f,"%s %s %s %s %s %s %s %d %d %d %d %d  %s\n",id1,cin1,nom1,prenom1,sexe1,email1,tel2,etage1,chambre1,jours1,mois1,annee1,classe1);
fclose(f);
}
else
printf("\n not found");
info5=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"etudiant ajouté avec succées!");
switch (gtk_dialog_run(GTK_DIALOG(info5)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info5);
break;

}
}


void
on_button9_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
etudiant e;
GtkWidget *info3,*id2,*nom2,*prenom2,*sexe2,*email2,*tel2,*spin_etage2,*spin_chambre2,*cin2,*classe2,*calendar2,*spin_mois,*spin_annee;
char nom1[30];
char prenom1[30];
char id1[9];
char classe1[30];
char sexe4[30];
int etage1;
int chambre1;
char cin1[9];
int jours1,mois1,annee1;
char tel1[30];
char email1[30];

//////////////////////////////////////////
nom2 = lookup_widget (objet_graphique, "entry_etudiant_modifier_nom");
prenom2 = lookup_widget (objet_graphique, "entry_etudiant_modifier_prenom");
classe2 = lookup_widget (objet_graphique, "comboboxentry2");
sexe2 = lookup_widget (objet_graphique, "comboboxentry3");
id2 = lookup_widget (objet_graphique, "entry_etudiant_modifer_id");
cin2 = lookup_widget (objet_graphique, "entry_etudiant_modifier_cin");
spin_etage2=lookup_widget(objet_graphique,"spinbutton3");
spin_chambre2=lookup_widget(objet_graphique,"spinbutton4");
email2=lookup_widget(objet_graphique,"entry_etudiant_modifier_email");
tel2=lookup_widget(objet_graphique,"entry_etudiant_modifier_tel");
calendar2 = lookup_widget (objet_graphique, "calendar2");


///////////////////////////
gtk_calendar_get_date(GTK_CALENDAR(calendar2),&jours1,&mois1,&annee1);
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom2)));
strcpy(prenom1, gtk_entry_get_text(GTK_ENTRY(prenom2)));
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id2)));
strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(cin2)));
strcpy(email1, gtk_entry_get_text(GTK_ENTRY(email2)));
strcpy(tel1, gtk_entry_get_text(GTK_ENTRY(tel2)));
strcpy(classe1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe2)));
strcpy(sexe4,gtk_combo_box_get_active_text(GTK_COMBO_BOX(sexe2)));
etage1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_etage2));
chambre1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_chambre2));
mois1++;
strcpy(e.cin,cin1);
strcpy(e.id,id1);
strcpy(e.nom,nom1);
strcpy(e.prenom,prenom1);
strcpy(e.sexe,sexe4);
strcpy(e.email,email1);
strcpy(e.tel,tel1);
e.etage=etage1;
e.chambre=chambre1;
e.dn.jours=jours1;
e.dn.mois=mois1;
e.dn.annee=annee1;
strcpy(e.classe,classe1);

printf("\n%s",e.cin);
printf("\n%s",e.id);
printf("\n%s",e.nom);
printf("\n%s",e.prenom);
printf("\n%s",e.sexe);
printf("\n%s",e.email);
printf("\n%s",e.tel);
printf("\n%d",e.etage);
printf("\n%d",e.chambre);
printf("\n%d",e.dn.jours);
printf("\n%d",e.dn.mois);
printf("\n%d",e.dn.annee);

printf("\n%s\n",e.classe);





modifier_etudiant(e);

info3=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modification effectuée avec succées!");
switch (gtk_dialog_run(GTK_DIALOG(info3)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info3);
break;

}

}


void
on_button8_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *identifiant,*info,*info2;

char idhah[20];
int test=0;
identifiant = lookup_widget (objet_graphique,"entry_etudiant_modifer_id");

strcpy(idhah, gtk_entry_get_text(GTK_ENTRY(identifiant)));

printf("\n%s",idhah);
GtkWidget *windowmodifier;
etudiant e2;

FILE *f,*g;
f=fopen("utilisateur.txt","r");
g=fopen("tmp2.txt","w");
if ((f!=NULL) )
{
while (fscanf(f,"%s %s %s %s %s %s %s %d %d %d %d %d %s \n",e2.id,e2.cin,e2.nom,e2.prenom,e2.sexe,e2.email,e2.tel,&e2.etage,&e2.chambre,&e2.dn.jours,&e2.dn.mois,&e2.dn.annee,e2.classe)!=EOF)
{
if (strcmp(idhah,e2.id)==0)
{
test=1;
fprintf(g,"%s %s %s %s %s %s %s %d %d %d %d %d %s \n",e2.id,e2.cin,e2.nom,e2.prenom,e2.sexe,e2.email,e2.tel,e2.etage,e2.chambre,e2.dn.jours,e2.dn.mois,e2.dn.annee,e2.classe);
info=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"etudiant trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info);
break;
}
}



}
}
fclose(f);
fclose(g);



if (test==0)
{
info2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'etudiant avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(info2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info2);
break;

}
}
////// iniiiiiiiiiit

etudiant e3;
GtkWidget *nom,*prenom,*radio3,*radio4,*calendar,*id,*classe,*cin,*sexe,*tel,*email,*spin_etage,*spin_chambre,*spin_jours,*spin_mois,*spin_annee;
FILE *q=NULL;
char m[200][200]={"3B1","3B2","3B3","3B4","3B5","3B6","3B7","3B8","3B9","3B10","3B11","3B12","3B13","3B14"};
char m1[200][200]={"homme","femme"};
int i=0;
int j=0;
q=fopen("tmp2.txt","r");
fscanf(q,"%s %s %s %s %s %s %s %d %d %d %d %d %s \n",e3.id,e3.cin,e3.nom,e3.prenom,e3.sexe,e3.email,e3.tel,&e3.etage,&e3.chambre,&e3.dn.jours,&e3.dn.mois,&e3.dn.annee,e3.classe);
nom = lookup_widget (objet_graphique,"entry_etudiant_modifer_id");
gtk_entry_set_text(nom,e3.id);
nom = lookup_widget (objet_graphique,"entry_etudiant_modifier_cin");
gtk_entry_set_text(nom,e3.cin);
nom = lookup_widget (objet_graphique,"entry_etudiant_modifier_nom");
gtk_entry_set_text(nom,e3.nom);
nom = lookup_widget (objet_graphique,"entry_etudiant_modifier_prenom");
gtk_entry_set_text(nom,e3.prenom);

nom = lookup_widget (objet_graphique,"entry_etudiant_modifier_email");
gtk_entry_set_text(nom,e3.email);
nom = lookup_widget (objet_graphique,"entry_etudiant_modifier_tel");
gtk_entry_set_text(nom,e3.tel);
///////// calendar //////////

e3.dn.mois-=1;
//calendar = lookup_widget(objet_graphique, "calendar2");
//gtk_calendar_set_date(GTK_CALENDAR(calendar),e3.dn.jours,e3.dn.mois,e3.dn.annee);*/
spin_etage=lookup_widget(objet_graphique,"spinbutton3");
spin_chambre=lookup_widget(objet_graphique,"spinbutton4");
while ((i<14) && (strcmp(m[i],e3.classe))!=0)
{
i=i+1;}
classe = lookup_widget (objet_graphique, "comboboxentry2");
gtk_combo_box_set_active(GTK_COMBO_BOX(classe),i);
gtk_spin_button_set_value(spin_etage,e3.etage);
gtk_spin_button_set_value(spin_chambre,e3.chambre);


while ((j<2) && (strcmp(m1[j],e3.sexe))!=0)
{
j=j+1;}
sexe = lookup_widget (objet_graphique, "comboboxentry3");
gtk_combo_box_set_active(GTK_COMBO_BOX(sexe),j);

}


void
on_button10_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
////////// recherche hereeeeeeeeeeee 
GtkWidget *lol,*info6,*info7,*treeview21,*windowEspacefoyer1;

char lol1[20];
int test1=0;
lol = lookup_widget (objet_graphique,"entry1_etudiant");
strcpy(lol1, gtk_entry_get_text(GTK_ENTRY(lol)));

etudiant e4;

FILE *f1,*g1;
f1=fopen("utilisateur.txt","r");
g1=fopen("tmp7.txt","w");
if ((f1!=NULL) )
{
while (fscanf(f1,"%s %s %s %s %s %s %s %d %d %d %d %d %s \n",e4.id,e4.cin,e4.nom,e4.prenom,e4.sexe,e4.email,e4.tel,&e4.etage,&e4.chambre,&e4.dn.jours,&e4.dn.mois,&e4.dn.annee,e4.classe)!=EOF)
{
if (strcmp(lol1,e4.id)==0)
{
test1=1;
fprintf(g1,"%s %s %s %s %s %s %s %d %d %d %d %d %s \n",e4.id,e4.cin,e4.nom,e4.prenom,e4.sexe,e4.email,e4.tel,e4.etage,e4.chambre,e4.dn.jours,e4.dn.mois,e4.dn.annee,e4.classe);
info6=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"etudiant trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info6)))
{
case GTK_RESPONSE_OK:


gtk_widget_destroy(info6);
break;
}

}



}
}
fclose(f1);
fclose(g1);



if (test1==0)
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'etudiant avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
////////////////////////////////////////////////////////////
break;

}

}
else if (test1==1)

{
windowEspacefoyer1=create_window4();
gtk_widget_show(windowEspacefoyer1);
treeview21=lookup_widget(windowEspacefoyer1,"treeview2");
//vider(treeview21);
afficher_etudiantt(treeview21);

}

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=1;
printf("\nla valeur de x est %d",x);
}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
x=2;
printf("\nla valeur de x est %d",x);
}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=1;
printf("\nla valeur de y est %d",y);
}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
y=2;
printf("\nla valeur de y est %d",y);
}
}


/**************************************nadaaaaaaaaaaaa************************/















































void
on_button10rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button11rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *windowafficherrec;




	GtkWidget *treeview11rec;
	
	GtkWidget *ajoutreclamation;
	ajoutreclamation=lookup_widget(button,"ajoutreclamation");
      gtk_widget_destroy(ajoutreclamation);
	
	
         windowafficherrec=create_affichreclamation();
         gtk_widget_show(windowafficherrec); 
	
	treeview11rec=lookup_widget(windowafficherrec,"treeview1rec");

	afficherrec(treeview11rec);
}


void
on_button13rec_clicked                    (GtkWidget       *obj, gpointer         user_data)
{
GtkWidget *entry3rec; 
GtkWidget *entry9rec; 
GtkWidget *combobox1rec;
GtkWidget  *spin3nd;
GtkWidget  *spin4nd;
GtkWidget  *spin5nd;
//GtkWidget *pRadio1;
//GtkWidget *pRadio3;

reclamation t;

GtkWidget *ctrl;
GtkWidget *info4;
GtkWidget *ajoutreclamation;
GtkWidget *affichreclamation;
GtkWidget *treeview11rec;


entry3rec=lookup_widget(obj,"entry3rec");
combobox1rec=lookup_widget(obj,"combobox1rec");
spin3nd=lookup_widget(obj,"spinbutton3rec");
spin4nd=lookup_widget(obj,"spinbutton4rec");
spin5nd=lookup_widget(obj,"spinbutton5rec");
entry9rec=lookup_widget(obj,"entry9rec");
strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(entry3rec)));
strcpy(t.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1rec)));
strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(entry9rec)));
t.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin3nd));
t.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin4nd));
t.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin5nd));
strcpy(t.reclamation,gtk_entry_get_text(GTK_ENTRY(entry9rec)));


 
  if (idexistee(t.id)==1)
    {ctrl= lookup_widget(obj,"label54rec");
gtk_label_set_text(GTK_LABEL(ctrl),"ce id existe deja😔");}

else {
ajouterrec(t);
info4=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"reclamation ajouté avec succées!");
switch (gtk_dialog_run(GTK_DIALOG(info4)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info4);
break;

}
}

ajoutreclamation=lookup_widget(obj,"ajoutreclamation");
      gtk_widget_destroy(ajoutreclamation);
      affichreclamation=lookup_widget(obj,"affichreclamation");
      affichreclamation=create_affichreclamation();
      gtk_widget_show(affichreclamation);
      treeview11rec=lookup_widget(affichreclamation,"treeview1rec");
afficherrec(treeview11rec);

}




void
on_button14rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *choisir;
GtkWidget *affichreclamation;

affichreclamation=lookup_widget(button,"affichreclamation");
      gtk_widget_destroy(affichreclamation);




choisir=create_choisir();
gtk_widget_show (choisir);
}


void
on_button8rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *supprec;
GtkWidget *choisir;

choisir=lookup_widget(button,"choisir");
      gtk_widget_destroy(choisir);



supprec=create_supprec();
gtk_widget_show (supprec);
}


void
on_button7rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *modifrecher;
GtkWidget *choisir;


choisir=lookup_widget(button,"choisir");
      gtk_widget_destroy(choisir);

modifrecher=create_modifrecher();
gtk_widget_show (modifrecher);








}


void
on_button6rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *choisir;
GtkWidget *windowafficherrec;
	GtkWidget *treeview11rec;
	
	choisir=lookup_widget(button,"choisir");
      gtk_widget_destroy(choisir);
         windowafficherrec=create_affichreclamation();
         gtk_widget_show(windowafficherrec); 
	
	treeview11rec=lookup_widget(windowafficherrec,"treeview1rec");

	afficherrec(treeview11rec);
	
	
}


void
on_button9rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *sure;
GtkWidget *choisir;


choisir=lookup_widget(button,"choisir");
      gtk_widget_destroy(choisir);




sure=create_modifrecher();
gtk_widget_show (sure);
}


void
on_button5rec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajoutreclamation;
GtkWidget *choisir;


choisir=lookup_widget(button,"choisir");
      gtk_widget_destroy(choisir);

ajoutreclamation=create_ajoutreclamation();
gtk_widget_show (ajoutreclamation);







}


void
on_button15rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
char id[50];
GtkWidget *hm;
  
    

	GtkWidget *entry4;
	entry4=lookup_widget(button,"entry4");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry4)));
if (idexistee(id)==1){
	supprimerrec(id);}
	else {hm= lookup_widget(button,"label56rec");
gtk_label_set_text(GTK_LABEL(hm),"ce id n'existe pas😫");}
	
}


void
on_button16rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *supprec;

GtkWidget *choisir;
supprec=lookup_widget(button,"supprec");
      gtk_widget_destroy(supprec);




choisir=create_choisir();
gtk_widget_show (choisir);
}


void
on_button19rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *choisir;
GtkWidget *modifrecher;
modifrecher=lookup_widget(button,"modifrecher");
      gtk_widget_destroy(modifrecher);



choisir=create_choisir();
gtk_widget_show (choisir);

}


void
on_button17rec_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{  GtkWidget *info255;
GtkWidget *type2;
char idd[50];
	char typee[50];
	char date1[50];
	char reclamationn[50];
	GtkWidget *entry5rec;
	
	GtkWidget *entry8rec; 
	GtkWidget *entry7rec;
	
	entry5rec=lookup_widget(button,"entry5rec");
	strcpy(idd,gtk_entry_get_text(GTK_ENTRY(entry5rec)));
	type2 = lookup_widget (button, "comboboxrec");
	strcpy(typee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type2)));
	
	entry8rec=lookup_widget(button,"entry8rec");
	strcpy(date1,gtk_entry_get_text(GTK_ENTRY(entry8rec)));
	entry7rec=lookup_widget(button,"entry7rec");
	strcpy(reclamationn,gtk_entry_get_text(GTK_ENTRY(entry7rec)));
	 modifierrec(idd,typee,reclamationn,date1);
	 
	 info255=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modification effectuée avec succées!");
switch (gtk_dialog_run(GTK_DIALOG(info255)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info255);
break;

}
	 
	 
	 
	 
	 
}


void
on_button18rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{






GtkWidget *info256;


GtkWidget *entry5rec;
GtkWidget *type;
GtkWidget *entry7rec;
GtkWidget *entry8rec;
GtkWidget *labelnad;
GtkWidget *labelnada;
FILE *fa;
int i=0;
char p[200][200]={"FOYER","RESTAURANT"};
char id1[50];
reclamation t;
char date[50];
fa=fopen("bloc.txt","r");
entry5rec=lookup_widget(button,"entry5rec");
strcpy(id1,gtk_entry_get_text(GTK_ENTRY(entry5rec)));
if (fa!=NULL)
 {
    	while(fscanf(fa,"%s %s %s %s \n",t.id,t.type,t.reclamation,date)!=EOF)
 {
			if(strcmp(id1,t.id)==0){
			
			
			
			
			while ((i<2) && (strcmp(p[i],t.type))!=0)
 
 
{i=i+1;}

				entry5rec=lookup_widget(button,"entry5rec");
				type = lookup_widget (button, "comboboxrec");
gtk_combo_box_set_active(GTK_COMBO_BOX(type),i);
				entry7rec=lookup_widget(button,"entry7rec");
				entry8rec=lookup_widget(button,"entry8rec");
				gtk_entry_set_text(GTK_ENTRY(entry5rec),t.id);
				
				gtk_entry_set_text(GTK_ENTRY(entry7rec),t.reclamation);
				gtk_entry_set_text(GTK_ENTRY(entry8rec),date);
				labelnad=lookup_widget(button,"label55rec");
                           gtk_label_set_text(GTK_LABEL(labelnad),"ce id existe 😁 ");
                           info256=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"reclamation trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info256)))
{
case GTK_RESPONSE_OK:


gtk_widget_destroy(info256);
break;
} 
				}
				
				
				
			
			 else 
			
			
			
{
     





}







}

}

}




void
on_treeview1rec_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
                                        
                                        
  {   reclamation rec;
  GtkTreeIter iter;
      gchar* id;
      gchar* reclamation;
      gchar* type;
      gint *jour;
      gint* mois;
      
      gint* annee;
      
      
      GtkTreeModel *model=gtk_tree_view_get_model(treeview);
      if (gtk_tree_model_get_iter(model,&iter,path))
      { gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&reclamation,2,&type,3,&jour,4,&mois,5,&annee,-1);
      strcpy(rec.id,id);
      strcpy(rec.reclamation,reclamation);
      strcpy(rec.type,type);
      rec.date.jour=jour;
      rec.date.mois=mois;
      rec.date.annee=annee; 
      supprimerrec(id);
      afficherrec(treeview);}
      
      
      }
                                           
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        
                                        









void
on_radiobutton1rec_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{GtkWidget *modifrecher;
GtkWidget *sure;
  
 if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
 {  


sure=lookup_widget(togglebutton,"sure");
      gtk_widget_destroy(sure);

modifrecher=create_modifrecher();
gtk_widget_show (modifrecher);
}
}


void
on_button20rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)

{
GtkWidget *sure;
GtkWidget *affichreclamation;

affichreclamation=lookup_widget(button,"affichreclamation");
      gtk_widget_destroy(affichreclamation);


sure=create_sure();
gtk_widget_show (sure);
}




void
on_button21rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *sure;



GtkWidget *windowafficher;
	GtkWidget *treeview11;
	sure=lookup_widget(button,"sure");
      gtk_widget_destroy(sure);
	
	
	
         windowafficher=create_affichreclamation();
         gtk_widget_show(windowafficher); 
	
	treeview11=lookup_widget(windowafficher,"treeview1");

	afficherrec(treeview11);
}


void
on_radiobutton2rec_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_button22rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *ajoutreclamation;
GtkWidget *affichreclamation;


affichreclamation=lookup_widget(button,"affichreclamation");
      gtk_widget_destroy(affichreclamation);


ajoutreclamation=create_ajoutreclamation();
gtk_widget_show (ajoutreclamation);
}


void
on_button23rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *choisir;
GtkWidget *serviceplusreclame;


serviceplusreclame=lookup_widget(button,"serviceplusreclame");
      gtk_widget_destroy(serviceplusreclame);


choisir=create_choisir();
gtk_widget_show (choisir);
}


void
on_button24rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{


GtkWidget *choisir;





GtkWidget *tous;


choisir=lookup_widget(button,"choisir");
      gtk_widget_destroy(choisir);

tous=create_tous();
gtk_widget_show (tous);}





    



























void
on_button25rec_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{char ch3[100];
char ch4[]="foyer";
char ch5[]="restau";
char ch6[]="RESTAU ET FOYER";
GtkWidget* output;

n=service_plus_reclame();

if (n==0)

   {sprintf(ch3,"%s",ch4);
output=lookup_widget(button,"label53rec");
gtk_label_set_text(GTK_LABEL(output),"foyer🏡");
}
else if (n==1)
  { 
  sprintf(ch3,"%s",ch5);
output= lookup_widget(button,"label53rec");
gtk_label_set_text(GTK_LABEL(output),"restauuu🍔");
}

else if (n==2)
{ 
  sprintf(ch3,"%s",ch6);
output= lookup_widget(button,"label53rec");
gtk_label_set_text(GTK_LABEL(output),"RESTAU ET FOYER");
}





}














void
on_button1rec_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{                }

//////////////////////////ichrak///////////////////////////////////////

void
on_button_ajout1_clicked               (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2_ajout;
window2_ajout=create_window2_ajout();
gtk_widget_show(window2_ajout);
}


void
on_button_menu1_clicked                (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window33;
window33=create_window33();
gtk_widget_show(window33);
treeview1=lookup_widget(window33,"treeview1menu");
afficher(treeview1);
}





void
on_buttonajout2menu_clicked                (GtkWidget      *button,
                                        gpointer         user_data)
{
int j;
menu m;
char chjour[20],chtemps[20];
GtkWidget *entry1, *entry2plat, *entry3dessert ,*comboboxjour,*output;
GtkWidget *window2_ajout;
comboboxjour=lookup_widget(button,"comboboxjour");
strcpy(chjour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxjour)));

if (xx==1){
strcpy(chtemps,"petit_dejeuner");}
else if (xx==2){
strcpy(chtemps,"dejeuner");}
else
{strcpy(chtemps,"dinner");}
j=controle(chjour,chtemps);
if(j!=1)
	{
	strcpy(m.jour,chjour);
	strcpy(m.temps,chtemps);
        if (t[0]==1)
	{strcat(m.menu.entree,"salade.");}
	if (t[1]==1)
	{strcat(m.menu.entree,"soupe.");}
	if (t[2]==1)
	{strcat(m.menu.entree,"braquette.");}

entry2plat=lookup_widget(button,"entry2plat");
entry3dessert=lookup_widget(button,"entry3dessert");
strcpy(m.menu.plat_principale,gtk_entry_get_text(GTK_ENTRY(entry2plat) ) );
strcpy(m.menu.dessert,gtk_entry_get_text(GTK_ENTRY(entry3dessert) ) );
	
	ajout_menu(m);
	gtk_widget_destroy(window2_ajout);
	output= lookup_widget(button,"labelcontrole");
	gtk_label_set_text(GTK_LABEL(output),"AJOUT SUCCEE");
	}
else
	{
	output= lookup_widget(button,"labelcontrole");
	gtk_label_set_text(GTK_LABEL(output),"ce plat correspond déja a un jour");
	}

}


void
on_button5_menu_ajout_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2_ajout;
GtkWidget *window33;
GtkWidget *treeview1;
window2_ajout=lookup_widget(button,"window2_ajout");
gtk_widget_destroy(window2_ajout);
window33=lookup_widget(button,"window33");
window33=create_window33();
gtk_widget_show(window33);
treeview1=lookup_widget(window33,"treeview1menu");
afficher(treeview1);

}

void
on_buttonrecherchermenu1_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Jour1,*Combobox2;
char jour[100];
char temps[100];

Combobox2=lookup_widget(button,"combobox2rechercher");

strcpy(temps,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox2)));
rechercher_menu2(temps);
GtkWidget *treeview1;
GtkWidget *window33;
window33=create_window33();
gtk_widget_show(window33);
treeview1=lookup_widget(window33,"treeview1menu");
afficher1(treeview1);

}


void
on_buttonmodifiermenu1_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
menu m;
GtkWidget *windowmodifier;
GtkWidget *window33;
window33=lookup_widget(button,"window33");
windowmodifier=create_windowmodifier();
gtk_widget_show(windowmodifier);
gtk_widget_destroy(window33);


}


void
on_button10retourner_clicked           (GtkWidget     *button,
                                        gpointer         user_data)
{GtkWidget *treeview1; 
GtkWidget *window33;
window33=create_window33();
gtk_widget_show(window33);
treeview1=lookup_widget(window33,"treeview1menu");
afficher(treeview1);
}


void
on_button11rechercher_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
{

}


void
on_radiobuttonpetit_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=1;}
}


void
on_radiobuttondinner_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=3;}
}


void
on_radiobuttondejeuner_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{xx=2;}
}


void
on_treeview1menu_row_activated             (GtkTreeView     *treeview1,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)

{

gchar* jour;
gchar* temps;
gchar* entree;
gchar* plat_principale;
gchar* dessert; 
GtkTreeIter iter;

GtkTreeModel *model = gtk_tree_view_get_model(treeview1);

	if (gtk_tree_model_get_iter(model,&iter,path))
	{ 
	  gtk_tree_model_get(GTK_LIST_STORE(model),&iter, 0 , &jour, 1,&temps,2,&entree,3,&plat_principale,4,&dessert,-1);
	  strcpy(me.jour,jour);
	  strcpy(me.temps,temps);
	  strcpy(me.menu.entree,entree);
	 strcpy(me.menu.plat_principale,plat_principale);
	 strcpy(me.menu.dessert,dessert);

	}
}


void
on_button7actualiser_clicked           (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *window33,*w1;
w1=lookup_widget(button,"window33");
window33=create_window33();
gtk_widget_show(window33);
gtk_widget_hide(w1);
treeview1=lookup_widget(window33,"treeview1menu");
supprimer_menu(me);
afficher(treeview1);

}



void
on_button4retourmenu_clicked            (GtkWidget     *button,
                                        gpointer         user_data)
{
GtkWidget *window2_ajout,*window33;
window33=lookup_widget(button,"window33");
gtk_widget_destroy(window33);
window2_ajout=create_window2_ajout();
gtk_widget_show(window2_ajout);
}




void
on_buttonmeilleur_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
char meill11[10];
char meill13[10];
char meill21[10];
char meill23[10];
char meill31[10];
char meill33[10];
GtkWidget *window5meilleur;
meilleur_menu(meill11,meill13,meill21,meill23,meill31,meill33);
window5meilleur=lookup_widget(button,"window5meilleur");
GtkWidget* mm11=lookup_widget(window5meilleur,"label270");
gtk_label_set_text(GTK_LABEL(mm11),meill11);
gtk_widget_show(mm11);

GtkWidget* mm13=lookup_widget(window5meilleur,"label300");
gtk_label_set_text(GTK_LABEL(mm13),meill13);
gtk_widget_show(mm13);

GtkWidget* mm21=lookup_widget(window5meilleur,"label280");
gtk_label_set_text(GTK_LABEL(mm21),meill21);
gtk_widget_show(mm21);

GtkWidget* mm23=lookup_widget(window5meilleur,"label310");
gtk_label_set_text(GTK_LABEL(mm23),meill23);
gtk_widget_show(mm23);

GtkWidget* mm31=lookup_widget(window5meilleur,"label290");
gtk_label_set_text(GTK_LABEL(mm31),meill31);
gtk_widget_show(mm31);

GtkWidget* mm33=lookup_widget(window5meilleur,"label320");
gtk_label_set_text(GTK_LABEL(mm33),meill33);
gtk_widget_show(mm33);

}


void
on_buttonmeilleurmenu_clicked          (GtkWidget         *button,
                                        gpointer         user_data)
{
GtkWidget *window5meilleur;
window5meilleur=create_window5meilleur();
gtk_widget_show(window5meilleur);
window5meilleur=lookup_widget(button,"window5meilleur");

}


void
on_radiobutton3modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=3;}
}
void
on_radiobutton2modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=2;}
}


void
on_radiobutton1modif_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}


void
on_buttonvalidermodif_clicked          (GtkWidget        *button,
                                        gpointer         user_data)
{

GtkWidget *windowmodifier;
GtkWidget *entry_entree, *entry_plat, *entry_dessert,*Combobox1menu;
windowmodifier=lookup_widget(button,"windowmodifier");
//Combobox1=lookup_widget(button,"combobox1");
entry_entree=lookup_widget(button,"entry4entree");
entry_plat=lookup_widget(button,"entry5plat");
entry_dessert=lookup_widget(button,"entry6dessert");
 strcpy(me.menu.entree,gtk_entry_get_text(GTK_ENTRY(entry_entree) ) );
strcpy(me.menu.plat_principale,gtk_entry_get_text(GTK_ENTRY(entry_plat) ) );
 strcpy(me.menu.dessert,gtk_entry_get_text(GTK_ENTRY(entry_dessert) ) );


modifier_menu(me);
gtk_widget_destroy(windowmodifier);

}







void
on_checkbutton1salade_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{t[0]=1;}
}


void
on_checkbutton2soupe_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
{t[1]=1;}
}


void
on_checkbutton3barquette_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)

{
if ( gtk_toggle_button_get_active(togglebutton))
{t[2]=1;}
}
void
on_button4retourmenu1_clicked           (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *window2_ajout;

window2_ajout=lookup_widget(button,"window2_ajout");
gtk_widget_destroy(window2_ajout);
}



void
on_buttonquittermenu_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
}





void
on_checkbuttonancien_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
int a;

GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *combobox1menu;



char chjour[50];
char chtemps[50];


menu m;

GtkWidget *fenetre_modification;

fenetre_modification=lookup_widget(togglebutton,"windowmodifier");

combobox1menu=lookup_widget(togglebutton,"combobox1menu");
strcpy(chjour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1menu)));

if (z==1){
strcpy(chtemps,"petit_dejeuner");}
else if (z==2){
strcpy(chtemps,"dejeuner");}
else
{strcpy(chtemps,"dinner");}
a=controle(chjour,chtemps);
if (a==1)
{

m=chercher_menu(chjour,chtemps);

output1 = lookup_widget(togglebutton, "label161");
gtk_label_set_text(GTK_LABEL(output1),m.menu.entree);

output2 = lookup_widget(togglebutton, "label160");
gtk_label_set_text(GTK_LABEL(output2),m.menu.plat_principale);

output3 = lookup_widget(togglebutton, "label159");
gtk_label_set_text(GTK_LABEL(output3),m.menu.dessert);


}


}
}
void
on_button_trouve_meilleur_menu_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *mm1,*mm2,*mm3,*mm4;
char text1[100];
char text2[100];
char text4[100];
char text3[100];
meilleur_menu1(text1,text2,text3,text4);
mm1=lookup_widget (objet_graphique, "best1");
mm2=lookup_widget (objet_graphique, "best2");
mm3=lookup_widget (objet_graphique, "best3");
mm4=lookup_widget (objet_graphique, "best4");
gtk_label_set_text(GTK_LABEL(mm1),text1);
gtk_label_set_text(GTK_LABEL(mm2),text2);
gtk_label_set_text(GTK_LABEL(mm3),text3);
gtk_label_set_text(GTK_LABEL(mm4),text4);
}




////////////////////////////////////////////////hela//////////////



void
on_button_A_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"menu");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"login");
    dashboard=create_login();
    gtk_widget_show(dashboard);
}


void
on_treeview_H_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
stock t;
GtkTreeIter iter;
gchar* id;
gchar* quantite;
gchar* nom;
gchar* emballage;
gchar* prix;





gint* jours;
gint* mois;
gint* annee;
gchar* origine;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter, path))
{
gtk_tree_model_get(GTK_LIST_STORE(model), &iter, 0, &id,1, &quantite, 2, &nom, 3, &emballage, 4, &prix, 5 , &jours, 6 , &mois, 7 , &annee, 8 , &origine, -1);
strcpy(t.id,id);
strcpy(t.quantite,quantite);

strcpy(t.nom,nom);
strcpy(t.origine,origine);
strcpy(t.emballage,emballage);
strcpy(t.prix,prix);

t.dn.jours=jours;
t.dn.mois=mois;
t.dn.annee=annee;
supprimer_stock(t);

afficher_stock(treeview);

}
}



void
on_button_E_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *xd;
xd=create_recherche_stock();
gtk_widget_show(xd);
}


void
on_button_C_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowajout_stock;

windowajout_stock=create_ajout_stock();
gtk_widget_show(windowajout_stock);
}




void
on_radiobutton_H_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
h=1;
printf("\nla valeur de x est %d",h);
}
}


void
on_radiobutton_T_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
h=2;
printf("\nla valeur de x est %d",h);
}
}


void
on_button_G_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu;
menu=create_menu();
gtk_widget_show (menu);
}




void
on_button_I_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_J_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
FILE *f=NULL;
GtkWidget *info5,*id,*nom,*prix,*calendar,*quantite,*origine,*ctrll;
char nom1[30];
char id1[9];
char origine1[30];
char emballage1[30];
char quantite1[9];
int jours1,mois1,annee1;
char prix2[30];

//-------association-----------------
calendar = lookup_widget(objet_graphique, "calendar_hela");
nom = lookup_widget (objet_graphique, "entry_22");
origine = lookup_widget (objet_graphique, "combobox_origine");
id = lookup_widget (objet_graphique, "entry_11");
quantite = lookup_widget (objet_graphique, "entry_33");
prix=lookup_widget(objet_graphique,"entry_44");

///////////////////////////
gtk_calendar_get_date(GTK_CALENDAR(calendar),&jours1,&mois1,&annee1);
strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(quantite1, gtk_entry_get_text(GTK_ENTRY(quantite)));
strcpy(prix2, gtk_entry_get_text(GTK_ENTRY(prix)));
strcpy(origine1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(origine)));
if (h==1)
{
strcpy(emballage1,"emballee");
}
 else 

{
strcpy(emballage1,"non_emballee");
}



mois1+=1;

printf("\n%s",nom1);

printf("\n%s",id1);
printf("\n%s",quantite1);
printf("\n%s",emballage1);
printf("\n%d",jours1);
printf("\n%d",mois1);
printf("\n%d",annee1);
printf("\n%s",origine1);
printf("\n%s",prix2);




//ouvrir le fichier 
f=fopen("hela.txt","a+");
if(f!=NULL)
{
//controle
if (idexisteee(id1)==1)
    {ctrll= lookup_widget(objet_graphique,"idident");
gtk_label_set_text(GTK_LABEL(ctrll),"ce id existe deja😔");}

else {

//ecrire dans le fichier
fprintf(f,"%s %s %s %s %s %d %d %d %s \n",id1,quantite1,nom1,emballage1,prix2,jours1,mois1,annee1,origine1);
fclose(f);
info5=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"produit ajouté avec succées!");
switch (gtk_dialog_run(GTK_DIALOG(info5)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info5);
break;

}

}}




}





void
on_button_K_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *identifiant,*info,*info2;

char idhah[20];
int test=0;
identifiant = lookup_widget (objet_graphique,"entry_88");

strcpy(idhah, gtk_entry_get_text(GTK_ENTRY(identifiant)));

printf("\n%s",idhah);
GtkWidget *windowmodifier;
stock t2;

FILE *f,*g;
f=fopen("hela.txt","r");
g=fopen("tmp22.txt","w");
if ((f!=NULL) )
{
while (fscanf(f,"%s %s %s %s %s  %d %d %d  %s \n",t2.id,t2.quantite,t2.nom,t2.emballage,t2.prix,&t2.dn.jours,&t2.dn.mois,&t2.dn.annee,t2.origine)!=EOF)
{
if (strcmp(idhah,t2.id)==0)
{
test=1;
fprintf(g,"%s %s %s %s %s  %d %d %d  %s \n",t2.id,t2.quantite,t2.nom,t2.emballage,t2.prix,t2.dn.jours,t2.dn.mois,t2.dn.annee,t2.origine);
info=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"produit trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info);
break;
}
}



}
}
fclose(f);
fclose(g);



if (test==0)
{
info2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas de produit avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(info2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info2);
break;

}
}
////// iniiiiiiiiiit

stock t3;
GtkWidget *nom,*radio3,*radio4,*calendar,*id,*origine,*quantite,*emballage,*prix,*spin_jours,*spin_mois,*spin_annee;
FILE *q=NULL;
char m[200][200]={"vegetal","animal"};
char m1[200][200]={"emballee","non_emballee"};
int i=0;
int j=0;
q=fopen("tmp22.txt","r");
fscanf(q,"%s %s %s %s %s  %d %d %d  %s \n",t3.id,t3.quantite,t3.nom,t3.emballage,t3.prix,&t3.dn.jours,&t3.dn.mois,&t3.dn.annee,t3.origine);
nom = lookup_widget (objet_graphique,"entry_88");
gtk_entry_set_text(nom,t3.id);
nom = lookup_widget (objet_graphique,"entry_111");
gtk_entry_set_text(nom,t3.quantite);
nom = lookup_widget (objet_graphique,"entry_99");
gtk_entry_set_text(nom,t3.nom);

nom = lookup_widget (objet_graphique,"entry_222");
gtk_entry_set_text(nom,t3.prix);
///////// calendar //////////

t3.dn.mois-=1;



while ((j<2) && (strcmp(m1[j],t3.emballage))!=0)
{
j=j+1;}
emballage = lookup_widget (objet_graphique, "combobox_444");
gtk_combo_box_set_active(GTK_COMBO_BOX(emballage),j);
while ((i<2) && (strcmp(m[i],t3.origine))!=0)
{
i=i+1;}

origine = lookup_widget (objet_graphique, "combobox_333");
gtk_combo_box_set_active(GTK_COMBO_BOX(origine),i);

spin_jours=lookup_widget(objet_graphique,"spinbutton_X");
spin_mois=lookup_widget(objet_graphique,"spinbutton_Y");
spin_annee=lookup_widget(objet_graphique,"spinbutton_Z");
gtk_spin_button_set_value(spin_jours,t3.dn.jours);
gtk_spin_button_set_value(spin_mois,t3.dn.mois);
gtk_spin_button_set_value(spin_annee,t3.dn.annee);
}





void
on_button_L_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
stock t;
GtkWidget *info3,*id2,*nom2,*emballage2,*prix2,*quantite2,*origine2,*spin_jours,*spin_mois,*spin_annee;
char nom1[30];
char id1[9];
char origine1[30];
char emballage4[30];
char quantite1[9];
int jours1,mois1,annee1;
char prix1[30];

//////////////////////////////////////////
nom2 = lookup_widget (objet_graphique, "entry_99");
origine2 = lookup_widget (objet_graphique, "combobox_333");
emballage2 = lookup_widget (objet_graphique, "combobox_444");
id2 = lookup_widget (objet_graphique, "entry_88");
quantite2 = lookup_widget (objet_graphique, "entry_111");
prix2=lookup_widget(objet_graphique,"entry_222");
spin_jours=lookup_widget(objet_graphique,"spinbutton_X");
spin_mois=lookup_widget(objet_graphique,"spinbutton_Y");
spin_annee=lookup_widget(objet_graphique,"spinbutton_Z");


///////////////////////////

strcpy(nom1, gtk_entry_get_text(GTK_ENTRY(nom2)));
strcpy(id1, gtk_entry_get_text(GTK_ENTRY(id2)));
strcpy(quantite1, gtk_entry_get_text(GTK_ENTRY(quantite2)));
strcpy(prix1, gtk_entry_get_text(GTK_ENTRY(prix2)));
strcpy(origine1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(origine2)));
strcpy(emballage4,gtk_combo_box_get_active_text(GTK_COMBO_BOX(emballage2)));
jours1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_jours));
mois1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_mois));
annee1=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spin_annee));

strcpy(t.quantite,quantite1);
strcpy(t.id,id1);
strcpy(t.nom,nom1);
strcpy(t.emballage,emballage4);
strcpy(t.prix,prix1);
t.dn.jours=jours1;
t.dn.mois=mois1;
t.dn.annee=annee1;
strcpy(t.origine,origine1);

printf("\n%s",t.quantite);
printf("\n%s",t.id);
printf("\n%s",t.nom);
printf("\n%s",t.emballage);
printf("\n%s",t.prix);
printf("\n%d",t.dn.jours);
printf("\n%d",t.dn.mois);
printf("\n%d",t.dn.annee);

printf("\n%s\n",t.origine);





modifier(t);

info3=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modification effectuée avec succées!");
switch (gtk_dialog_run(GTK_DIALOG(info3)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info3);
break;

}

}


void
on_button_M_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *lol,*info6,*info7,*treeviews,*windowEspacestock1;

char lol1[20];
int test1=0;
lol = lookup_widget (objet_graphique,"entry_777");
strcpy(lol1, gtk_entry_get_text(GTK_ENTRY(lol)));

stock t4;

FILE *f1,*g1;
f1=fopen("hela.txt","r");
g1=fopen("tmp77.txt","w");
if ((f1!=NULL) )
{
while (fscanf(f1,"%s %s %s %s %s  %d %d %d  %s \n",t4.id,t4.quantite,t4.nom,t4.emballage,t4.prix,&t4.dn.jours,&t4.dn.mois,&t4.dn.annee,t4.origine)!=EOF)
{
if (strcmp(lol1,t4.id)==0)
{
test1=1;
fprintf(g1,"%s %s %s %s %s  %d %d %d  %s \n",t4.id,t4.quantite,t4.nom,t4.emballage,t4.prix,t4.dn.jours,t4.dn.mois,t4.dn.annee,t4.origine);
info6=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"stock trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(info6)))
{
case GTK_RESPONSE_OK:


gtk_widget_destroy(info6);
break;
}

}



}
}
fclose(f1);
fclose(g1);



if (test1==0)
{
info7=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas de stock avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(info7)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(info7);
////////////////////////////////////////////////////////////
break;

}

}
else if (test1==1)

{
windowEspacestock1=create_cherche();
gtk_widget_show(windowEspacestock1);
treeviews=lookup_widget(windowEspacestock1,"treeviews");
//vider(treeview21);
afficher_stockk(treeviews);

}
}


void
on_button_N_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_button_D_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
{

GtkWidget *windowmodif_stock;

windowmodif_stock=create_modif_stock();
gtk_widget_show(windowmodif_stock);
}
}


void
on_button_F_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview2;
treeview2=lookup_widget(button,"treeview_H");
afficher_stock(treeview2);
}


void
on_button_O_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu,*modif_stock;
modif_stock=lookup_widget(button,"modif_stock");
      gtk_widget_destroy(modif_stock);
menu=create_menu();
gtk_widget_show (menu);
}


void
on_button_P_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu,*cherche;
cherche=lookup_widget(button,"cherche");
      gtk_widget_destroy(cherche);
menu=create_menu();
gtk_widget_show (menu);
}


void
on_button_Q_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_999, *output, *ctrll;
int hela;
stock t;
entry_999=lookup_widget(button,"entry_999");
strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(entry_999)));
//controle
if (idexisteee(t.id)==0)
    {ctrll= lookup_widget(button,"label_1002");
gtk_label_set_text(GTK_LABEL(ctrll),"pas de produit avec un tel id😔");}
else 
{


hela=repture_stock(t.id);
if (hela==1)
{
  output= lookup_widget(button,"label_1000");
 gtk_label_set_text(GTK_LABEL(output),"produit en stock 😎️");}
else
 {output= lookup_widget(button,"label_1000");
gtk_label_set_text(GTK_LABEL(output),"produit en repture de stock");}

}
}

void
on_button_R_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tous;
    GtkWidget *serviceplusreclame;
    tous=lookup_widget(button,"menu");
    gtk_widget_destroy(tous);
    serviceplusreclame=lookup_widget(button,"tous");
    serviceplusreclame=create_tous();
    gtk_widget_show(serviceplusreclame);
}


void
on_button_S_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *menu,*cherche_stock;
cherche_stock=lookup_widget(button,"cherche_stock");
      gtk_widget_destroy(cherche_stock);
menu=create_menu();
gtk_widget_show (menu);
}



/****************************Chahine*****************************/



void
on_non_def_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	x1 = 1;
    	}
}


void
on_def_toggled                         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	x1 = 2;
   	}
}


void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	capteur c;
	GtkWidget *addid,*addtype,*addmarque,*addprix,*addvaleur,*calendar;
	
	char prix[20],valeur[20];
	int a,m,j;

	addid = lookup_widget(objet,"entry1");
	addtype= lookup_widget(objet,"combobox1");
	addmarque= lookup_widget(objet,"combobox2");
	addprix = lookup_widget(objet,"entry2");	
	addvaleur = lookup_widget(objet,"entry3");
	calendar = lookup_widget(objet,"calendar1");
	

	strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(addid)));
	
	strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(addtype)));
	strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(addmarque)));	
	
	strcpy(valeur,gtk_entry_get_text(GTK_ENTRY(addvaleur)));
	c.valeur = atoi(valeur);
	
	strcpy(prix,gtk_entry_get_text(GTK_ENTRY(addprix)));
	c.prix = atoi(prix);

	if(x1 == 1){
		strcpy(c.etat,"Non_Defectueux");	
	}
	else{
		strcpy(c.etat,"Defectueux");
	}

	
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&a,&m,&j);
	c.d.j = j;
	c.d.m = m+1;
	c.d.a = a;

	if(!idExiste(c.id)){
		ajouter_capteur(c);
	}
	
	
}


void
on_gotodef_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"tech");
	window2 = create_window_def ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_rech_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"tech");
	window2 = create_window_rech ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_actu_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

	
	GtkWidget *current_window,*treeview; 

	current_window = lookup_widget(objet,"tech");
	treeview = lookup_widget(current_window,"treeListCap");

	afficher_capteur(treeview);
}


void
on_modif_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"tech");
	window2 = create_window_modif ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}





void
on_modif_non_def_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	y1 = 1;
    	}
}


void
on_modif_def_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
        	y1 = 2;
    	}
}


void
on_enreg_modif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1,*input2,*input3,*input4,*input5,*j,*m,*a,*output;
	char id[20],valeur[20],prix[20];
	capteur c;

	input1 = lookup_widget(objet,"idM");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	output = lookup_widget(objet,"outputEdit");


	char message[200];

	if(idExiste(id)){
		
		input2 = lookup_widget(objet,"combotypeM");
		input3 = lookup_widget(objet,"combomarqueM");
		input4 = lookup_widget(objet,"prixM");
		input5 = lookup_widget(objet,"valM");

		j = lookup_widget(objet,"spinJM");
		m = lookup_widget(objet,"spinMM");
		a = lookup_widget(objet,"spinAM");

		strcpy(c.id,id);
		strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input2)));
		strcpy(c.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
		
		strcpy(prix,gtk_entry_get_text(GTK_ENTRY(input4)));
		c.prix = atoi(prix);

		strcpy(valeur,gtk_entry_get_text(GTK_ENTRY(input5)));
		c.valeur = atoi(valeur);
	
		

		if(y1 == 1){
		strcpy(c.etat,"Non_Defectueux");	
		}
		else{
			strcpy(c.etat,"Defectueux");
		}


		c.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(j));
		c.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m));
		c.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(a));

		sprintf(message,"Votre Enregistrement a été effectué avec succés !");
		gtk_label_set_text(GTK_LABEL(output),message);
		modifier_capteur(c);
	}
	else{
		sprintf(message,"ID Non existant");
		gtk_label_set_text(GTK_LABEL(output),message);
	}

}


void
on_modif_rech_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1,*input2,*input3,*input4,*input5,*j,*m,*a,*def,*output;
	char id[20];
	capteur c;

	input1 = lookup_widget(objet,"idM");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	output = lookup_widget(objet,"outputEdit");


	char message[200];
	if(idExiste(id)){
		
		input2 = lookup_widget(objet,"combotypeM");
		input3 = lookup_widget(objet,"combomarqueM");
		input4 = lookup_widget(objet,"prixM");
		input5 = lookup_widget(objet,"valM");

		def = lookup_widget(objet,"modif_def");

		
		j = lookup_widget(objet,"spinJM");
		m = lookup_widget(objet,"spinMM");
		a = lookup_widget(objet,"spinAM");

		strcpy(c.type,chercher_capteur(id).type);
		strcpy(c.marque,chercher_capteur(id).marque);
		strcpy(c.etat,chercher_capteur(id).etat);

		c.valeur = chercher_capteur(id).valeur;
		c.prix = chercher_capteur(id).prix;

		c.d.j = chercher_capteur(id).d.j;
		c.d.m = chercher_capteur(id).d.m;
		c.d.a = chercher_capteur(id).d.a;

		if(strcmp(c.type,"Température") == 0){
			gtk_combo_box_set_active(input2,0);
		}
		else{
			gtk_combo_box_set_active(input2,1);
		}

		if(strcmp(c.marque,"Bosch") == 0){
			gtk_combo_box_set_active(input3,0);
		}
		else if(strcmp(c.marque,"Cherry") == 0){
			gtk_combo_box_set_active(input3,1);
		}
		else{
			gtk_combo_box_set_active(input3,2);
		}
		
		char prix[20],valeur[20];

		sprintf(prix,"%d",c.prix);
		gtk_entry_set_text(GTK_ENTRY(input4),prix);

		sprintf(valeur,"%d",c.valeur);
		gtk_entry_set_text(GTK_ENTRY(input5),valeur);
		
		if(strcmp(c.etat,"Defectueux") == 0){
			gtk_toggle_button_set_active (def,"TRUE");
		}
		


		gtk_spin_button_set_value(j,c.d.j);
		gtk_spin_button_set_value(m,c.d.m);
		gtk_spin_button_set_value(a,c.d.a);

		
		
		sprintf(message,"Tapez vos nouveaux données puis \n\t\tcliquer sur Enregistrer !");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"ID Non existant");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}





void
on_backEdit_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_modif");
	window2 = create_tech ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_backReche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_rech");
	window2 = create_tech ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}


void
on_backCapDef_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1;
	GtkWidget *window2;
	window1 = lookup_widget(objet,"window_def");
	window2 = create_tech ();
  	gtk_widget_show (window2);
	gtk_widget_destroy(window1);
}	


void
on_rech_rech_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{



	
}



void
on_actu_def_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

/*
	GtkWidget *current_window,*treeview; 

	current_window = lookup_widget(objet,"window_def");
	treeview = lookup_widget(current_window,"treeCapDef");

	
	afficher_capteur(treeview);
*/
}




void
on_treeListCap_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{


	
}


void
on_supp_modif_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *input1,*output;
	char id[20];
	capteur c;

	input1 = lookup_widget(objet,"idM");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));

	output = lookup_widget(objet,"outputEdit");


	char message[200];

	if(idExiste(id)){
	
		supprimer_capteur(id);
		sprintf(message,"Le capteur est supprimé avec succès");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
	else{
		sprintf(message,"ID Non existant");
		gtk_label_set_text(GTK_LABEL(output),message);
	}
}




void
on_quitter_cap_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	
}


/***********************************************Amine************************/



void
on_button1_valider_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
  FILE *f=NULL;
  GtkWidget *dad;
  GtkWidget *login,*pw,*Authentification,*admin;
  char login1[100],log[100];
  char passw[100],Pw[100];
  int test=0;
  login=lookup_widget(button,"entry1_loginA");
  pw=lookup_widget(button,"entry2_PwA");
  strcpy(login1,gtk_entry_get_text(GTK_ENTRY(login)));
  strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
  //ouvrir le fichier
  f=fopen("admin.txt","r");
  if (f!=NULL)
//ecrire dans le fichier
     { while (fscanf(f,"%s %s",log,Pw)!=EOF) 
       {
        if ((strcmp(log,login1)==0) && (strcmp(passw,Pw)==0))
           test=1;}
     }
     fclose(f);
     if (test==1)
     {
      //Authentification=lookup_widget(button,"Authentification");
      //gtk_widget_destroy(Authentification);
      admin=lookup_widget(button,"window_admin");
      admin=create_window_admin();
      gtk_widget_show(admin);
     }
     else
     {
      dad=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"coordonnees invalides!");
switch (gtk_dialog_run(GTK_DIALOG(dad)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(dad);
break;
}
}
}



void
on_button2_dec_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
   /*GtkWidget *admin;
   admin=lookup_widget(objet,"admin");
   gtk_widget_destroy(admin);
   GtkWidget *Authentification;
   Authentification=lookup_widget(objet,"Authentification");
   Authentification=create_Authentification();
   gtk_widget_show(Authentification);*/
    
}




void
on_checkbutton2_aj_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(togglebutton))
{
to[0]=1;
}  
else
{
to[0]=0;
}
}




void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(togglebutton))
{
to[2]=1;
}  
else
{
to[2]=0;
}
}


void
on_button5_ok_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
if (to[1]==1)
{
GtkWidget *modif;
GtkWidget *Gestion;
Gestion=lookup_widget(objet,"Gestion");
gtk_widget_destroy(Gestion);
modif=lookup_widget(objet,"ajout_modif");
modif=create_ajout_modif();
gtk_widget_show(modif);
to[1]=0;
}
   else if (to[0]==1)
{
   GtkWidget *Gestion;
   Gestion=lookup_widget(objet,"Gestion");
   gtk_widget_destroy(Gestion);
   GtkWidget *ajout;
   ajout=lookup_widget(objet,"ajout_modif");
   ajout=create_ajout_modif();
   gtk_widget_show(ajout);
 to[0]=0; 
}
 else if (to[2]==1)
{
 GtkWidget *Gestion;
   Gestion=lookup_widget(objet,"Gestion");
   gtk_widget_destroy(Gestion);
   GtkWidget *delete;
   delete=lookup_widget(objet,"DELETE");
   delete=create_DELETE();
   gtk_widget_show(delete);
to[2]=0;   
}
}


void
on_button6_recher_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
   char ch[20]="user.txt",m[100]="utilisateur inexistant",ch2[100];
   char ID[100],Nom[100],Prenom[100],Log[100],Passw[100],iden[100];
   GtkWidget *mom,*mom1;
   int Role,test;
   FILE *f=NULL;
   f=fopen(ch,"r");
   utilisateur u;
   GtkWidget *Id;
   Id=lookup_widget(objet,"entry3_cherid");
   strcpy(ID,gtk_entry_get_text(GTK_ENTRY(Id)));
   test=chercher(ch,ID);
   if (test==1)
   {
   GtkWidget *treeview1_user;
   treeview1_user=lookup_widget(objet,"treeview1_user"); 
   rechercher_k(treeview1_user,ID);
   mom=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"utilisateur trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(mom)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(mom);
break;
   }
}
   else
   {
    mom1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'utilisateurs avec un tel ID");
switch (gtk_dialog_run(GTK_DIALOG(mom1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(mom1);
break;
   }
}
}

void
on_button4_re_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *Gestion;
   Gestion=lookup_widget(objet,"Gestion");
   gtk_widget_destroy(Gestion);
   GtkWidget *admin;
   admin=lookup_widget(objet,"admin");
   admin=create_window_admin();
   gtk_widget_show(admin);
}


void
on_button7_ajou_clicked                (GtkWidget       *objet, 
                                        gpointer         user_data)
{
  char ch[]="user.txt";
  GtkWidget *Gestion;
  GtkWidget *combobox1_choice;
  GtkWidget *u;
  GtkWidget *pw;
  GtkWidget *n;
  GtkWidget *p;
  GtkWidget *i;
  GtkWidget *Rol;
  GtkWidget *calendar;
  GtkWidget *ajout,*min1;
  char u1[100],passw[100],N[100],P[100];
  char I[100],D[100],S[100];
  int r,jour,mois,annee,Mois1;
  char j[100],m[100],an[100];
  utilisateur a;
  GtkWidget *treeview1_user;
  combobox1_choice=lookup_widget(objet,"combobox1_sE");
  calendar=lookup_widget(objet,"calendar1_date");
  n=lookup_widget(objet,"entry4_n");
  p=lookup_widget(objet,"entry5_p");
  u=lookup_widget(objet,"entry6_u");
  pw=lookup_widget(objet,"entry7_p");
  i=lookup_widget(objet,"entry8_id");
  Rol=lookup_widget(objet,"spinbutton2_Ro");
  strcpy(N,gtk_entry_get_text(GTK_ENTRY(n)));
  strcpy(P,gtk_entry_get_text(GTK_ENTRY(p)));
  strcpy(u1,gtk_entry_get_text(GTK_ENTRY(u)));
  strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
  strcpy(I,gtk_entry_get_text(GTK_ENTRY(i)));
  strcpy(S,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_choice)));
  gtk_calendar_get_date(GTK_CALENDAR(calendar),&jour,&mois,&annee);
  Mois1=mois+1;
  sprintf(j,"%d",jour);
  sprintf(m,"%d",Mois1);
  sprintf(an,"%d",annee);
  strcat(an,"/");
  strcat(an,m);
  strcat(an,"/");
  strcat(an,j);
  strcpy(D,an);
  strcpy(a.nom,N);
  strcpy(a.prenom,P);
  strcpy(a.login,u1);
  strcpy(a.password,passw);
  strcpy(a.id,I);
  strcpy(a.date,D);
  strcpy(a.sexe,S);
  a.role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Rol));
  ajouter_i(ch,a);
  ajout=lookup_widget(objet,"ajout_modif");
  gtk_widget_destroy(ajout);
  Gestion=lookup_widget(objet,"Gestion");
  Gestion=create_Gestion();
  gtk_widget_show(Gestion);
  treeview1_user=lookup_widget(Gestion,"treeview1_user"); 
  afficher_u(treeview1_user);
  min1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ajout avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(min1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(min1);
break;
}
}

void
on_button8_modif_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
  char ch[]="user.txt";
  GtkWidget *us;
  GtkWidget *pasw;
  GtkWidget *no;
  GtkWidget *pr;
  GtkWidget *Ro;
  GtkWidget *ide;
  GtkWidget *ajout;
  GtkWidget *Gestion;
  GtkWidget *combobox1_choice;
  GtkWidget *calendar,*my1;
  int jour,mois,annee,Mois1;
  char u1[20],passw[20],N[20],P[20],ID[100],m[100];
  char j[100],M[100],an[100],S[100],D[100];
  char Date[100];
  utilisateur a;
  GtkWidget *treeview1_user; 
  no=lookup_widget(objet,"entry4_n");
  pr=lookup_widget(objet,"entry5_p");
  us=lookup_widget(objet,"entry6_u");
  pasw=lookup_widget(objet,"entry7_p");
  ide=lookup_widget(objet,"entry8_id");
  Ro=lookup_widget(objet,"spinbutton2_Ro");
  combobox1_choice=lookup_widget(objet,"combobox1_sE");
  calendar=lookup_widget(objet,"calendar1_date");
  strcpy(N,gtk_entry_get_text(GTK_ENTRY(no)));
  strcpy(P,gtk_entry_get_text(GTK_ENTRY(pr)));
  strcpy(u1,gtk_entry_get_text(GTK_ENTRY(us)));
  strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pasw)));
  strcpy(ID,gtk_entry_get_text(GTK_ENTRY(ide)));
  strcpy(S,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1_choice)));
  gtk_calendar_get_date(GTK_CALENDAR(calendar),&jour,&mois,&annee);
  a.role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Ro));
  Mois1=mois+1;
  sprintf(j,"%d",jour);
  sprintf(M,"%d",Mois1);
  sprintf(an,"%d",annee);
  strcat(an,"/");
  strcat(an,M);
  strcat(an,"/");
  strcat(an,j);
  strcpy(D,an);
  strcpy(a.nom,N);
  strcpy(a.prenom,P);
  strcpy(a.login,u1);
  strcpy(a.password,passw);
  strcpy(a.id,ID);
  strcpy(a.date,D);
  strcpy(a.sexe,S);
  modifier_no(ch,a);
  ajout=lookup_widget(objet,"ajout_modif");
  gtk_widget_destroy(ajout);
  Gestion=lookup_widget(objet,"Gestion");
  Gestion=create_Gestion();
  gtk_widget_show(Gestion);
  treeview1_user=lookup_widget(Gestion,"treeview1_user"); 
  afficher_u(treeview1_user);
  my1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"modification avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(my1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(my1);
break;
}
}




void
on_button10_Delete_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
  char ch[20]="user.txt";
  int test;
  GtkWidget *ide,*no1,*no2;
  GtkWidget *delete;
  GtkWidget *Gestion;
  GtkWidget *treeview1_user;
  char ID[100];
  ide=lookup_widget(objet,"entry11_Del");
  strcpy(ID,gtk_entry_get_text(GTK_ENTRY(ide)));
  test=chercher(ch,ID);
  if (test==1)
  {
  supprimer(ch,ID);
  delete=lookup_widget(objet,"DELETE");
  gtk_widget_destroy(delete);
  Gestion=lookup_widget(objet,"Gestion");
  Gestion=create_Gestion();
  gtk_widget_show(Gestion);
  treeview1_user=lookup_widget(Gestion,"treeview1_user"); 
  afficher_u(treeview1_user);
   no1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"utilisateur supprimé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(no1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(no1);
break;
  }
}
  else
  {
   no2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Id n'existe pas!");
switch (gtk_dialog_run(GTK_DIALOG(no2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(no2);
break;
  }
  }
}


void
on_treeview1_user_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  
 GtkTreeIter iter;
 gchar* nom;
 gchar* prenom;
 gchar* login;
 gchar* password;
 gint* role;
 gchar* id;
 gchar* date;
 gchar* sexe;
 GtkWidget *treeview1_user;
 utilisateur u;
 GtkTreeModel *model=gtk_tree_view_get_model(treeview);
 if (gtk_tree_model_get_iter(model,&iter,path))
 {
  gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&login,3,&password,4,&role,5,&id,6,&date,7,&sexe,-1);
  strcpy(u.nom,nom);
  strcpy(u.prenom,prenom);
  strcpy(u.login,login);
  strcpy(u.password,password);
  strcpy(u.id,id);
  u.role=role;
  strcpy(u.date,date);
  strcpy(u.sexe,sexe);
  supprimer("user.txt",u.id);
  afficher_u(treeview);
  
}
}





void
on_button1_aff_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *treeview1_user;
   treeview1_user=lookup_widget(objet,"treeview1_user"); 
   afficher_u(treeview1_user);
}


void
on_checkbutton1_xo_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 if (gtk_toggle_button_get_active(togglebutton))
{
to[1]=1;
} 
else
{
to[1]=0;
}
}

void
on_button1_aq_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Gestion;
    GtkWidget *ajout;
    GtkWidget *treeview1_user;
    ajout=lookup_widget(button,"ajout_modif");
    gtk_widget_destroy(ajout);
    Gestion=lookup_widget(button,"Gestion");
    Gestion=create_Gestion();
    gtk_widget_show(Gestion);
    treeview1_user=lookup_widget(Gestion,"treeview1_user"); 
    afficher_u(treeview1_user);
}


void
on_button2_kn_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *Gestion;
    GtkWidget *Del;
    GtkWidget *treeview1_user;
    Del=lookup_widget(button,"DELETE");
    gtk_widget_destroy(Del);
    Gestion=lookup_widget(button,"Gestion");
    Gestion=create_Gestion();
    gtk_widget_show(Gestion);
    treeview1_user=lookup_widget(Gestion,"treeview1_user"); 
    afficher_u(treeview1_user);
}





void
on_button1_ax_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
char texte[100],Nom[100],Prenom[100],Log[100],Passw[100],iden[100],ch[100]="utilisateur inexistant",m[100];
GtkWidget *ID,*mine2,*mine3;
GtkWidget *r;
GtkWidget *entry4;
GtkWidget *entry5;
GtkWidget *entry6;
GtkWidget *entry7;
char Iden[100],Date[100],Sexe[100];
int Role,test;
GtkWidget* output;
utilisateur u;
FILE *f=NULL;
f=fopen("user.txt","r");
ID=lookup_widget(objet,"entry8_id");
r=lookup_widget(objet,"spinbutton2_Ro");
strcpy(Iden,gtk_entry_get_text(GTK_ENTRY(ID)));
test=chercher("user.txt",Iden);
if (test==1)
{
if (f!=NULL) 
{
while(fscanf(f,"%s %s %s %s %d %s %s %s",Nom,Prenom,Log,Passw,&Role,iden,Date,Sexe)!=EOF)
{
if (strcmp(iden,Iden)==0)
{
mine2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"utilisateur trouvé avec succés!");
switch (gtk_dialog_run(GTK_DIALOG(mine2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(mine2);
break;
}
strcpy(u.nom,Nom);
strcpy(u.prenom,Prenom);
strcpy(u.login,Log);
strcpy(u.password,Passw);
strcpy(u.id,iden);
u.role=Role;
entry4=lookup_widget(objet,"entry4_n");
entry5=lookup_widget(objet,"entry5_p");
entry6=lookup_widget(objet,"entry6_u");
entry7=lookup_widget(objet,"entry7_p");
gtk_entry_set_text(GTK_ENTRY(ID),u.id);
gtk_entry_set_text(GTK_ENTRY(entry7),u.password);
gtk_entry_set_text(GTK_ENTRY(entry6),u.login);
gtk_entry_set_text(GTK_ENTRY(entry5),u.prenom);
gtk_entry_set_text(GTK_ENTRY(entry4),u.nom);
gtk_spin_button_set_value(r,u.role);
break;
}
}
}
to[1]=0;
}
else
{
mine3=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'utilisateurs avec un tel ID!");
switch (gtk_dialog_run(GTK_DIALOG(mine3)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(mine3);
break;
}
}
}

void
on_button1_Bn_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Gestion,*admin;
  GtkWidget *treeview1_user;
     admin=lookup_widget(objet,"admin");
     gtk_widget_destroy(admin);
     Gestion=lookup_widget(objet,"Gestion");
     Gestion=create_Gestion();
     gtk_widget_show(Gestion);
     treeview1_user=lookup_widget(Gestion,"treeview1_user"); 
     afficher_u(treeview1_user);
}


void
on_button2_Vc_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
   GtkWidget *Statistiques,*admin;
   admin=lookup_widget(objet,"admin");
     gtk_widget_destroy(admin);
     Statistiques=lookup_widget(objet,"Dashboard");
     Statistiques=create_Dashboard();
     gtk_widget_show(Statistiques); 
}






void
on_button1_Sz_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
   GtkWidget *Gestion;
    GtkWidget *Dashboard;
    Dashboard=lookup_widget(button,"Dashboard");
    gtk_widget_destroy(Dashboard);
    Gestion=lookup_widget(button,"Gestion");
    Gestion=create_Gestion();
    gtk_widget_show(Gestion);
}

void
on_button2_AFf_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* output;
FILE *f=NULL;
FILE *g=NULL;
char m[100],message[10],er[100];
int jour,heure,num_capteur;
char valeur_debit[10];
f=fopen("debit.txt","r");
g=fopen("dash.txt","a+");
if (f!=NULL )
{
while (fscanf(f,"%d %d %d %s \n",&jour,&heure,&num_capteur,&valeur_debit)!=EOF)
{
printf("%d %d %d %d %s \n",jour,heure,num_capteur,valeur_debit);
if (atoi(valeur_debit)>30)
{
if (g!=NULL)
{
fprintf(g,"%d %d %d %s\n",jour,heure,num_capteur,valeur_debit);
}
}
}
fclose(f);
fclose(g);
}
g=fopen("dash.txt","r");
if (g!=NULL)
{
while (fscanf(g,"%d %d %d %s \n",&jour,&heure,&num_capteur,&valeur_debit)!=EOF)
{
strcpy(message,"l'etage ");
sprintf(er,"%d",num_capteur);
strcat(message,er);
sprintf(m,"%s\n",message);
break;
}
fclose(g);
}
output=lookup_widget(button,"label39_das");
gtk_label_set_text(GTK_LABEL(output),m);
}


void
on_radiobutton1_h_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
   if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xo=1;
}
}


void
on_radiobutton2_f_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
xo=0;
}
}


void
on_button1_GH_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
  GtkWidget *dad1,*dad2,*dad3,*dad4;
  if (xo==1)
{
GtkWidget *treeview1_user;
   treeview1_user=lookup_widget(objet,"treeview1_user");
   if (chercher_homme("user.txt")==1)
   {
      dad1=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"utilisateur trouve avec succes selon sexe!");
switch (gtk_dialog_run(GTK_DIALOG(dad1)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(dad1);
break; 
}
   rechercher_homme(treeview1_user);
   }
else
{
  dad2=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'utilisateurs selon ce sexe!");
switch (gtk_dialog_run(GTK_DIALOG(dad2)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(dad2);
break; 
}
}
}
else
{
   GtkWidget *treeview1_user;
   treeview1_user=lookup_widget(objet,"treeview1_user"); 
   if (chercher_femme("user.txt")==1)
   {
      dad3=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"utilisateur trouve avec succes selon sexe!");
switch (gtk_dialog_run(GTK_DIALOG(dad3)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(dad3);
break; 
}
   rechercher_femme(treeview1_user);
   }
else
{
  dad4=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"pas d'utilisateurs selon ce sexe!");
switch (gtk_dialog_run(GTK_DIALOG(dad4)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(dad4);
break; 
}
}
}
}



void
on_button2_etud_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button3_af_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_ar_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button5_nut_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button6_tec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_Seeee_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_search_close                        (GtkDialog       *dialog,
                                        gpointer         user_data)
{
  
}


void
on_button1_Ver_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_Mv_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_tit_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_Okv_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}

















void
on_button11_AmDa_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion;
    GtkWidget *tous;
    Gestion=lookup_widget(button,"Gestion");
    gtk_widget_destroy(Gestion);
    tous=lookup_widget(button,"tous");
    tous=create_tous();
    gtk_widget_show(tous);
}







void
on_buttonfedi_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *class;
class=lookup_widget(objet_graphique,"comboboxentry4");
char class1[20];
strcpy(class1,gtk_combo_box_get_active_text(GTK_COMBO_BOX(class)));
int n;
printf("\n %s",class1);
n=tache_etudiant(class1);
printf("\n %d",n);
char ch[20];
sprintf(ch,"%d",n);

GtkWidget *output;
output=lookup_widget(objet_graphique,"fedi");
gtk_label_set_text(GTK_LABEL(output),ch);
}


void
on_buttonnada_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tous;
    GtkWidget *serviceplusreclame;
    tous=lookup_widget(button,"tous");
    gtk_widget_destroy(tous);
    serviceplusreclame=lookup_widget(button,"serviceplusreclame");
    serviceplusreclame=create_serviceplusreclame();
    gtk_widget_show(serviceplusreclame);

}


void
on_buttonhela_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tous;
    GtkWidget *serviceplusreclame;
    tous=lookup_widget(button,"tous");
    gtk_widget_destroy(tous);
    serviceplusreclame=lookup_widget(button,"dash");
    serviceplusreclame=create_dash();
    gtk_widget_show(serviceplusreclame);
}


void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tous;
    GtkWidget *serviceplusreclame;
    tous=lookup_widget(button,"tous");
    gtk_widget_destroy(tous);
    serviceplusreclame=lookup_widget(button,"ichraktache2");
    serviceplusreclame=create_ichraktache2();
    gtk_widget_show(serviceplusreclame);
   
    
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tous;
    GtkWidget *serviceplusreclame;
    tous=lookup_widget(button,"window1menu");
    gtk_widget_destroy(tous);
    serviceplusreclame=lookup_widget(button,"tous");
serviceplusreclame=create_tous();
    gtk_widget_show(serviceplusreclame);
}


void
on_button13_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"tous");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"Dashboard");
    dashboard=create_Dashboard();
    gtk_widget_show(dashboard);
}

//////////////////////chahine tache 222222222222222
void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"tous");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"login");
    dashboard=create_login();
    gtk_widget_show(dashboard);
}


void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"choisir");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"login");
    dashboard=create_login();
    gtk_widget_show(dashboard);
}


void
on_button17_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"window1menu");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"login");
    dashboard=create_login();
    gtk_widget_show(dashboard);
}


void
on_button18_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"Gestion");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"login");
    dashboard=create_login();
    gtk_widget_show(dashboard);
}


void
on_button19_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"window_etudiant_ajouter");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"window_etudiant");
    dashboard=create_window_etudiant();
    gtk_widget_show(dashboard);
}


void
on_button20_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"window_etudiant_modifier");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"window_etudiant");
    dashboard=create_window_etudiant();
    gtk_widget_show(dashboard);
}


void
on_button21_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
    GtkWidget *tous;
    tous=lookup_widget(button,"window4");
    gtk_widget_destroy(tous);
    dashboard=lookup_widget(button,"window_etudiant");
    dashboard=create_window_etudiant();
    gtk_widget_show(dashboard);
}

