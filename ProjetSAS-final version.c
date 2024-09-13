#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

///creation un strucrure pour la date :
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
///Les fonctions importants:
void Ajouter();
void ModifierSupprimer();
void Afficher();
void Calculer();
void Calculer();
void Statistique();
void Rechercher();
void Trier();

///Les variables importantes (globale):
etudiant Etudiants[100] = {
{1, "ham", "ahmed", {6, 10, 2000} , 1, 12.89},
{2, "ajjouqa", "abdou", {6, 03, 2005} , 5, 14.36},
{3, "sikal", "achraf", {20, 01, 2000} , 1, 9.14},
{4, "abofaresse", "yasser", {01, 9, 1999} , 3, 8.41},
{5, "laajil", "kawtar", {26, 11, 2001} , 2, 17.78},
{6, "baaoude", "aya", {15, 7, 2003} , 4, 12.5},
{7, "boutaib", "anass", {30, 5, 1998} , 1, 16.30},
{8, "imame", "yossra", {19, 12, 2001} , 3, 19.23},
{9, "laarbi", "ahlame", {1, 1, 2005} , 4, 7.75},
{10, "drwiche", "nabil", {7, 7, 2006} , 1, 12.5},
{11, "amour", "hatim", {14, 8, 1996} , 5, 13}, };
int compteur=11;
int taille, choix, date_de_naissance, id, i;
char nom[30], prenom[30];
float note_generale;

int main()
{
///Menu principale:
    printf("\n=================W~E~L~C~O~M~E==================\n");
    printf("Veuillez selectionner une option ci-dessous :\n");
    printf("===>1-Ajouter un ou bien plusieur etudiant.\n");
    printf("===>2-Modifier / Supprimer un compte d'un etudiant.\n");
    printf("===>3-Afficher les details d'un etudiant.\n");
    printf("===>4-Calculer la moyenne generale.\n");
    printf("===>5-Statistiques.\n");
    printf("===>6-Rechercher un etudiant.\n");
    printf("===>7-Trier.\n");
    printf("==>0-Quitter.\n");
    scanf("%d",&choix);
///lancement le switch:
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
case 5:
    Statistique();
    break;
case 6:
    Rechercher();
    break;
case 7.
    Trier();
default:
    break;
}
}

char* DepartementNOM(int DepartementChoix)
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
    if(compteur==0)
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
            printf("Departement : %s\n", DepartementNOM(Etudiants[i].departement));
            printf("Note generale : %.2f\n", Etudiants[i].note_generale);
        }
    }
main();
}

