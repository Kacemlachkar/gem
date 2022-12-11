#ifndef STAT_H_INCLUDED
#define STAT_H_INCLUDED
#include <stdio.h>
#include<string.h>
typedef struct {
int id;
char nom[20];
char prenom[20];
int genre;
char nationalite[20];
char appartenance[20];
}obs;
int nbobservateur(char *);
void taux(char *,float * ,float *);

#endif
