#include <stdio.h>
#include <string.h>
#include"observateur.h"

int main()
{
    obs o1= {1,"Med","benamor",1,"tunisienne","presse"},o2= {2,"Maryem","mallek",2,"tunisienne","hote",},o3;
    int x=ajouter("observateur.txt", o1);
    if(x==1)
        printf("\najout d'observateur avec succés");
    else printf("\nechec ajout");
    x=modifier("observateur.txt",1, o2 );
    if(x==1)
        printf("\nModification d'observateur avec succés");
    else printf("\nechec Modification");
    x=supprimer("observateur.txt",1 );
    if(x==1)
        printf("\nSuppression d'observateur avec succés");
    else printf("\nechec Suppression");
    o3=chercher("observateur.txt",3);
    if(o3.id==-1)
        printf("\nintrouvable");
   
return 0;
    
}
