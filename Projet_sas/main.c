#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


    struct Produit{
        int Code;
        char Nom[20];
        int Quantite;
        float Prix;
    };

    struct Satistique{
        time_t date;
        int Max;
        int Min;
        float Moyenne;
        int nombre;
    };
    struct Satistique satistique;

    //Menu
    void Option(int choix){
        printf("\n");
        system("cls");
        printf("\t \t================= bienvenu =================\n\n\n");
        printf("\t \t 1_ Ajouter un ou  plusieurs nouveaux produits \n");
        printf("\t \t 2_ Rechercher les produits \n");
        printf("\t \t 3_ supprimer  un nouveau produit \n");
        printf("\t \t 4_ afficher  liste des produits \n");
        printf("\t \t 5_ Acheter produit \n");
        printf("\t \t 6_ Statistique de vente \n");
        printf("\t \t 7_ Exit \n");
        printf("\t \t===========================================\n");

        scanf("%c",&choix);

//        do{
//            scanf(" %c",&choix);
//        }while (choix <= 48 || choix > 55);

        switch(choix){
            case 49:
                system("cls");
                Ajouter_Produit();
                getch();
                system("cls");
                break;
            case 50:
                system("cls");
                Rechercher_Produit();
                getch();
                system("cls");
                break;
            case 51:
                system("cls");
                SupprimerProduit();
                getch();
                system("cls");
                break;
            case 52:
                system("cls");
                AfficherListeProduit();
                getch();
                system("cls");
                break;
            case 53:
                system("cls");
                Acheter();
                getch();
                system("cls");
                break;
            case 54:

                break;
            case 55:
                exit(0);
                break;
        }
    };
    //Ajouter un Produit
    void Ajouter_Produit(FILE *file_produit){
    char autre;
    struct Produit produit;
    do{
        system("cls");
        printf("\t====Ajouter un nouveau produit=== \n");
        file_produit = fopen("Produit.txt","a");
        printf("\n\t\t Donner le code de produit     :");
        scanf("%d",&produit.Code);
        printf("\n\t\t Donner le nom de produit      :");
        scanf("%s",&produit.Nom);
        printf("\n\t\t Donner le quantite de produit :");
        scanf("%d",&produit.Quantite);
        printf("\n\t\t Donner le prix de produit     :");
        scanf("%f",&produit.Prix);
        fwrite(&produit,sizeof(struct Produit),1,file_produit);
        printf("\t\t_____________________________\n");
        printf("AJOUTER AUTRE PRODUIT !! (Y/n)\n");
        scanf("%c",&autre);
    }while(autre =='y'||autre=='Y');
    fclose(file_produit);
}

//Rechercher Produit
void Rechercher_Produit(FILE *file_produit){
    struct Produit produit;
    int Quantite_produit,code_produit;
    int existe = 0;
    file_produit=fopen("Produit.txt","r");
    //choix par code ou quantite
    printf("\t\t\t ============= RECHERCHER PAR CODE OU QUANTITE ============ \n\n");
    debut:
    printf("\n\t\t\t 1_ Rechercher les produits Par code     :");
    printf("\n\t\t\t 2_ Rechercher les produits Par Quantite :\n");
    int choix_rechercher;
    do{
        scanf("%c",&choix_rechercher);
    }while (choix_rechercher <= 48 || choix_rechercher > 51);

    switch(choix_rechercher){
        //rechercher par code
        case 49:
                system("cls");
                printf("\t\t\t ============= RECHERCHER des produits par code ============ \n\n");
                printf("\n\t\t\t Donner le code de produit :\n");
                printf("\t\t\t _______________________________________\n");
                scanf("%d",&code_produit);
                while(fread(&produit,sizeof(struct Produit),1,file_produit)){
                    if(produit.Code == code_produit){
                            existe = 1;
                        printf("\n\t\t\t Code de Produit est     : %d \n",produit.Code);
                        printf("\n\t\t\t Nom de Produit est      : %s \n",produit.Nom);
                        printf("\n\t\t\t quantite de Produit est : %d \n",produit.Quantite);
                        printf("\n\t\t\t Prix de Produit est     : %.2f %s \n",produit.Prix,"DH");
                        printf("\t\t\t _______________________________________\n");
                    }
                }
                if(!existe)
                    printf("Il n'y a pas de produit");
                fclose(file_produit);
                break;
        //rechercher par quantite
        case 50:
                system("cls");
                printf("\t\t\t ============= RECHERCHER des produits par QUANTITE ============ \n\n");
                printf("\n\t\t\t Donner le quantite de produit :\n");
                printf("\t\t\t _______________________________________\n");
                scanf(" %d",&Quantite_produit);
                while(fread(&produit,sizeof(struct Produit),1,file_produit)){
                    if(produit.Quantite == Quantite_produit){
                            existe = 1;
                        printf("\n\t\t\t Code de Produit est     : %d \n",produit.Code);
                        printf("\n\t\t\t Nom de Produit est      : %s \n",produit.Nom);
                        printf("\n\t\t\t quantite de Produit est : %d \n",produit.Quantite);
                        printf("\n\t\t\t Prix de Produit est     : %.2f %s \n",produit.Prix,"DH");
                        printf("\t\t\t _______________________________________\n");
                    }
                }
                if(!existe)
                    printf("Il n'y a pas de produit");
                fclose(file_produit);
                break;
            default:
                printf("\n\t\t\t choisir 1 ou 2 : \n");
                goto debut;
    }
}

