#include "observateur.h"
#include<stdio.h>
#include<string.h>
#include<gtk/gtk.h>

enum
{
	EID,
	ENOM,
	EPRENOM,
	EGENRE,
	ENATIONALITE,
	EAPPARTENANCE,
	COLUMNS,
};
void ajouter( obs p )
{
    FILE * f;
    f=fopen("observateur.txt", "a");
    if(f!=NULL)
    {
    fprintf(f,"%s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance);
        fclose(f);
}
}
void modifier(obs nouv)
{
obs p;
FILE * f,*f2;
f=fopen("observateur.txt", "r");
f2 =fopen("aux.txt", "a");
    if(f!=NULL){
	while(fscanf(f,"%s %s %s %s %s %s",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF)
	{
		if(strcmp(p.id,nouv.id)!=0)
        		fprintf(f2,"%s %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance);
		else

  			fprintf(f2,"%s %s %s %s %s %s\n",nouv.id,nouv.nom,nouv.prenom,nouv.genre,nouv.nationalite,nouv.appartenance);

	}
	}
        fclose(f);
        fclose(f2);
remove("observateur.txt");
rename("aux.txt","observateur.txt"); 
}

void supprimer(obs p)
{
	char id[30];
	char nom[30];
	char prenom[30];
	char genre[30];
	char nationalite[30];
	char appartenance[30];
FILE *f,*f2;
f=fopen("observateur.txt", "r");
f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
  	{
   	return;
  	}
    else
    {
	while(fscanf(f,"%s %s %s %s %s %s",id,nom,prenom,genre,nationalite,appartenance)!=EOF)
	{
		if(strcmp(p.id,id)!=0 || strcmp(p.nom,nom)!=0 || strcmp(p.prenom,prenom)!=0 || strcmp(p.genre,genre)!=0 || strcmp(p.nationalite,nationalite)!=0 || strcmp(p.appartenance,appartenance) !=0  )
        		fprintf(f2,"%s %s %s %s %s %s\n",id,nom,prenom,genre,nationalite,appartenance);
	}
        fclose(f);
        fclose(f2);
    remove("observateur.txt");
    rename("aux.txt", "observateur.txt");
    }
}
obs chercher(char id[])
{
obs p;
int tr=0;
FILE * f=NULL;
f=fopen("observateur.txt", "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %s %s %s",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF)
{if(strcmp(p.id,id)==0)
{
fclose(f);
return (p);}
}
}
}
void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char prenom[30];
	char genre[30];
	char nationalite[30];
	char appartenance[30];
	store=NULL;
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nationalite", renderer, "text",ENATIONALITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("appartenance", renderer, "text",EAPPARTENANCE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

 f=fopen("observateur.txt","r");
if(f==NULL)
{
return;
}
else
{
f=fopen("observateur.txt","a+");
while(fscanf(f,"%s %s %s %s %s %s \n",id,nom,prenom,genre,nationalite,appartenance)!=EOF)
  {
	gtk_list_store_append (store, &iter);
	gtk_list_store_set(store,&iter,EID,id,ENOM,nom,EPRENOM,prenom,EGENRE,genre,ENATIONALITE,nationalite,EAPPARTENANCE,appartenance, -1);
  }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}
void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	char id[30];
	char nom[30];
	char prenom[30];
	char genre[30];
	char nationalite[30];
	char appartenance[30];
	store=NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",EID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",ENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",EPRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",EGENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nationalite", renderer, "text",ENATIONALITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("appartenance", renderer, "text",EAPPARTENANCE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
gtk_list_store_append (store, &iter);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
int nbobservateur()
{
obs p;
int nb=0;
 FILE * f=fopen("observateur.txt", "r");
 if(f!=NULL )
    {
	while(fscanf(f,"%s %s %s %s %s %s",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF){
		nb++;
	}
    }
fclose(f);
return(nb);
}
void taux(float *tn ,float *te)
{
obs p;
int nbn=0;
int nbe=0;
int nb0;
nb0=nbobservateur();
FILE * f=fopen("observateur.txt", "r");
if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %s %s %s",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF)
{
if(strcmp(p.nationalite,"etranger")==0)
nbe++;
else
nbn++;
}
}
*te=(float)nbe/nb0*100;
*tn=(float)nbn/nb0*100;
fclose(f);
}


