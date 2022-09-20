#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


    //declare structeure
    struct Produit{
        int Code;
        char Nom[20];
        int Quantite;
        float Prix;
    };

    //les varaible global
    float minPrix = 0, maxPrix = 0 ,moyennePrix = 0 ,totalPrix = 0 ,nbrVente = 0;
    struct Produit produit;
    FILE *file_produit;

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
        printf("\t \t 7_ Ajouter le produit dans le stock \n");
        printf("\t \t 8_ Exit \n");
        printf("\t \t===========================================\n");
        scanf("%c",&choix);
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
//                sort();
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
                system("cls");
                afficherStatistique();
                getch();
                system("cls");
                break;
            case 55:
                system("cls");
                Stock();
                getch();
                system("cls");
                break;
            case 56:
                exit(0);
                break;
        }
    };


//Ajouter un Produit
void Ajouter_Produit(){
    int nbr;
    file_produit = fopen("Produit.txt","a");
    printf("\n\t\t Donner le nombre des produits     :");
    scanf("%d",&nbr);
    struct Produit produit;
    while( nbr != 0){
        system("cls");
        printf("\t====Ajouter un nouveau produit=== \n");
        printf("\n\t\t Donner le code de produit     :");
        scanf("%d",&produit.Code);
        printf("\n\t\t Donner le nom de produit      :");
        scanf("%s",&produit.Nom);
        printf("\n\t\t Donner le quantite de produit :");
        scanf("%d",&produit.Quantite);
        printf("\n\t\t Donner le prix de produit     :");
        scanf("%f",&produit.Prix);
        fwrite(&produit,sizeof(struct Produit),1,file_produit);
        nbr--;
    }
    fclose(file_produit);
}

//Rechercher Produit
void Rechercher_Produit(){
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
                system("cls");
                printf("\n\t\t\t choisir 1 ou 2 : \n");
                goto debut;
    }
}

