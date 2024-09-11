#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
int numero_unique;
char nom;
char prenom;
int date_de_naissance;
int departement;
int note_generale;
}etudiant;

void Ajouter();
void Modifier();
void Afficher();
void Calculer();
void Statistiques();
void Rechercher();
void Trier();

etudiant tab[100];
int compteur=0;

int main()
{
    int choix;
     printf("\n~~~~~~~~WELCOME~~~~~~~~\n");
     printf("\nVeuillez choisir une option que vous voulez:\n");
     printf("1-Ajouter.\n");
     printf("2-Modifier.\n");
     printf("3-Afficher.\n");
     printf("4-Calculer.\n");
     printf("5-Statistiques.\n");
     printf("6-Rechercher.\n");
     printf("7-Trier.\n");
     printf("0-Quitter.\n");
     scanf("%d",&choix);

 switch(choix)
 {
    case 1:
      Ajouter();
     break;
    /*case 2:
      Modifier();
     break;*/


 }
}
void Ajouter()
{//créer les variable importants:
 int choix, taille, i;
 int numero_unique,date_de_naissance;
 float note_generale;
 char nom[30],prenom[30],departement[100];
//créer des messages pour l'affichage:
            start:
  printf("Vous voulez quoi ?\n");
  printf("1-Ajouter un seul etudiant.\n");
  printf("2-Ajouter plusieur etudiants en meme temps.\n");
  printf("\n0-Retour.\n");
  scanf("%d",&choix);
//maintenant lancement de SWITCH: 
 switch(choix)
 { 
    case 1:
     {
      printf("Entrer les information de l'etudiant : \n");

      printf("Id : ");
      scanf("%d", &numero_unique);

      printf("Nom : ");
      scanf("%s", nom);

      printf("Prenom : ");
      scanf("%s", prenom);

      printf("Date de naissance : ");
      scanf("%d", &date_de_naissance);

      printf("Departement : ");
      scanf(" %[^\n]%*c", departement);

      printf("Note Generale : ");
      scanf("%f", &note_generale);

     //poser les information au stocke.
        strcpy(tab[compteur].nom, nom);
        strcpy(tab[compteur].prenom, prenom);
        strcpy(tab[compteur].departement, departement);
        tab[compteur].numero_unique = numero_unique;
        tab[compteur].date_de_naissance = date_de_naissance;
        tab[compteur].note_generale = note_generale;

         compteur++;

        goto start;
    break;
   }
    case 2:
   {
      printf("Combien d'etudiant pouvez-vous l'ajouter ?\n");
      scanf("%d",&taille);
    //faire une boucle pour la répetetion:
      for(i=0;i<taille;i++)
      {
         printf("\nSaisir le Id de l'etudiant %d: ",i+1);
         scanf("%d",&tab[compteur].numero_unique);

         printf("\nSaisir le nom de l'etudiant %d: ",i+1);
         scanf(" %[^\n]%*c", tab[compteur].nom);

         printf("\nSaisir le prenom de l'etudiant %d: ",i+1);
         scanf(" %[^\n]%*c", tab[compteur].prenom);

         printf("\nSaisir le departement de l'etudiant %d: ",i+1);
         scanf(" %[^\n]%*c", tab[compteur].departement);

         printf("\nSaisir la date de naissance de l'etudiant %d: ",i+1);
         scanf("%d", &tab[compteur].date_de_naissance);

         printf("\nSaisir la note generale de l'etudiant %d: ",i+1);
         scanf("%f", &tab[compteur].note_generale);

         printf("\nLes informations sont ajoutes avec succees !\n");

         compteur++;
      }
     goto start; 
    break;
   }
   case 0:
        break;  
 }
 main();
}
