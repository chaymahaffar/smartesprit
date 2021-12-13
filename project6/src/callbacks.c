#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "reclamation.h"
#include "callbacks.h"
#include "interface.h"
#include "support.h"
int x,y;

void
on_radiobutton_homme_reclam_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=0;
}


void
on_radiobutton_femme_reclam_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		x=1;
}


void
on_checkbutton_prepa_reclam_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=0;
}


void
on_checkbutton_ing_reclam_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=1;
}


void
on_checkbutton_business_reclam_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		y=2;
}


void
on_button_ajouter_reclam_clicked       (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
reclamation r;
	GtkWidget *id,*cin,*nom,*prenom,*type,*text_reclamation,*jour,*mois,*annee;
	id=lookup_widget(objet_graphique,"entry_id_reclam");
	cin=lookup_widget(objet_graphique,"entry_cin_reclam");
	nom=lookup_widget(objet_graphique,"entry_nom_reclam");
	prenom=lookup_widget(objet_graphique,"entry_prenom_reclam");
	type=lookup_widget(objet_graphique,"combobox_reclam");
	text_reclamation=lookup_widget(objet_graphique,"entryreclam");
	jour=lookup_widget(objet_graphique,"spinbutton_jour_reclam");
	mois=lookup_widget(objet_graphique,"spinbutton_mois_reclam");
	annee=lookup_widget(objet_graphique,"spinbutton_annee_reclam");
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(r.text_reclamation,gtk_entry_get_text(GTK_ENTRY(text_reclamation)));
	r.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	r.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	if(strcmp("Service d'hebergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		r.type=0;
	else
		r.type=1;
	r.sexe=x;
	r.education=y;
	if(existe(r.id)==0)
	{	
		ajouter_reclamation(r);
		GtkWidget *dialog_succes_ajout_reclam;
		dialog_succes_ajout_reclam=create_dialog_succes_ajout_reclam() ;
		gtk_widget_show(dialog_succes_ajout_reclam) ;
	}
	else
	{
		GtkWidget *dialog_echec_ajout_reclam;
		dialog_echec_ajout_reclam=create_dialog_echec_ajout_reclam() ;
		gtk_widget_show(dialog_echec_ajout_reclam) ;
	}
}


void
on_button_modifier_reclam_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
reclamation r;
	int ex=1;
	GtkWidget *id,*cin,*nom,*prenom,*type,*text_reclamation,*jour,*mois,*annee;
	id=lookup_widget(objet_graphique,"entry_id_reclam");
	cin=lookup_widget(objet_graphique,"entry_cin_reclam");
	nom=lookup_widget(objet_graphique,"entry_nom_reclam");
	prenom=lookup_widget(objet_graphique,"entry_prenom_reclam");
	type=lookup_widget(objet_graphique,"combobox_reclam");
	text_reclamation=lookup_widget(objet_graphique,"entryreclam");
	jour=lookup_widget(objet_graphique,"spinbutton_jour_reclam");
	mois=lookup_widget(objet_graphique,"spinbutton_mois_reclam");
	annee=lookup_widget(objet_graphique,"spinbutton_annee_reclam");
	strcpy(r.id,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(cin)));
	strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(r.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(r.text_reclamation,gtk_entry_get_text(GTK_ENTRY(text_reclamation)));
	r.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	r.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	r.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
	if(strcmp("Service d'hebergement",gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)))==0)
		r.type=0;
	else
		r.type=1;
	r.sexe=x;
	r.education=y;
	ex=existe(r.id);
	if(ex==1)
	{
		modifier_reclamation(r);
		GtkWidget *dialog_succes_modif_reclam;
		dialog_succes_modif_reclam=create_dialog_succes_modif_reclam() ;
		gtk_widget_show(dialog_succes_modif_reclam) ;
	}
	else
	{
		GtkWidget *dialog_echec_modif_reclam;
		dialog_echec_modif_reclam=create_dialog_echec_modif_reclam() ;
		gtk_widget_show(dialog_echec_modif_reclam) ;
	}
}


void
on_button_afficher_reclam_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_afficher_reclam,*window_gestion_reclam,*treeview1;
	window_afficher_reclam=lookup_widget(objet_graphique,"window_afficher_reclam");
	window_gestion_reclam=lookup_widget(objet_graphique,"window_gestion_reclam");
	gtk_widget_destroy(window_gestion_reclam);
	window_afficher_reclam=create_window_afficher_reclam();
	gtk_widget_show(window_afficher_reclam);
	treeview1=lookup_widget(window_afficher_reclam,"treeview1");
	afficher_reclamation(treeview1,"reclamation.txt");
	
}


void
on_button_rechercher_reclam_clicked    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *cin,*treeview_reclamation;
	char cin1[20];
	cin=lookup_widget(objet_graphique,"entry_recherche_cin_reclam");
	treeview_reclamation=lookup_widget(objet_graphique,"treeview1");
	strcpy(cin1,gtk_entry_get_text(GTK_ENTRY(cin)));
	if(strcmp(cin1,"")!=0)
	{
		recherche_reclamation(cin1);
		afficher_reclamation(treeview_reclamation,"recherche.txt");
		remove("recherche.txt");
	}
	else
		afficher_reclamation(treeview_reclamation,"reclamation.txt");
}