void ModifierSupprimer()
{
///les variable pour cette foncyion:
    int x=0;
    int iid;
    int index= -1; //Cette variable pour stocker l'index de l'etudiant trouve(comme un nouveau compteur)
    int choix_modif;
    int confirm;//Confirme de suppression
///////////////////////////////////
                    Depart:
    printf("\nEntrez l'id de l'etudiant que vous voulez modifier/supprimer :\n");
    scanf("%d", &iid);
///////////////////////////////////
///Recherche de l'etudiant avec l'ID specifie
    for(int i=0; i<compteur; i++)
    {
        if(Etudiants[i].id==iid)
        {
            x=1;
            index=i;
            break;
        }
    }
    if(x==0)
    {
        printf("-Id incorrect.\n");
        goto Depart;
    }
///////////////////////////////////
            Sous_Menu:
    printf("Voulez-vous ?\n");
    printf("1-Modifier.\n");
    printf("2-Supprimer.\n");
    printf("0-Retour.\n");
    scanf("%d", &choix);
///////////////////////////////////
    switch(choix)
    {
        case 1:
///Modification des informations de l'etudiant:
            printf("Vous pouvez modifier quoi ?\n");
            printf("1-Id\n2-Nom\n3-Prenom\n4-Date de naissance\n5-Departement\n6-Note generale\n0-Retour\n");
            scanf("%d", &choix_modif);

            switch(choix_modif)
            {
            case 1:
                    printf("Nouveau Id : ");
                    scanf("%d", &Etudiants[index].id);
                    goto Sous_Menu;
                break;
            case 2:
                    printf("Nouveau Nom : ");
                    scanf(" %[^\n]", Etudiants[index].nom);
                    goto Sous_Menu;
                break;
            case 3:
                    printf("Nouveau Prenom : ");
                    scanf(" %[^\n]", Etudiants[index].prenom);
                    goto Sous_Menu;
                break;
            case 4:
///Saisie de la nouvelle date de naissance avec validation:
                    printf("Nouvelle date de naissance (JJ/MM/AAAA):\n");
                do{
                        printf("Jour : ");
                        scanf("%d", &Etudiants[index].date_de_naissance.jour);
                   }while(Etudiants[index].date_de_naissance.jour < 1 || Etudiants[index].date_de_naissance.jour > 31);

                do{
                        printf("Mois : ");
                        scanf("%d", &Etudiants[index].date_de_naissance.mois);
                   }while(Etudiants[index].date_de_naissance.mois < 1 || Etudiants[index].date_de_naissance.mois > 12);

                do{
                        printf("Annee : ");
                        scanf("%d", &Etudiants[index].date_de_naissance.annee);
                   }while(Etudiants[index].date_de_naissance.annee < 1990 || Etudiants[index].date_de_naissance.annee > 2007);
                   goto Sous_Menu;
                break;
            case 5:
///Modification du departement:
                    printf("Selectionner votre nouveau departement :\n");
                    printf("1-Sience Mathematique\n2-Sience Physique et Chimie\n3-Sience de Vie et Terre (SVT)\n4-Philosophie\n5-Informatique\n");
                    scanf("%d", &Etudiants[index].departement);
                break;
            case 6:
///Modification de la note generale:
                do{
                        printf("Nouvelle note generale : ");
                        scanf("%f", &Etudiants[index].note_generale);
                   }while(Etudiants[index].note_generale < 0 || Etudiants[index].note_generale > 20);
                break;
            case 0:
                return main();
            default:
                    printf("Option invalide !\n");
                    break;
            }
            goto Sous_Menu;
        break;
        case 2:
///Suppression de l'etudiant:
            printf("Etes-vous sur de vouloir supprimer cet etudiant ?\n");
            printf("1-Oui\n2-Non\n");
            scanf("%d", &confirm);

            if(confirm == 1)
             {
                for(int i=index; i<compteur-1; i++)
                {
                    Etudiants[i] = Etudiants[i+1];
                }
                compteur--;
                printf("Etudiant supprime avec succes.\n");
             }
             goto Sous_Menu;
            break;
        case 0:
            main();
        default:
            printf("Option invalide !\n");
            break;
    }
}

void Calculer()
{
///les variables importantes :
    int chois, total_etudiants=0;
    float notes=0, moyenne_generale=0;

    if(compteur==0)
    {
        printf("Aucun etudiant n'a encore ete ajoute.\n");
        return main();
    }
    printf("Selectionner un departement pour calculer la moyenne :\n");
    printf("1-Sience Mathematique.\n2-Sience Physique et Chimie.\n3-Sience de Vie et Terre (SVT).\n4-Philosophie.\n5-Informatique.\n");
    scanf("%d", &chois);

    if(chois < 1 || chois > 5)
    {
        printf("Veuillez choisir sauf entre 1 et 5.\n");
        return main();
    }
    for(int i=0;i<compteur;i++)
    {
        if(Etudiants[i].departement == chois)
        {
            notes +=Etudiants[i].note_generale;
            total_etudiants++;
        }
    }

    if(total_etudiants>0)
    {
        moyenne_generale=notes / total_etudiants;
        printf("La moyenne generale du departement %d est : %.2f\n", chois, moyenne_generale);
        main();
    }
    else
    {
        printf("Aucun etudiant dans ce departement.\n");
        main();
    }
}

