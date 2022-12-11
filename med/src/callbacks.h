#include <gtk/gtk.h>


void
on_obs_valider_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_afficher_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_table_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_obs_supprimer_clicked               (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_obs_ajouter_clicked                 (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_obs_modifier_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_femme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_obs_homme_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_obs_actualiser_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_valider_m_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_stats_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_non_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_oui_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_obs_recherche_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_quit_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_retour_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_homme1_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_obs_femme2_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_obs_gdo_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_obs_deconnexion_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);
