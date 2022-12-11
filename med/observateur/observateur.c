#include "observateur.h"
#include<stdio.h>
#include<string.h>
//#include<gtk/gtk.h>
/*enum
{
	ID,
	NOM,
	PRENOM,
	GENRE,
	NATIONALITE,
	APPARTENANCE,
	COLUMNS
};*/
int ajouter(char * observateur, obs p )
{
    FILE * f=fopen(observateur, "a");
    if(f!=NULL)
    {
    fprintf(f,"%d %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier( char * observateur, int id, obs nouv)
{
obs p;
    FILE * f=fopen(observateur, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %s %s %s",&p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance);
else

  fprintf(f2,"%d %s %s %s %s %s\n",nouv.id,nouv.nom,nouv.prenom,nouv.genre,nouv.nationalite,nouv.appartenance);

}
        fclose(f);
        fclose(f2);
remove(observateur);
rename("aux.txt", observateur);
        return 1;
    }
  
}

int supprimer(char * observateur, int id)
{
obs p;
    FILE * f=fopen(observateur, "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %s %s %s",&p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d %s %s %s %s %s\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance);

}
        fclose(f);
        fclose(f2);
remove(observateur);
rename("aux.txt", observateur);
        return 1;
    }
}

obs chercher(char * observateur, int id)
{
obs p; int tr=0;
    FILE * f=fopen(observateur, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %s %s %s",&p.id,p.nom,p.prenom,p.genre,p.nationalite,p.appartenance)!=EOF && tr==0)
{if(id==p.id)
tr=1;
}
}
if(tr==0)
p.id=-1;
return p;
}
/*void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	
	int id;
	char nom[20];
	char prenom[20];
	char genre[20];
	char nationalite[20];
	char appartenance[20];
	store=NULL;

	if(store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id", renderer, "text",ID,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom", renderer, "text",NOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom", renderer, "text",PRENOM,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("genre", renderer, "text",GENRE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nationalite", renderer, "text",NATIONALITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("appartenance", renderer, "text",APPARTENANCE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

store=gtk_list_store_new(COLUMNS, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

FILE * f=fopen("observateur.txt","r");
if(f==NULL)
{
return;
}
else
{
FILE * f=fopen("observateur.txt","a+");
	while(fscanf(f,"%d %s %s %s %s %s \n",id,nom,prenom,genre,nationalite,appartenance)!=EOF)
  {
gtk_list_store_append (store, &iter);

gtk_list_store_set (store, &iter,ID,id,NOM,nom,PRENOM,prenom,GENRE,genre,NATIONALITE,nationalite,APPARTENANCE,appartenance, -1);
  }
  fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
}*/
