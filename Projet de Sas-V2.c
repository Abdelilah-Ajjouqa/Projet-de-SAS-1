#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
 //creation un strucrure pour la date :
typedef struct DateDeNaissance{
    int jour,mois,annee;
}DateDeNaissance;

typedef struct etudiant{
    int id;
    char nom[30];
    char prenom[30];
    DateDeNaissance date_de_naissance;
    char departement[100];
    float note_generale;
    }etudiant;



//Les variables importantes(globale):
etudiant Etudiants[100];
int compteur=0;
int taille, choix, date_de_naissance, id, i;
char nom[30], prenom[30];
float note_generale;

int main()
{
    //Menu principale:
    printf("\n=================W~E~L~C~O~M~E==================\n");
    printf("Veuillez selectionner une option ci-dessous :\n");
    printf("===>1-Ajouter un ou bien plusieur etudiant.\n");
    printf("===>2-Modifier / Supprimer un compte d'un etudiant.\n");
    printf("===>3-Afficher les details d'un etudiant.\n");
    printf("===>4-Calculer la moyenne generale.\n");
    printf("===>5-Statistiques.\n");
    printf("===>6-Rechercher un étudiant.\n");
    printf("===>7-Trier.\n");
    printf("==>0-Quitter.\n");
    scanf("%d",&choix);
    //lancement le switch:
switch (choix)
{
case 1:
    Ajouter();
    break;

default:
    break;
}
}

void Ajouter()
{
    //les variables pour la date de naissance:
    int jour, mois, annee;

    //Message d'affichage:
    printf("Vous pouvez ajouter un etudiant ou bien plusieur etudiants ?\n");
    printf("1-Ajouter un seul etudiant.\n");
    printf("2-Ajouter plusieur etudiants.\n");
    printf("0-Retour.\n");
    scanf("%d",&choix);
    //lancement le switch:
switch (choix)
{
 case 1:
    printf("Veuillez entrer les information suivant : \n");
    printf("Id : ");
    scanf("%d",&Etudiants[compteur].id);

    printf("\n-Nom : ");
    scanf("%s",&Etudiants[compteur].nom);

    printf("\n-Prenom : ");
    scanf("%s",&Etudiants[compteur].prenom);

    printf("\n-Date de naissance (JJ/MM/AAAA): \n");
    /////////////////////////////////////////////////
             Again:
    printf("Jour : ");
    scanf("%d",&Etudiants[compteur].date_de_naissance.jour );
    if(jour<1 || jour>31){
    printf("Saisir un date reel s'il vous plait.");
    goto Again;          }
    //#########################
    printf("\nMois : ");
    scanf("%d",&Etudiants[compteur].date_de_naissance.mois);
    if(mois<1 || mois>12){
    printf("Saisir un date reel s'il vous plait.");
    goto Again;          }
    //#########################
    printf("\nAnnee : ");
    scanf("%d",&Etudiants[compteur].date_de_naissance.annee);
    if(annee<1 || annee>2024){
    printf("Saisir un date reel s'il vous plait.");
    goto Again;          }
    //#########################
//fonction pour appeler le departemnet d'etudiant dans les autres fonctions:
char* Nom_De_Departement(int DepartementChoix)
{
    switch(DepartementChoix)
    {
        case 1: return "Sience Mathematique";
        case 2: return "Sience Physique et Chimie";
        case 3: return "Sience de Vie et Terre (SVT)";
        case 4: return "Philosophie";
        case 5: return "Informatique";
    }
}

//printf("Etudiant Departement est : %s", Nom_De_Departement(Etudiants[compteur].departement));
    //creation de les departements:
    int chois;
             again:
    printf("\nVeuillez selectionner votre departement :\n");
    printf("1-Sience Mathematique.\n2-Sience Physique et Chimie.\n3-Sience de Vie et Terre (SVT).\n4-Philosophie.\n5-Informatique.\n");
    scanf("%d",&chois);
    if (chois<1 || chois>5){
     printf("Vous devez chhoisir des option entre 1 et 5 seulement.");
     goto again;           }    
 //copie le "chois" de l'utilisateur et coller dans la Etudiant(stockage):
     Etudiants[compteur].departement=chois;
    
    printf("\nNote generale : ");
    scanf("%.2f",&Etudiants[compteur].note_generale);
        compteur++;
    break;

 default:
    break;
}
}