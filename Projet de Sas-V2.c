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
    int departement;
    float note_generale;
    }etudiant;
//Les fonctions importants:
void Ajouter();
void ModifierSupprimer();
void Afficher();
void Calculer();
void Calculer();
void Statistique();
//void Rechercher();
//void Trier();

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
case 2:
    ModifierSupprimer();
    break;
case 3:
    Afficher();
    break;
case 4:
    Calculer();
    break;
default:
    break;
}
}

void Ajouter()
{
///les variables pour la date de naissance:
    int jour, mois, annee;
    int chois;
///Message d'affichage:
    Start:
    printf("Vous pouvez ajouter un etudiant ou bien plusieur etudiants ?\n");
    printf("1-Ajouter un seul etudiant.\n");
    printf("2-Ajouter plusieur etudiants.\n");
    printf("0-Retour.\n");
    scanf("%d",&choix);
///lancement le switch:
switch (choix)
{
 case 1:
    printf("Veuillez entrer les information suivant : \n");
    printf("Id : ");
    scanf("%d",&Etudiants[compteur].id);

    printf("\n-Nom : ");
    scanf(" %[^\n]s",&Etudiants[compteur].nom);

    printf("\n-Prenom : ");
    scanf(" %[^\n]s",&Etudiants[compteur].prenom);

    printf("\n-Date de naissance (JJ/MM/AAAA): \n");
    /////////////////////////////////////////////////
             day:
    printf("Jour : ");
    scanf("%d",&Etudiants[compteur].date_de_naissance.jour);
    if(Etudiants[compteur].date_de_naissance.jour<1 || Etudiants[compteur].date_de_naissance.jour>31){
    printf("Saisir un date reel s'il vous plait.\n");
    goto day;          }
    //#########################
             month:
    printf("\nMois : ");
    scanf("%d",&Etudiants[compteur].date_de_naissance.mois);
    if(Etudiants[compteur].date_de_naissance.mois<1 || Etudiants[compteur].date_de_naissance.mois>12){
    printf("Saisir un date reel s'il vous plait.\n");
    goto month;          }
    //#########################
             year:
    printf("\nAnnee : ");
    scanf("%d",&Etudiants[compteur].date_de_naissance.annee);
    if(Etudiants[compteur].date_de_naissance.annee<1990 || Etudiants[compteur].date_de_naissance.annee>2007){
    printf("Saisir un date reel s'il vous plait.\n");
    goto year;          }
    //#########################
///creation de les departements:
             again:
    printf("\nVeuillez selectionner votre departement :\n");
    printf("1-Sience Mathematique.\n2-Sience Physique et Chimie.\n3-Sience de Vie et Terre (SVT).\n4-Philosophie.\n5-Informatique.\n");
    scanf("%d",&chois);
    if (chois<1 || chois>5){
     printf("Vous devez chhoisir des option entre 1 et 5 seulement.\n");
     goto again;           }
///copie le "chois" de l'utilisateur et coller dans la Etudiant(stockage):

     Etudiants[compteur].departement=chois;
///Note Generale:
                    Riestart:
    printf("\nNote generale : ");
    scanf("%f",&Etudiants[compteur].note_generale);
    if(Etudiants[compteur].note_generale<1 || Etudiants[compteur].note_generale>20)
                {
                          printf("la note generale doit etre limite a 0-20 seulement.");
                          goto Riestart;
                }
    printf("les infomations sont ajoutes avec succes!\n");
        compteur++;
goto Start;
    break;
 case 2:
    printf("Combien d'etudiants vouillez-vous ajouter ?\n");
    printf("Nombre d'etudiant : ");
    scanf("%d",&taille);
        for(i=0;i<taille;i++)
        {
            printf("Veuillez entrer les infomations suivants:\n");

            printf("Id d'etudiant %d : ",i+1);
            scanf("%d",&Etudiants[compteur].id);

            printf("\nNom d'etudiant %d : ",i+1);
            scanf(" %[^\n]s",&Etudiants[compteur].nom);

            printf("\nPrenom d'etudiant %d : ",i+1);
            scanf(" %[^\n]s",&Etudiants[compteur].prenom);
///SAISIRE DATE DE NAISSANCE AVEC LES CONDITION
                        Day:
            printf("\nDate de naissance d'etudiant %d : ",i+1);
            printf("\nJour : ");
            scanf("%d",&Etudiants[compteur].date_de_naissance.jour);
            if(Etudiants[compteur].date_de_naissance.jour<1 || Etudiants[compteur].date_de_naissance.jour>31) {
                printf("Saisir un date reel s'il vous plait.\n");
                 goto Day;          }
    //////////////////////////////
                        Month:
            printf("\nMois : ");
            scanf("%d",&Etudiants[compteur].date_de_naissance.mois);
            if(Etudiants[compteur].date_de_naissance.mois<1 || Etudiants[compteur].date_de_naissance.mois>12)     {
                 printf("Saisir un date reel s'il vous plait.\n");
                 goto Month;          }
    //////////////////////////////
                        Year:
            printf("\nAnnee : ");
            scanf("%d",&Etudiants[compteur].date_de_naissance.annee);
            if(Etudiants[compteur].date_de_naissance.annee<1990 || Etudiants[compteur].date_de_naissance.annee>2024){
                 printf("Saisir un date reel s'il vous plait.\n");
                 goto Year;          }
    ///////////////////////////////
///Departement:
            int chois;
                         Reetry:
            printf("\nVeuillez selectionner le departement d'etudiant %d:\n",i+1);
            printf("1-Sience Mathematique.\n2-Sience Physique et Chimie.\n3-Sience de Vie et Terre (SVT).\n4-Philosophie.\n5-Informatique.\n");
             scanf("%d",&chois);
                 if (chois<1 || chois>5)         {
                           printf("Vous devez chhoisir des option entre 1 et 5 seulement.\n");
                           goto Reetry;           }

            Etudiants[compteur].departement=chois;

///Note Generale:
                            Reestart:
            printf("\nNote generale d'etudiant %d : ",i+1);
            scanf("%f",&Etudiants[compteur].note_generale);
            if(Etudiants[compteur].note_generale<1 || Etudiants[compteur].note_generale>20)
                {
                          printf("la note generale doit etre limite a 0-20 seulement.");
                          goto Reestart;
                }
            printf("Les information d'etudiant %d sont ajoutees avec succes !\n", i+1);

              compteur++;
        }
        goto Start;
    break;
  case 0:
main();
        break;
 default:
    printf("Veuillez selectionner les choix entre 0-2 seulement.");
    goto Start;
    break;
  }
 }