void Statistique()
{
///Les variables importantes pour cette foction:
    int totalEtudiants = compteur;
    int total[5] = {0}; //5=departement||-totale:les eleves qui inscrient
    float seuil;
    etudiant Top[3];//les 3 meuilleurs d'etudiant
    int Reussi[5] = {0};//les eleves qui reussient
//////////////////////////////////////////////
///Meilleur etudiants:
    // les meilleur avec des points negative pour la faciliter
    for (int i = 0; i < 3; i++)
    {
            Top[i].note_generale = -1;
    }
//////////////////////////////////////////////
/// Afficher le nombre total d'etudiants:
    printf("Nombre total d'etudiants inscrits : %d\n", totalEtudiants);
//////////////////////////////////////////////
    for (i=0; i<compteur; i++)
    {
        total[Etudiants[i].departement - 1]++;
        //Classement les etudiants(Tri)
        for (int j = 0; j < 3; j++)
        {
            if (Etudiants[i].note_generale > Top[j].note_generale)
            {
                for (int k = 2; k > j; k--)
                {
                    Top[k] = Top[k-1];
                }
                Top[j] = Etudiants[i];
                break;
            }
        }
        // Les etudiants qui reussient
        if (Etudiants[i].note_generale >= 10.0)
        {
            Reussi[Etudiants[i].departement - 1]++;
        }
    }
//////////////////////////////////////////////
/// Afficher le nombre d'etudiant de quelque departement:

    printf("\nNombre d'etudiants par departement :\n");
    printf("1-Sience Mathematique: %d\n", total[0]);
    printf("2-Sience Physique et Chimie: %d\n", total[1]);
    printf("3-Sience de Vie et Terre (SVT): %d\n", total[2]);
    printf("4-Philosophie: %d\n", total[3]);
    printf("5-Informatique: %d\n", total[4]);
//////////////////////////////////////////////
///Seuil de moyenne general:

    printf("\nEntrez un seuil de moyenne generale : ");
    scanf("%f", &seuil);
    printf("\nEtudiants avec une moyenne superieure a %.2f :\n", seuil);
    for (i=0; i<compteur; i++)
    {
        if (Etudiants[i].note_generale > seuil)
        {
            printf("%s %s (ID: %d) - Note generale : %.2f\n", Etudiants[i].nom, Etudiants[i].prenom, Etudiants[i].id, Etudiants[i].note_generale);
        }
    }
///Afficher les 3 tope etudiants:
    printf("\nLes 3 etudiants avec les meilleures notes :\n");
    for (i=0; i<3 && Top[i].note_generale>0; i++)
    {
        printf("%s %s (Id: %d) - Note generale : %.2f\n", Top[i].nom, Top[i].prenom, Top[i].id, Top[i].note_generale);
    }

///Qui reussi a chaque departement:
    printf("\nNombre d'etudiants qui reussient par departement :\n");
    printf("1-Sience Mathematique: %d\n", Reussi[0]);
    printf("2-Sience Physique et Chimie: %d\n", Reussi[1]);
    printf("3-Sience de Vie et Terre (SVT): %d\n", Reussi[2]);
    printf("4-Philosophie: %d\n", Reussi[3]);
    printf("5-Informatique: %d\n", Reussi[4]);

    if(compteur==0)
    {
        printf("Aucun etudiant n'a encore ete ajoute.\n");
        return main();
    }
   return main();
}

void Rechercher()
{
    int search;
    char recherche_par_nom[30];
    int recherche_par_departement;
    int trouve = 0; // Variable pour verifier si un etudiant a ete trouve

    printf("\n==== Rechercher un etudiant ====\n");
    printf("1-Rechercher par nom\n");
    printf("2-Rechercher par departement\n");
    printf("0-Retour\n");
    printf("Veuillez choisir une option : ");
    scanf("%d", &search);

    switch(search)
    {
    case 1:
            printf("\nEntrez le nom de l'etudiant a rechercher : ");
            scanf(" %[^\n]s", recherche_par_nom);
          for(int i=0; i<compteur; i++)
            {
                if(strcmp(Etudiants[i].nom, recherche_par_nom)==0)
                {
                    printf("\nEtudiant trouve :\n");
                    printf("Id : %d\n", Etudiants[i].id);
                    printf("Nom : %s\n", Etudiants[i].nom);
                    printf("Prenom : %s\n", Etudiants[i].prenom);
                    printf("Date de naissance : %02d/%02d/%d\n", Etudiants[i].date_de_naissance.jour,
                           Etudiants[i].date_de_naissance.mois,
                           Etudiants[i].date_de_naissance.annee);
                    printf("Departement : %d\n", Etudiants[i].departement);
                    printf("Note generale : %.2f\n", Etudiants[i].note_generale);
                    trouve = 1;
                    break;
                }
            }
            if(trouve==0)
            {
                printf("\nAucun etudiant sous le nom \"%s\" n'a ete trouve.\n", recherche_par_nom);
            }
        break;
    case 2:
            printf("\nSelectionnez le departement :\n");
            printf("1- Science Mathematique\n");
            printf("2- Science Physique et Chimie\n");
            printf("3- Science de Vie et Terre (SVT)\n");
            printf("4- Philosophie\n");
            printf("5- Informatique\n");
            scanf("%d", &recherche_par_departement);

            printf("\nListe des etudiants du departement %d :\n", recherche_par_departement);
            for(int i=0;i<compteur; i++)
            {
                if(Etudiants[i].departement==recherche_par_departement)
                {
                    printf("\nId : %d\n", Etudiants[i].id);
                    printf("Nom : %s\n", Etudiants[i].nom);
                    printf("Prenom : %s\n", Etudiants[i].prenom);
                    printf("Date de naissance : %02d/%02d/%d\n", Etudiants[i].date_de_naissance.jour,
                                                               Etudiants[i].date_de_naissance.mois,
                                                               Etudiants[i].date_de_naissance.annee);
                    printf("Note generale : %.2f\n", Etudiants[i].note_generale);
                    trouve = 1;
                }
            }
            if(trouve==0)
             {
                printf("\nAucun etudiant n'est inscrit dans ce departement.\n");
             }
            break;

    case 0:
            return main();
    default:
            printf("Option invalide. Veuillez reessayer.\n");
            break;
    }
    main();
}

