#include "stat.h"
#include<stdio.h>
#include<string.h>
int nbobservateur(char * observateur)
{
int nb=0;
obs p;
 FILE * f=fopen(observateur, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %d %s %s",&p.id,p.nom,p.prenom,&p.genre,p.nationalite,p.appartenance)!=EOF)
nb++;
return(nb);
}
fclose(f);
}
void taux(char * observateur,float *tn ,float *te)
{
obs p;
int nbn=0;
int nbe=0;
int nb0;
nb0=nbobservateur("observateur.txt");
FILE * f=fopen(observateur, "r");
if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %d %s %s",&p.id,p.nom,p.prenom,&p.genre,p.nationalite,p.appartenance)!=EOF)
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
