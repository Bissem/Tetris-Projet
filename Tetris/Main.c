#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Tetris.h"


int main(){


    // Initialisation des variables.

    int colone;
    int piece[10];
    int fullL[10];
    char grille[220];
    int nbrL;
    int dif=1;
    char rep[3];
    int enr;
    int testL;
    int points;
    int testC;
    int numPiece;
    time_t begin;
    time_t end;
    unsigned long secondes;


    // Lancement du menu.

    int choixM =Menue();

    while(choixM!=5){


        // Module jeu.

        if(choixM==1){


            // Variable a reinitialiser a chaque debut de partie.

            testL = 1;
            points = 0;


            // Création de la grille et affichage du debut du jeu.

            Initialisation(grille);
            printf("\nLa partie va commence, bonne chance!\n\n");
            printf("\n\n------------------------------\n\n");
            printf("Voici votre grille:\n\n");
            showTab(grille);

            while (testL!=0){

                testC = 1;

                begin = time( NULL );
                numPiece = piecealea(piece);

                printf("\nVeuillez choissir votre colonne:\n\n");

                while(testC){

                    if (scanf("%d",&colone)==0){
                        printf("Veuillez ecrire un chiffre:\n\n");}

                    else{
                        testC =  VerifC(grille,piece,colone,0);
                    }

                    scanf("%*[^\n]%*1[\n]");
                }

                end = time( NULL);
                secondes = difftime(end,begin);


                // Pièce aléatoire si le temps est dépassé.

                if (secondes>temps(dif)){

                    piecefullalea(piece,numPiece);
                    testC = 1;

                    while(testC){
                        colone = aleaNbr(1,10);
                        testC = VerifC(grille,piece,colone,1);
                    }
                    printf("\n\nVous avez depasse les %d secondes accordees, la rotation et la colonne seront donc choisie aleatoiremment.\n\n",temps(dif));

                }


                // Donne la ligne sur laquelle placer la piece ou fini le jeu si perdu.

                testL = VerifL(grille,piece,colone);

                if(testL!=0){


                    //Place la piece et affiche la grille

                    PlacePiece(grille,piece,colone,testL);

                    printf("\n\n------------------------------\n\n");
                    printf("Voici votre grille:\n\n");
                    showTab(grille);


                    // Verifie si une ligne est complète, augmente les points et affiche la grille.

                    VerifP(grille,fullL);
                    nbrL = clearL(grille,fullL);

                    if(nbrL!=0){
                        showTab(grille);

                        points+=nbrL*nbrL;

                        grav(grille,fullL);
                        showTab(grille);
                    }
                }
            }


            // Fin du jeu, afficher et enregistremnt du score si voulu.

            printf("\n\n------------------------------\n\n");
            printf("\nPerdu, vous avez %d points.\n\n",points);
            printf("Voulez vous enregistrer votre score (oui/non):\n\n");

            while(1){
                scanf("%s",rep);

                if(rep[0]=='o' && rep[1]=='u' && rep[2]=='i'){
                    enr=1;break;
                }

                else if(rep[0]=='n' && rep[1]=='o' && rep[2]=='n'){
                    enr=0;
                    break;
                }

                printf("\nVeuillez repondre oui ou non :\n\n");
            }

            FILE *save = fopen("save.txt","r+");
            printf("\n\n");
            score(save,enr,points);
            fclose(save);

            choixM=MiniMenu();

        }


        // Module règle.

        if(choixM==2){
            choixM=rules();
        }


        // Module difficulté.

        if(choixM==3){
            choixM=difficulte(&dif);
        }


        // Module score.

        if(choixM==4){
            FILE *save = fopen("save.txt","r+");
            choixM=scorefull(save);
            fclose(save);
        }


        // Module menu.

        if(choixM==6){
            choixM=Menue();
        }
    }
}