void Trier()
{
///Lesvariables pour cette fonction:
    int choiix, ordre;
    etudiant temp;

///Condition de depart:
    if(compteur==0)
    {
        printf("Il y n'a aucun etudiants pour faire l'operation de Tri.\n");
        return main();
    }
                    deepart:
    printf("\nVeuillez choisir la methode de tri :\n");
    printf("1-Tri par nom (A-Z ou Z-A)\n");
    printf("2-Tri par moyenne generale (du plus eleve au plus bas)\n");
    printf("3-Tri par statut de reussite (moyenne >= 10/20)\n");
    printf("0-Retour\n");
    scanf("%d", &choiix);

    switch(choiix)
 {
        case 1:
/// Tri par nom:
            printf("\nChoisissez comment vou pouvez faire l'ordre de tri :\n");
            printf("1-A a Z\n");
            printf("2-Z a A\n");
            scanf("%d", &ordre);
            for (int i=0; i<compteur-1; i++)
            {
                for (int j=i+1; j<compteur; j++)
                {
                    if ((ordre==1 && strcmp(Etudiants[i].nom, Etudiants[j].nom)>0)||(ordre==2 && strcmp(Etudiants[i].nom, Etudiants[j].nom)<0))
                    {
                        temp=Etudiants[i];
                        Etudiants[i]=Etudiants[j];
                        Etudiants[j]=temp;
                    }
                }
            }
            printf("\nTri par nom est complete.\n");
            break;

        case 2:
///Tri par moyenne generale:
            printf("\nChoisissez l'ordre de tri :\n");
            printf("1-Du plus eleve au plus bas\n");
            printf("2-Du plus bas au plus eleve\n");
            scanf("%d", &ordre);
            for(int i=0; i<compteur-1; i++)
            {
                for(int j=i+1; j<compteur; j++)
                {
                    if((ordre==1 && Etudiants[i].note_generale<Etudiants[j].note_generale)||(ordre==2 && Etudiants[i].note_generale>Etudiants[j].note_generale))
                    {
                        temp = Etudiants[i];
                        Etudiants[i] = Etudiants[j];
                        Etudiants[j] = temp;
                    }
                }
            }
            printf("\nTri par moyenne generale est complete.\n");
            break;

        case 3:
///Tri par statut de reussite:
            printf("\nListe des etudiants qui reussient (moyenne >= 10/20) :\n");
            for(int i=0; i<compteur; i++)
            {
                if(Etudiants[i].note_generale>=10)
                {
                   printf("%s %s (Id: %d) - Note generale : %.2f\n", Etudiants[i].nom, Etudiants[i].prenom, Etudiants[i].id, Etudiants[i].note_generale);
                }
            }
            break;

        default:
            printf("Choix invalide.\n");
            goto deepart;
            break;

        case 0:
         main();
         break;

    }
}
