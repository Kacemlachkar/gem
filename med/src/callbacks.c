#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "observateur.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "string.h"

int sexe=2 ;
int sexe1=2 ;

void
on_obs_valider_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
obs p;
GtkWidget *id,*nom,*prenom;
GtkWidget *ajouterobs;
GtkWidget *nationalite;
GtkWidget *appartenance;
if(sexe==1)
strcpy(p.genre,"homme");
else if(sexe==2)
strcpy(p.genre,"femme");
ajouterobs=lookup_widget(objet, "ajouterobs");
id = lookup_widget(objet, "entryobs1");
nom = lookup_widget(objet, "entryobs2");
prenom = lookup_widget(objet, "entryobs3");
nationalite= lookup_widget(objet, "comboboxobs1");
appartenance= lookup_widget(objet, "comboboxobs2");
strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(p.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(p.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nationalite)));
strcpy(p.appartenance,gtk_combo_box_get_active_text(GTK_COMBO_BOX(appartenance)));
ajouter(p);

}


void
on_obs_afficher_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouterobs;
GtkWidget *fenetre_afficher;
GtkWidget *obs_table;

ajouterobs=lookup_widget(objet, "ajouterobs");

gtk_widget_destroy(ajouterobs);
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

obs_table=lookup_widget(fenetre_afficher, "obs_table");

afficher(obs_table);
}


void
on_obs_table_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar* id;
	gchar* nom;
	gchar* prenom;
	gchar* genre;
	gchar* nationalite;
	gchar* appartenance;

	obs p;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model,&iter,path))
	{

		gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&id,1,&nom,2,&prenom,3,&genre,4,&nationalite,5,&appartenance,-1);
		strcpy(p.id,id);
		strcpy(p.nom,nom);
		strcpy(p.prenom,prenom);
		strcpy(p.genre,genre);
		strcpy(p.nationalite,nationalite);
		strcpy(p.appartenance,appartenance);
		supprimer(p);
		afficher(treeview);
}
}


void
on_obs_supprimer_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerobs;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet, "fenetre_afficher");


gtk_widget_destroy(fenetre_afficher);
supprimerobs=lookup_widget(objet, "supprimerobs");
supprimerobs=create_supprimerobs();

gtk_widget_show(supprimerobs);
}


void
on_obs_ajouter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouterobs;
GtkWidget *fenetre_afficher;

fenetre_afficher=lookup_widget(objet, "fenetre_afficher");


gtk_widget_destroy(fenetre_afficher);
ajouterobs=lookup_widget(objet, "ajouterobs");
ajouterobs=create_ajouterobs();

gtk_widget_show(ajouterobs);

}

void
on_obs_modifier_clicked                (GtkWidget        *objet,
                                        gpointer         user_data)
{
obs o;
GtkWidget *id1,*nom1,*prenom1;
GtkWidget *fenetre_afficher;
GtkWidget *nationalite1;
GtkWidget *appartenance1;
if(sexe1==1)
strcpy(o.genre,"homme");
else if(sexe1==2)
strcpy(o.genre,"femme");
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
id1 = lookup_widget(objet, "entryobs11");
nom1 = lookup_widget(objet, "entryobs22");
prenom1 = lookup_widget(objet, "entryobs33");
nationalite1= lookup_widget(objet, "comboboxobs11");
appartenance1= lookup_widget(objet, "comboboxobs22");
strcpy(o.id,gtk_entry_get_text(GTK_ENTRY(id1)));
strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(nom1)));
strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(prenom1)));
strcpy(o.nationalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nationalite1)));
strcpy(o.appartenance,gtk_combo_box_get_active_text(GTK_COMBO_BOX(appartenance1)));
modifier(o);
}

void
on_obs_femme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))  sexe=2;
}


void
on_obs_homme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))  sexe=1;
}


void
on_obs_actualiser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher,*w1;
GtkWidget *obs_table;

w1=lookup_widget(objet, "fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

gtk_widget_hide(w1);
obs_table = lookup_widget(fenetre_afficher,"obs_table");

//vider(obs_table);
afficher(obs_table);
}


