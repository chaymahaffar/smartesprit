#include <gtk/gtk.h>


void
on_radiobutton_homme_reclam_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_femme_reclam_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_prepa_reclam_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_ing_reclam_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_business_reclam_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_reclam_clicked       (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_reclam_clicked      (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_afficher_reclam_clicked      (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_rechercher_reclam_clicked    (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_go_to_ajouter_reclam_clicked (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_go_to_modifier_reclam_clicked
                                        (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_supprimer_reclam_clicked     (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_closebutton1_clicked                (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_closebutton2_clicked                (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_closebutton3_clicked                (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_closebutton4_clicked                (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_dashboard_clicked            (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_service_plus_reclame_clicked (GtkWidget        *objet_graphique,
                                        gpointer         user_data);

void
on_button_retour_reclam_clicked        (GtkWidget        *objet_graphique,
                                        gpointer         user_data);