void
on_button_go_to_ajouter_reclam_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_afficher_reclam,*window_gestion_reclam,*treeview_reclamation;
	window_afficher_reclam=lookup_widget(objet_graphique,"window_afficher_reclam");
	window_gestion_reclam=lookup_widget(objet_graphique,"window_gestion_reclam");
	gtk_widget_destroy(window_afficher_reclam);
	window_gestion_reclam=create_window_gestion_reclam();
	gtk_widget_show(window_gestion_reclam);

}


void
on_button_go_to_modifier_reclam_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_gestion_reclam,*window_afficher_reclam;
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview;
	
	
        gchar* id;
	gchar* cin;
	gchar* nom;
	gchar* prenom;
	gchar* text;
	gint sexe;
	gint education;
	gint jour;
	gint mois;
	gint annee;
	gint type;
	window_afficher_reclam=lookup_widget(objet_graphique,"window_afficher_reclam");
        treeview=lookup_widget(window_afficher_reclam,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&id,1,&cin,2,&nom,3,&prenom,4,&type,5,&jour,6,&mois,7,&annee,8,&text,9,&sexe,10,&education,-1);
		gtk_widget_destroy(window_afficher_reclam);
		window_gestion_reclam=lookup_widget(objet_graphique,"window_gestion_reclam");
		window_gestion_reclam=create_window_gestion_reclam();
		gtk_widget_show(window_gestion_reclam);
	        gtk_entry_set_text(GTK_ENTRY(lookup_widget(window_gestion_reclam,"entry_id_reclam")),id);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(window_gestion_reclam,"entry_cin_reclam")),cin);
                gtk_entry_set_text(GTK_ENTRY(lookup_widget(window_gestion_reclam,"entry_nom_reclam")),nom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(window_gestion_reclam,"entry_prenom_reclam")),prenom);

gtk_entry_set_text(GTK_ENTRY(lookup_widget(window_gestion_reclam,"entryreclam")),text);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(window_gestion_reclam,"spinbutton_jour_reclam")),jour);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(window_gestion_reclam,"spinbutton_mois_reclam")),mois);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(window_gestion_reclam,"spinbutton_annee_reclam")),annee);
		gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(window_gestion_reclam,"combobox_reclam")),type);

	}
}


void
on_button_supprimer_reclam_clicked     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *windowajouter_reclamation,*windowafficher_reclamation;
	GtkTreeModel  *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* treeview;
	
	
        gchar* id;
	
	windowafficher_reclamation=lookup_widget(objet_graphique,"window_afficher_reclam");
        treeview=lookup_widget(windowafficher_reclamation,"treeview1");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {
		gtk_tree_model_get (model,&iter,0,&id,-1);
		supprimer_reclamation(id);
		afficher_reclamation(treeview,"reclamation.txt");
		
	}
}


void
on_closebutton1_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        gtk_widget_destroy(lookup_widget(objet_graphique,"dialog_echec_ajout_reclam"));
}


void
on_closebutton2_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
     gtk_widget_destroy(lookup_widget(objet_graphique,"dialog_succes_ajout_reclam"));
}


void
on_closebutton3_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
       gtk_widget_destroy(lookup_widget(objet_graphique,"dialog_echec_modif_reclam"));
}


void
on_closebutton4_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        gtk_widget_destroy(lookup_widget(objet_graphique,"dialog_succes_modif_reclam"));

}



void
on_button_dashboard_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
        GtkWidget *window_afficher_reclam,*window_dashboard_reclam;
	window_afficher_reclam=lookup_widget(objet_graphique,"window_afficher_reclam");
	window_dashboard_reclam=lookup_widget(objet_graphique,"window_dashboard_reclam");
	gtk_widget_destroy(window_afficher_reclam);
	window_dashboard_reclam=create_window_dashboard_reclam();
	gtk_widget_show(window_dashboard_reclam);

}


void
on_button_service_plus_reclame_clicked (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
	int r;
	GtkWidget *resultat;
	resultat=lookup_widget(objet_graphique,"label_service_plus_reclame");
	r=serviceleplusreclame();
	if(r==0)
		gtk_label_set_text(GTK_LABEL(resultat),"Le service le plus reclamé est : Service d'hebergement");
	else
		gtk_label_set_text(GTK_LABEL(resultat),"Le service le plus reclamé est : Service de restauration");
}


void
on_button_retour_reclam_clicked        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window_afficher_reclam,*window_dashboard_reclam,*treeview_reclamation;
	window_afficher_reclam=lookup_widget(objet_graphique,"window_afficher_reclam");
	window_dashboard_reclam=lookup_widget(objet_graphique,"window_dashboard_reclam");
	gtk_widget_destroy(window_dashboard_reclam);
	window_afficher_reclam=create_window_afficher_reclam();
	gtk_widget_show(window_afficher_reclam);
	treeview_reclamation=lookup_widget(window_afficher_reclam,"treeview_reclamation");
	afficher_reclamation(treeview_reclamation,"reclamation.txt");
}

