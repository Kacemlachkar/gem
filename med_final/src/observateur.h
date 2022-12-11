#ifndef OBSERVATEUR_H_INCLUDED
#define OBSERVATEUR_H_INCLUDED
#include <stdio.h>
#include<gtk/gtk.h>
typedef struct {
char id[30];
char nom[30];
char prenom[30];
char genre[30];
char nationalite[30];
char appartenance[30];
}obs;

void ajouter(obs);
void modifier(obs);
void supprimer(obs);
obs chercher(char[]);
void afficher(GtkWidget *liste);
void vider(GtkWidget *liste);
int nbobservateur();
void taux(float *,float *);


#endif
