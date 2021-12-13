#include <gtk/gtk.h>
typedef struct{
	int jour;
	int mois;
	int annee;
}date;
typedef struct{
	char id[20];
	char cin[20];
	char nom[20];
	char prenom[20];
	int type;
	char text_reclamation[50];
	date d;
	int sexe;
	int education;
	
}reclamation;
void ajouter_reclamation(reclamation r);
void supprimer_reclamation(char id[20]);
void modifier_reclamation(reclamation r);
void afficher_reclamation(GtkWidget *liste,char file[20]);
void recherche_reclamation(char cin[20]);
int serviceleplusreclame();
int existe(char id[20]);
