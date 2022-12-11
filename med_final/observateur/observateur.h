#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
//#include<gtk/gtk.h>
typedef struct {
int id;
char nom[20];
char prenom[20];
char genre[20];
char nationalite[20];
char appartenance[20];
}obs;

int ajouter(char *, obs );
int modifier( char *, int, obs);
int supprimer(char *, int );
obs chercher(char *, int);
//void afficher(GtkWidget *liste);
#endif