void
on_obs_valider_m_clicked               (GtkWidget     *objet,
                                        gpointer         user_data)
{

}


void
on_stats_clicked                       (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *statistiques,*total,*tauxobse,*tauxobsn;
GtkWidget *fenetre_afficher;
char n[40];
char k[40];
char g[40];
float tn,te;
int nb;
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");

statistiques=lookup_widget(objet, "statistiques");


statistiques=create_statistiques();

gtk_widget_show(statistiques);
total=lookup_widget(statistiques, "total");
tauxobse=lookup_widget(statistiques, "tauxobse");
tauxobsn=lookup_widget(statistiques, "tauxobsn");
	nb=nbobservateur();
	sprintf(n,"%d",nb);
	strcat(n," observateurs");
	taux(&tn,&te);
	sprintf(k,"%f",te);
	strcat(k," : taux des etrangers");
	sprintf(g,"%f",tn);
	strcat(g," : taux des tunisiens");

gtk_label_set_text(GTK_LABEL (total),n);
gtk_label_set_text(GTK_LABEL (tauxobse),k);
gtk_label_set_text(GTK_LABEL (tauxobsn),g);
//gtk_widget_destroy(fenetre_afficher);
}


void
on_obs_non_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerobs;
GtkWidget *fenetre_afficher;

supprimerobs=lookup_widget(objet, "supprimerobs");


gtk_widget_destroy(supprimerobs);
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

}


void
on_obs_oui_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *supprimerobs;
GtkWidget *fenetre_afficher;


supprimerobs=lookup_widget(objet, "supprimerobs");
gtk_widget_destroy(supprimerobs);
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

}


void
on_obs_recherche_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
char id[30];
obs u;
 //GtkWidget *fenetre_afficher;
  GtkWidget *l1;
  GtkWidget *l2;
  GtkWidget *l3;
  GtkWidget *l4;
  GtkWidget *l5;
  GtkWidget *l6;
//fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
l1=lookup_widget(objet,"l1");
l2=lookup_widget(objet,"l2");
l3=lookup_widget(objet,"l3");
l4=lookup_widget(objet,"l4");
l5=lookup_widget(objet,"l5");
l6=lookup_widget(objet,"l6");
GtkWidget *l0;
l0=lookup_widget(objet,"l0");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(l0)));
u=chercher(id);
gtk_label_set_text(GTK_LABEL(l1),u.id);
gtk_label_set_text(GTK_LABEL(l2),u.nom);
gtk_label_set_text(GTK_LABEL(l3),u.prenom);
gtk_label_set_text(GTK_LABEL(l4),u.genre);
gtk_label_set_text(GTK_LABEL(l5),u.nationalite);
gtk_label_set_text(GTK_LABEL(l6),u.appartenance);

}

void
on_obs_quit_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_afficher;
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
gtk_widget_destroy(fenetre_afficher);
}


void
on_obs_retour_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *ajouterobs;
GtkWidget *fenetre_afficher;

ajouterobs=lookup_widget(objet, "ajouterobs");
gtk_widget_destroy(ajouterobs);
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
}


void
on_obs_homme1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))  sexe1=1;
}


void
on_obs_femme2_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))  sexe1=2;
}


void
on_obs_gdo_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_agent_de_bureau_de_vote;
GtkWidget *fenetre_afficher;

espace_agent_de_bureau_de_vote=lookup_widget(objet, "espace_agent_de_bureau_de_vote");

gtk_widget_destroy(espace_agent_de_bureau_de_vote);
fenetre_afficher=lookup_widget(objet, "fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();

gtk_widget_show(fenetre_afficher);

}


void
on_obs_deconnexion_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *espace_agent_de_bureau_de_vote;
espace_agent_de_bureau_de_vote=lookup_widget(objet, "espace_agent_de_bureau_de_vote");
gtk_widget_destroy(espace_agent_de_bureau_de_vote);
}

