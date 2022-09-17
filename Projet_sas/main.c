#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


    struct Produit{
        int Code;
        char Nom[20];
        int Quantite;
        float Prix;
    };

    void bienvenu(){
        printf("\n");
        printf("\t \t================= bienvenu =================\n\n\n");
    };

    //Menu
    void Option(){
        printf("\t \t 1_ Ajouter un nouveau produit \n");
        printf("\t \t 2_ Ajouter plusieurs nouveaux produits \n");
        printf("\t \t 3_ Rechercher les produits \n");
        printf("\t \t 4_ supprimer  un nouveau produit \n");
        printf("\t \t 5_ afficher  un nouveau produit \n");
        printf("\t \t 6_ Exit \n");
        printf("\t \t===========================================\n");
        int choix;
        do{
            scanf("%c",&choix);
        }while (choix <= 48 || choix > 55);
        switch(choix){
            case 49:
                system("cls");
                Ajouter_Produit();
                system("cls");
                break;
            case 50:
                printf("Ajouter plusieurs nouveaux produits \n");
                break;
            case 51:
                printf("Rechercher les produits \n");
                system("cls");
                Rechercher_Produit();
                system("cls");
                break;
            case 52:
                printf("supprimer  un nouveau produit \n");
                break;
            case 53:
                printf("afficher  un nouveau produit \n");
                break;
            case 54:
                printf("programme est exit \n");
                exit(0);
                break;
        }
    };
    //Ajouter un Produit
    void Ajouter_Produit(){
    FILE *file_produit;
    char autre;
    struct Produit produit;
    do{
        system("cls");
        printf("\t====Ajouter un nouveau produit=== \n");
        file_produit=fopen("Produit.txt","a");
        printf("\n\t\t Donner le code de produit     :");
        scanf("%d",&produit.Code);
        printf("\n\t\t Donner le nom de produit      :");
        scanf("%s",&produit.Nom);
        printf("\n\t\t Donner le quantite de produit :");
        scanf("%d",&produit.Quantite);
        printf("\n\t\t Donner le prix de produit     :");
        scanf("%f",&produit.Prix);
        printf("\t\t_____________________________\n");
        fwrite(&produit,sizeof(struct Produit),1,file_produit);
        fclose(file_produit);
        printf("AJOUTER AUTRE PRODUIT !! (Y/n)\n");
        scanf("%s",&autre);
    }while(autre =='y'||autre=='Y');
}
void Rechercher_Produit(){
    FILE *file_produit;
    struct Produit produit;

    int Quantite_produit,code_produit;
    int test=0;
    file_produit=fopen("Produit.txt","r");
        system("cls");
    printf("\t\t\t ============= la listes des produits ============ \n\n");
    debut:
    printf("\n\t\t\t 1_ Rechercher les produits Par code     :");
    printf("\n\t\t\t 2_ Rechercher les produits Par Quantite :\n");
    int choix_rechercher;
    do{
        scanf("%c",&choix_rechercher);
    }while (choix_rechercher <= 48 || choix_rechercher > 51);
    switch(choix_rechercher){
        case 49:
                system("cls");
                printf("\t\t\t ============= la listes des produits par code ============ \n\n");
                printf("\n\t\t\t Donner le code de produit :\n");
                printf("\t\t\t _______________________________________\n");
                scanf("%d",&code_produit);
                while(fread(&produit,sizeof(struct Produit),1,file_produit)){
                    if(produit.Code == code_produit){
                            test=1;
                        printf("\n\t\t\t Code de Produit est     : %d \n",produit.Code);
                        printf("\n\t\t\t Nom de Produit est      : %s \n",produit.Nom);
                        printf("\n\t\t\t quantite de Produit est : %d \n",produit.Quantite);
                        printf("\n\t\t\t Prix de Produit est     : %.2f %s \n",produit.Prix,"DH");
                        printf("\t\t\t _______________________________________\n");
                    }
                }
                if(!test)
                    printf("code n'est pas Ajouter");
                fclose(file_produit);
                printf("\n\t\t\t exit");
                getch();
                break;
        case 50:
                system("cls");
                printf("\n\t\t\t Donner le quantite de produit :\n");
                printf("\t\t\t _______________________________________\n");
                scanf("%d",&Quantite_produit);
                while(fread(&produit,sizeof(struct Produit),1,file_produit)){
                    if(produit.Quantite == Quantite_produit){
                            test=1;
                        printf("\n\t\t\t Code de Produit est     : %d \n",produit.Code);
                        printf("\n\t\t\t Nom de Produit est      : %s \n",produit.Nom);
                        printf("\n\t\t\t quantite de Produit est : %d \n",produit.Quantite);
                        printf("\n\t\t\t Prix de Produit est     : %.2f %s \n",produit.Prix,"DH");
                        printf("\t\t\t _______________________________________\n");
                    }
                }
                if(!test)
                    printf("code n'est pas Ajouter");
                fclose(file_produit);
                break;
        default:
            printf("\n\t\t\t choisir 1 ou 2 : \n");
            goto debut;
    }

}

int main()
{
    bienvenu();
    Option();
    return 0;
}