void Afficher()
{
    if (compteur == 0)
    {
        printf("\nAucun etudiant n'a encore ete ajoute.\n");
    }
    else
    {
        printf("\nListe des etudiant qui deja ajoutes :\n");
        for (int i=0;i<compteur;i++)
        {
            printf("\nEtudiant %d :\n", i+1);
            printf("Numero Unique : %d\n", Etudiants[i].id);
            printf("Nom : %s\n", Etudiants[i].nom);
            printf("Prenom : %s\n", Etudiants[i].prenom);
            printf("Date de naissance : %02d/%02d/%d\n", Etudiants[i].date_de_naissance.jour,
                    Etudiants[i].date_de_naissance.mois,
                    Etudiants[i].date_de_naissance.annee);
            printf("Departement : %d\n", Etudiants[i].departement);
            printf("Note generale : %.2f\n", Etudiants[i].note_generale);
        }
    }
main();
}

void ModifierSupprimer()
{
    //les variables pour cette fonctions:
    int x=0;
    int iid;
                                 start:

  printf("\nEntrez l'id d'etudiant que vous voulez le modifier/supprimer :\n");
  scanf("%d",&iid);
     if (iid == Etudiants[compteur].id)
{
  for(int i=0;i<compteur;i++)
 {
         x=1;
         again:
     printf("Vou pouvez ?\n");
     printf("1-Modifier.\n");
     printf("2-Supprimer.\n");
     printf("0-Retour.\n");
     scanf("%d",&choix);
int chois;
 switch(choix)
    {
    case 1:
                    Deefault:
            printf("Vous pouvez modifier quois ?\n");
            printf("1-Id\n");
            printf("2-Nom\n");
            printf("3-Prenom\n");
            printf("4-Date de naissance\n");
            printf("5-Departement\n");
            printf("6-Note generale\n");
            printf("0-Retour\n");
            scanf("%d",chois);
        switch(chois)
         {
        case 1:
            printf("-Nouveau Id : ");
            scanf("%d",&Etudiants[i].id);
            goto start;
             break;
        case 2:
            printf("-Nouveau Nom : ");
            scanf(" %[^\n]",&Etudiants[i].nom);
            goto start;
             break;
        case 3:
            printf("-Nouveau Prenom : ");
            scanf(" %[^\n]",&Etudiants[i].prenom);
            goto start;
             break;
        case 4:
            printf("-Nouveau Date de naissance (JJ/MM/AAAA) : \n");
                              Day:
            printf("-Jour : ");
            scanf("%d",&Etudiants[i].date_de_naissance.jour);
                if(Etudiants[i].date_de_naissance.jour<1 || Etudiants[i].date_de_naissance.jour>31)
                {
                    printf("Saisir un date reel s'il vous plait.\n");
                            goto Day;
                }
                            Month:
            printf("\n-Mois : ");
            scanf("%d",&Etudiants[i].date_de_naissance.mois);
                if(Etudiants[i].date_de_naissance.mois<1 || Etudiants[i].date_de_naissance.mois>12)
                {
                    printf("Saisir un date reel s'il vous plait.\n");
                        goto Month;
                }
                        Year:
            printf("\n-Annee : ");
            scanf("%d",&Etudiants[i].date_de_naissance.annee);
                if(Etudiants[i].date_de_naissance.annee<1990 || Etudiants[i].date_de_naissance.annee>2007)
                {
                    printf("Saisir un date reel s'il vous plait.\n");
                        goto Year;
                }
            goto start;
             break;
        case 5:
                        Departement:
            printf("-Selectionner votre nouvelle departement : \n");
            printf("1-Sience Mathematique.\n2-Sience Physique et Chimie.\n3-Sience de Vie et Terre (SVT).\n4-Philosophie.\n5-Informatique.\n");
            scanf("%d",&chois);
                if(chois<1 || chois>5)
                {
                    printf("Vous devez chhoisir des option entre 1 et 5 seulement.\n");
                        goto Departement;
                }
            Etudiants[i].departement=chois;
            goto start;
             break;
        case 6:
                      Restart:
            printf("-Nouvelle note generale : ");
            scanf("%f",&Etudiants[i].note_generale);
                if(Etudiants[i].note_generale<1 || Etudiants[i].note_generale>20)
                {
                    printf("la note generale doit etre limite a 0-20 seulement.");
                        goto Restart;
                }
            goto start;
             break;
        case 0:
            goto again;
             break;
        default:
            printf("Veuillez choisir un option possible !");
             goto Deefault;
             break;
         }//1ere Switch
    case 2:
    printf("Vous ete sur de supprimer ce compte ?\n");
    printf("1-Oui.\n");
    printf("2-Non.\n");
    scanf("%d",&choix);
switch(choix)
{
case 1:
     for(int j=i;i<compteur-1;j++)
     {
         Etudiants[j] = Etudiants[j+1];
     }
      compteur--;
      printf("la supprimation complete avec succes.\n");
     goto start;
    break;
case 2:
    goto start;
    break;
default:
    printf("Choisissez sauf 1 ou 2.");
     goto start;
    break;
}
case 0:
    goto start;
    }//2eme Switche
   }//Boucle "for"
}
if(x==0)
    printf("-Id incorrecte.\n");
}