//Afficher les Listes des Produits
void AfficherListeProduit(){
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

//Supprimer des Produits par code
void SupprimerProduit(){

    FILE *file_produit_supprimer;
    int code ;
    int existe=0;
    file_produit=fopen("produit.txt","r");
    file_produit_supprimer=fopen("supp_produit.txt","w");
    printf("\t\t\t\t======= SUPPRIMER LE PRODUIT=======\n\n\n");

    printf("\t\t\t\t Donner le code de produit : ");
    scanf("%d",&code);
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
    else{
        remove("produit.txt");
        rename("supp_produit.txt","produit.txt");
        printf("\n\t\t\t\tproduit est supprimer\n");
    }
    getch();
}

//Achate les produit
void Acheter(){
    struct Produit produit_Achat;
    FILE *file_produit_Achat;
    int code;
    int existe = 0;
    double tprix;
    float quantite;
    file_produit = fopen("produit.txt","r");
    file_produit_Achat = fopen("produit_Achat.txt","w");
    printf("Donner le code de produit ");
    scanf(" %d",&code);
    printf("Donner le quantite de vende :");
    scanf(" %f",&quantite);
     while(fread(&produit,sizeof(struct Produit),1,file_produit)){
        if(produit.Code == code && produit.Quantite >= quantite  ){
            existe=1;
            produit_Achat.Code = produit.Code ;
            strcpy(produit_Achat.Nom,produit.Nom);
            produit_Achat.Quantite = produit.Quantite - quantite;
            produit_Achat.Prix = produit.Prix;
            tprix = (produit.Prix + 0.15)* quantite;
            //function enregistrer le prix TTC et la date
            ListeAchate(tprix,produit_Achat.Nom);
            //function calculer les satistique
            statistique(tprix);
            printf("\n\t\t\t\t produit est achat \n");
            printf(" PRIX TOTAL EST  : %.2f %s\n",tprix,"DH");
            fwrite(&produit_Achat,sizeof(struct Produit),1,file_produit_Achat);
        }
        else{
           fwrite(&produit,sizeof(struct Produit),1,file_produit_Achat);
        }
    }

    fclose(file_produit);
    fclose(file_produit_Achat);
    remove("produit.txt");
    rename("produit_Achat.txt","produit.txt");
    if(!existe)
        printf("Produit n est existe pas");

}

//function enregistrer le prix TTC et la date d’achat
void ListeAchate(double prix,char nom[10]){
    FILE *file_achate;
    time_t temp = time(0);
    char date[20];
    strcpy(date,ctime(&temp));
    file_achate = fopen("Liste_Achat","a");
    fprintf(file_achate,"Nom de produit : %s \n",nom);
    fprintf(file_achate,"Date d achate produit est : %s \nLe Prix TTC : %.2f %s\n",date,prix,"DH");
    fprintf(file_achate,"_______________________________________________________\n");
    fclose(file_achate);
}
//function calculer les satistique
void statistique(double prix){
    if(maxPrix < prix)
        maxPrix = prix;
    if( minPrix == 0 || prix < minPrix )
        minPrix = prix;
    totalPrix+=prix;
    nbrVente++;
}

//Aficher les satistique des les produits vente Aujourd hui
void afficherStatistique(){

    time_t date = time(0);
    printf("\n\t\t\t la journe courante                       : %s \n",ctime(&date));
    printf("\n\t\t\t le totale des prix des produits vendue   : %.2f %s\n",totalPrix,"DH");
    printf("\n\t\t\t le max prix de produit vendue            : %.2f %s\n",maxPrix,"DH");
    printf("\n\t\t\t le min prix de produit vendue            : %.2f %s\n",minPrix,"DH");
    printf("\n\t\t\t le moyenne des prix des produits vendues : %.2f \n",totalPrix / nbrVente );
}

//Ajouter les Quntite des produit
void Stock(){
    struct Produit produit_Stock;
    FILE *file_produit_Stock;
    int code;
    int existe = 0,quantite;
    file_produit = fopen("produit.txt","r");
    file_produit_Stock = fopen("produit_Sockt.txt","w");
    printf("Donner le code de produit ");
    scanf(" %d",&code);

    while(fread(&produit,sizeof(struct Produit),1,file_produit)){
        if(produit.Code == code){
            existe=1;
            printf("Donner le quantite de vende :");
            scanf(" %d",&quantite);
            produit_Stock.Code = produit.Code;
            strcpy(produit_Stock.Nom,produit.Nom);
            produit_Stock.Quantite = produit.Quantite + quantite;
            produit_Stock.Prix = produit.Prix;
            printf("\n\t\t\t\t quantite  est modifier \n");

            fwrite(&produit_Stock,sizeof(struct Produit),1,file_produit_Stock);
        }else{
           fwrite(&produit,sizeof(struct Produit),1,file_produit_Stock);
        }
    }
    fclose(file_produit);
    fclose(file_produit_Stock);
    remove("produit.txt");
    rename("produit_Sockt.txt","produit.txt");
    if(!existe)
        printf("Produit n est existe pas");
}

//void sort(){
//    struct Produit produit[100],pro[100];
//    file_produit = fopen("produit.txt","r");
//
//    while(fread(&produit[100],sizeof(struct Produit),1,file_produit)){
//        for(int i=0;i<100;i++){
//            for(int j=0;j<100;j++){
//                if(produit[i].Prix < produit[j].Prix){
//                    pro[i] =produit[i];
//                    produit[i]=produit[j];
//                    produit[j]=pro[i];
//                }
//            }
//        }
//    }
//    for(int i=0;i<100;i++){
//        printf("\n\t\t\t Code de Produit est     : %d \n",produit[i].Code);
//        printf("\n\t\t\t Nom de Produit est      : %s \n",produit[i].Nom);
//        printf("\n\t\t\t quantite de Produit est : %d \n",produit[i].Quantite);
//        printf("\n\t\t\t Prix de Produit est     : %.2f %s \n",produit[i].Prix,"DH");
//    }
//
//    fclose(file_produit);
//
//
//
//}


int main()
{
    int choix;
    do{
        Option(choix);
    }while(choix <= 48 || choix > 56);


    return 0;
}