//Afficher les Listes des Produits
void AfficherListeProduit(){
    FILE *file_produit;
    struct Produit produit;
    file_produit = fopen("produit.txt","r");
    system("cls");
    printf("\t\t\t ============= la listes des produits par code ============ \n\n");
    printf("\t\t\t _______________________________________\n");

        while(fread(&produit,sizeof(struct Produit),1,file_produit)){
        printf("\n\t\t\t Code de Produit est         : %d \n",produit.Code);
        printf("\n\t\t\t Nom de Produit est          : %s \n",produit.Nom);
        printf("\n\t\t\t quantite de Produit est     : %d \n",produit.Quantite);
        printf("\n\t\t\t Prix de Produit est         : %.2f %s \n",produit.Prix,"DH");
        printf("\n\t\t\t Prix TTC de Produit est     : %.2f %s \n",produit.Prix+0.15,"DH");
        printf("\t\t\t _______________________________________\n");
        }
        fclose(file_produit);
}

void SupprimerProduit(){

    FILE *file_produit,*file_produit_supprimer;
    struct Produit produit;
    int code ;
    int existe=0;

       printf("\t\t\t\t=======DELETE STUDENTS RECORD=======\n\n\n");
    file_produit=fopen("produit.txt","r");
    file_produit_supprimer=fopen("supp_produit.txt","w");
    printf("\t\t\t\t Donner le code de produit : ");
    scanf("%d",&code);
    if(file_produit==NULL){
         printf("File ovrire\n");
         exit(0);
      }

    while(fread(&produit,sizeof(struct Produit),1,file_produit)){
        if(produit.Code == code){

            existe=1;

        }else{
           fwrite(&produit,sizeof(struct Produit),1,file_produit_supprimer);
        }

    }
     fclose(file_produit);
     fclose(file_produit_supprimer);

    if(!existe){
          printf("\n\t\t\t\t produit n est existe pas\n");
        }
      if(existe){
        remove("produit.txt");
        rename("supp_produit.txt","produit.txt");

        printf("\n\t\t\t\tproduit est supprimer\n");
        }

  getch();

    printf("\t\t\t _______________________________________\n");

}
void Acheter(){
    struct Produit produit;
    struct Produit produit_Achat;
    FILE *file_produit;
    FILE *file_produit_Achat;
    int code,quantite;
    int existe = 0;
    file_produit = fopen("produit.txt","r");
    file_produit_Achat = fopen("produit_Achat.txt","w");
    printf("Donner le code de produit ");
    scanf(" %d",&code);
    while(fread(&produit,sizeof(struct Produit),1,file_produit)){
        if(produit.Code == code){
            existe=1;
            printf("Donner le quantite de vende :");
            scanf(" %d",&quantite);
            produit_Achat.Code = produit.Code ;
            strcpy(produit_Achat.Nom,produit.Nom);
            produit.Quantite = produit.Quantite - quantite;
            produit_Achat.Quantite = produit.Quantite;

            produit_Achat.Prix = 0.15*produit.Prix;

            printf(" PRIX TOTAL EST  : %.2f\n",produit_Achat.Prix);

            fwrite(&produit,sizeof(struct Produit),1,file_produit_Achat);
        }else{
           fwrite(&produit_Achat,sizeof(struct Produit),1,file_produit_Achat);
        }
    }
    ListeAchate(produit_Achat.Prix);
    fclose(file_produit);
    fclose(file_produit_Achat);
    printf("\n\t\t\t\t produit est achat \n");
    remove("produit.txt");
    rename("produit_Achat.txt","produit.txt");
    if(!existe)
        printf("Produit n est existe pas");

}

void ListeAchate(float prix){
    FILE *fille_Achate;
    fille_Achate = fopen("Liste_Achate.txt","a");
    time(satistique.date);
    fprintf("\n Date de achate le produit: %s \n Prix Total : %.2f", ctime(satistique.date),prix);
    fclose(fille_Achate);

}

int main()
{
    int choix;
    do{
        Option(choix);
    }while(choix <= 48 || choix > 55);

    return 0;
}
