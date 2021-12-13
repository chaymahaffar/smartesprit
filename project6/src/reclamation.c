#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reclamation.h"
enum{
	RID,
	RCIN,
	RNOM,
	RPRENOM,
	RTYPE,
	RJOUR,
	RMOIS,
	RANNEE,
	RRECLAMATION,
	RSEXE,
	REDUCATION,
	COLUMNS
};
void ajouter_reclamation(reclamation r){
	FILE *f;
	f=fopen("reclamation.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,r.type,r.text_reclamation,r.d.jour,r.d.mois,r.d.annee,r.sexe,r.education);
	}
	else
		return;
	fclose(f);
}
void supprimer_reclamation(char id[20]){
	reclamation r;
	FILE *f,*g;
	f=fopen("reclamation.txt","r");
	g=fopen("tmp.txt","a+");
	if(f!=NULL && g!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,&r.type,r.text_reclamation,&r.d.jour,&r.d.mois,&r.d.annee,&r.sexe,&r.education)!=EOF)
		{
			if(strcmp(id,r.id)!=0)
				fprintf(g,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,r.type,r.text_reclamation,r.d.jour,r.d.mois,r.d.annee,r.sexe,r.education);
		}

	
	}
	fclose(f);
	fclose(g);
	remove("reclamation.txt");
	rename("tmp.txt","reclamation.txt");
}

void modifier_reclamation(reclamation r){
	reclamation r1;
	FILE *f,*g;
	f=fopen("reclamation.txt","r");
	g=fopen("tmp.txt","a+");
	if(f!=NULL && g!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r1.id,r1.cin,r1.nom,r1.prenom,&r1.type,r1.text_reclamation,&r1.d.jour,&r1.d.mois,&r1.d.annee,&r1.sexe,&r1.education)!=EOF)
		{
			if(strcmp(r1.id,r.id)!=0)
				fprintf(g,"%s %s %s %s %d %s %d %d %d %d %d\n",r1.id,r1.cin,r1.nom,r1.prenom,r1.type,r1.text_reclamation,r1.d.jour,r1.d.mois,r1.d.annee,r1.sexe,r1.education);
			else
				fprintf(g,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,r.type,r.text_reclamation,r.d.jour,r.d.mois,r.d.annee,r.sexe,r.education);		
		}

	
	}
	fclose(f);
	fclose(g);
	remove("reclamation.txt");
	rename("tmp.txt","reclamation.txt");
}
void recherche_reclamation(char cin[20]){
	reclamation r1;
	FILE *f,*g;
	f=fopen("reclamation.txt","r");
	g=fopen("recherche.txt","a+");
	if(f!=NULL && g!=NULL){
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r1.id,r1.cin,r1.nom,r1.prenom,&r1.type,r1.text_reclamation,&r1.d.jour,&r1.d.mois,&r1.d.annee,&r1.sexe,&r1.education)!=EOF)
		{
			if(strcmp(cin,r1.cin)==0)
				fprintf(g,"%s %s %s %s %d %s %d %d %d %d %d\n",r1.id,r1.cin,r1.nom,r1.prenom,r1.type,r1.text_reclamation,r1.d.jour,r1.d.mois,r1.d.annee,r1.sexe,r1.education);
				
		}
	}
	fclose(f);
	fclose(g);

}

void afficher_reclamation(GtkWidget *liste, char file[20])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter ;
	GtkListStore *store;
	reclamation r;
	char sexe[20];
	char type[20];
	char education[20];
	store=NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",RID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",RCIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",RNOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column); 

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",RPRENOM,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
 
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Type",renderer,"text",RTYPE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Jour",renderer,"text",RJOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Mois",renderer,"text",RMOIS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Annee",renderer,"text",RANNEE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Reclamation",renderer,"text",RRECLAMATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("SEXE",renderer,"text",RSEXE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("Education",renderer,"text",REDUCATION,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		 
	}
		  
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	f=fopen(file,"r");
	if(f==NULL){return;}
	else
	{
		 while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,&r.type,r.text_reclamation,&r.d.jour,&r.d.mois,&r.d.annee,&r.sexe,&r.education)!=EOF)
		 {
			if(r.sexe==0)
				strcpy(sexe,"Homme");
			else
				strcpy(sexe,"Femme");
			if(r.type==0)
				strcpy(type,"Hebergement");
			else
				strcpy(type,"Restauration");
			if(r.education==0)
				strcpy(education,"Prepa");
			else if(r.education==1)
				strcpy(education,"Ingenieur");
			else
				strcpy(education,"Bussiness");
			gtk_list_store_append(store,&iter);
		  	gtk_list_store_set(store,&iter,RID,r.id,RCIN,r.cin,RNOM,r.nom,RPRENOM,r.prenom,RTYPE,type,RJOUR,r.d.jour,RMOIS,r.d.mois,RANNEE,r.d.annee,RRECLAMATION,r.text_reclamation,RSEXE,sexe,REDUCATION,education,-1);
		 }
	 fclose(f);
	 gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	 g_object_unref(store);
	}
}
int serviceleplusreclame()
{
	int s=0,s1=0;
	FILE *f;
	reclamation r;
	f=fopen("reclamation.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,&r.type,r.text_reclamation,&r.d.jour,&r.d.mois,&r.d.annee,&r.sexe,&r.education)!=EOF)
		{
			if(r.type==0)
				s++;
			else
				s1++;
		}
		fclose(f);
	}
	if(s>s1)
		return 0;
	else
		return 1;
	
		
}
int existe(char id[20])
{
	FILE *f;
	reclamation r;
	f=fopen("reclamation.txt","r");
	if(f!=NULL)
	{
		while(fscanf(f,"%s %s %s %s %d %s %d %d %d %d %d\n",r.id,r.cin,r.nom,r.prenom,&r.type,r.text_reclamation,&r.d.jour,&r.d.mois,&r.d.annee,&r.sexe,&r.education)!=EOF)
		{
			if(strcmp(r.id,id)==0)
				return 1;
		}
		fclose(f);
	}
	return 0;
}




