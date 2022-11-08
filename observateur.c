#include "observateur.h"
#include<stdio.h>
int ajouter(obs p , char observateur[])
{
    FILE * f=fopen("observateur.txt", "a");
    if(f!=NULL)
    {
    fprintf(f,"%d %s %s %d %s %d\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.profession);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier(int id, obs nouv, char * observateur)
{
obs p;
    FILE * f=fopen("observateur.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %d %s %d",&p.id,p.nom,p.prenom,&p.genre,p.nationalite,&p.profession)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d %s %s %d %s %d\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.profession);
else

  fprintf(f2,"%d %s %s %d %s %d\n",nouv.id,nouv.nom,nouv.prenom,nouv.genre,nouv.nationalite,nouv.profession);

}
        fclose(f);
        fclose(f2);
remove("observateur.txt");
rename("aux.txt", "observateur.txt");
        return 1;
    }
  
}

int supprimer(int id, char * observateur)
{
obs p;
    FILE * f=fopen("observateur.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%d %s %s %d %s %d",&p.id,p.nom,p.prenom,&p.genre,p.nationalite,&p.profession)!=EOF)
{
if(p.id!=id)
        fprintf(f2,"%d %s %s %d %s %d\n",p.id,p.nom,p.prenom,p.genre,p.nationalite,p.profession);

}
        fclose(f);
        fclose(f2);
remove("observateur.txt");
rename("aux.txt", "observateur.txt");
        return 1;
    }
}

obs chercher(int id, char * observateur)
{
obs p; int tr=0;
    FILE * f=fopen("observateur.txt", "r");
 if(f!=NULL )
    {
while(fscanf(f,"%d %s %s %d %s %d",&p.id,p.nom,p.prenom,&p.genre,p.nationalite,&p.profession)!=EOF && tr==0)
{if(id==p.id)
tr=1;
}
}
if(tr==0)
p.id=-1;
return p;

}