void Calculer()
{
///les variables importantes :
    int chois, total_etudiants = 0;
    float somme_notes = 0.0, moyenne_generale = 0.0;

    if(compteur == 0)
    {
        printf("Aucun etudiant n'a encore ete ajoute.\n");
        return;
    }
    printf("Selectionner un departement pour calculer la moyenne :\n");
    printf("1-Sience Mathematique.\n2-Sience Physique et Chimie.\n3-Sience de Vie et Terre (SVT).\n4-Philosophie.\n5-Informatique.\n");
    scanf("%d", &chois);

    if (chois < 1 || chois > 5)
    {
        printf("Veuillez choisir sauf entre 1 et 5.\n");
        return;
    }
    for (int i=0;i<compteur;i++)
    {
        if(Etudiants[i].departement == chois)
        {
            somme_notes +=Etudiants[i].note_generale;
            total_etudiants++;
        }
    }

    if(total_etudiants>0)
    {
        moyenne_generale=somme_notes / total_etudiants;
        printf("La moyenne generale du departement %d est : %.2f\n", chois, moyenne_generale);
        main();
    }
    else
    {
        printf("Aucun etudiant dans ce departement.\n");
        main();
    }
}

/*void Statistique() {
    ///Les variables importantes pour cette foction:
    int totalEtudiants = compteur;
    int total[5] = {0}; //5=departement||-totale:les eleves qui inscrient
    float seuil;
    etudiant Top[3];//les 3 meuilleurs d'etudiant
    int Reussi[5] = {0};//les eleves qui reussient

    ///Meilleur etudiants:
    // les meilleur avec des points negative pour la faciliter
    for (int i = 0; i < 3; i++) {
        meilleursEtudiants[i].note_generale = -1.0;
    }

    // Afficher le nombre total d'étudiants
    printf("Nombre total d'étudiants inscrits : %d\n", totalEtudiants);

    // Calculer le nombre d'étudiants dans chaque département
    for (int i = 0; i < compteur; i++) {
        total[Etudiants[i].departement - 1]++;

        // Mettre à jour les étudiants avec les meilleures notes
        for (int j = 0; j < 3; j++) {
            if (Etudiants[i].note_generale > meilleursEtudiants[j].note_generale) {
                for (int k = 2; k > j; k--) {
                    meilleursEtudiants[k] = meilleursEtudiants[k-1];
                }
                meilleursEtudiants[j] = Etudiants[i];
                break;
            }
        }

        // Compter les étudiants ayant réussi (note >= 10)
        if (Etudiants[i].note_generale >= 10.0) {
            nbReussitesParDepartement[Etudiants[i].departement - 1]++;
        }
    }

    // Afficher le nombre d'étudiants dans chaque département
    printf("\nNombre d'étudiants par département :\n");
    printf("1-Sience Mathematique: %d\n", nbEtudiantsParDepartement[0]);
    printf("2-Sience Physique et Chimie: %d\n", nbEtudiantsParDepartement[1]);
    printf("3-Sience de Vie et Terre (SVT): %d\n", nbEtudiantsParDepartement[2]);
    printf("4-Philosophie: %d\n", nbEtudiantsParDepartement[3]);
    printf("5-Informatique: %d\n", nbEtudiantsParDepartement[4]);

    // Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil
    printf("\nEntrez un seuil de moyenne générale : ");
    scanf("%f", &seuil);
    printf("\nÉtudiants avec une moyenne supérieure à %.2f :\n", seuil);
    for (int i = 0; i < compteur; i++) {
        if (Etudiants[i].note_generale > seuil) {
            printf("%s %s (ID: %d) - Note générale : %.2f\n", Etudiants[i].nom, Etudiants[i].prenom, Etudiants[i].id, Etudiants[i].note_generale);
        }
    }

    // Afficher les 3 étudiants ayant les meilleures notes
    printf("\nLes 3 étudiants avec les meilleures notes :\n");
    for (int i = 0; i < 3 && meilleursEtudiants[i].note_generale > 0; i++) {
        printf("%s %s (ID: %d) - Note générale : %.2f\n", meilleursEtudiants[i].nom, meilleursEtudiants[i].prenom, meilleursEtudiants[i].id, meilleursEtudiants[i].note_generale);
    }

    // Afficher le nombre d'étudiants ayant réussi dans chaque département
    printf("\nNombre d'étudiants ayant réussi (note >= 10) par département :\n");
    printf("1-Sience Mathematique: %d\n", nbReussitesParDepartement[0]);
    printf("2-Sience Physique et Chimie: %d\n", nbReussitesParDepartement[1]);
    printf("3-Sience de Vie et Terre (SVT): %d\n", nbReussitesParDepartement[2]);
    printf("4-Philosophie: %d\n", nbReussitesParDepartement[3]);
    printf("5-Informatique: %d\n", nbReussitesParDepartement[4]);

    if (compteur == 0) {
        printf("Aucun étudiant n'a encore été ajouté.\n");
        return;
    }
    main();
}*/
//nbEtudiantsParDepartement // nbReussitesParDepartement
