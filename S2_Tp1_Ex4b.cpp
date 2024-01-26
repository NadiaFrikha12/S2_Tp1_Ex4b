//Ecrire un programme qui élimine les répétitions d’espaces dans un fichier texte.
//Dans des traitements indépendants les uns des autres, le résultat sera :
//b- Ecrit dans un autre fichier.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	
	FILE *fp, *fp2; 
	char nom[10]; //le nom du fichier à ouvrir
	char nom2[10]; //le nom du nouveau fichier 
	char ligne[100]; //pour désigner chaque ligne du fichier
	int i=0, j=0; //compteurs
	
	//lire le nom du fichier a ouvrir
	printf("donner le nom du fichier a ouvrir: ");
	gets(nom);
	
	//lire le nom du nouveau fichier 
	printf("donner le nom du nouveau fichier : ");
	gets(nom2);
	
	//ouvrir le fichier fp en mode read
	fp=fopen(nom,"r");
	//verifier si le pointeur du fichier est valide
	if (fp == NULL){
		printf("le fichier n'a pas put etre ouvert");
		return 0;
	}
	
	//ouvrir le nouveau fichier en mode write
	fp2=fopen(nom2,"w");
	//verifier si le pointeur du fichier est valide
	if (fp2 == NULL){
		printf("le fichier n'a pas put etre ouvert");
		return 0;
	}
	
	//lecture et affichage du contenu du fichier ligne par ligne 
	while(fgets(ligne,sizeof(ligne),fp) != NULL){
		for(i=0; ligne[i] != '\0'; i++){
			if (!isspace(ligne[i]) || (i > 0 && !isspace(ligne[i - 1]))){
				ligne[j] = ligne[i];
				j++;	
			}	
		}
		ligne[j] = '\0'; // Ajouter le caractère de fin de chaîne à la nouvelle ligne	
		//ecrire le resultat dans un autre fichier
		fprintf(fp2,"%s",ligne);	

	// Fermer les fichiers
    fclose(fp);
    fclose(fp2);
	
	return 0;
}
