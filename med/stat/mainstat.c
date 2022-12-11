#include <stdio.h>
#include <string.h>
#include"stat.h"

int main()
{
int nb0;
float tn,te;
nb0=nbobservateur("observateur.txt");
    printf("nombres d'observateurs = %d",nb0);
    taux("observateur.txt",&tn ,&te);
    printf("\nle taux des observateurs nationaux = %f",tn);
    printf("\nle taux des observateurs etrangers = %f\n",te);
}
