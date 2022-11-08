typedef struct observateur {
int id;
char nom[20];
char prenom[20];
int genre;
char nationalite[20];
int profession;
}obs;

int ajouter(obs p , char observateur[]);
int modifier(int id, obs nouv, char * observateur);
int supprimer(int id, char * observateur);
obs chercher(int id, char * observateur);
