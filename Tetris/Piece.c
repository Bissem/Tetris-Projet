#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int scanS(int min,int max);


// Liste des pieces et de leurs rotations.

int P1[4][10] = {{1,1,1,2,0,1,3}, {0,1,2,1,1,1,3}, {1,2,1,1,2,1,3}, {0,1,2,1,1,2,0,1,3}};
int P2[10] = {1,1,2,1,1,3};
int P3[2][10] = {{1,1,1,1,3},{1,2,1,2,1,2,1,3}};
int P4[2][10] = {{0,1,1,2,1,1,3},{1,2,1,1,2,0,1,3}};
int P5[2][10] = {{1,1,2,0,1,1,3},{0,1,2,1,1,2,1,3}};
int P6[4][10] = {{1,1,1,2,1,3},{1,2,1,2,1,1,3},{0,0,1,2,1,1,1,3},{1,1,2,0,1,2,0,1,3}};
int P7[4][10] = {{1,1,1,2,0,0,1,3},{1,1,2,1,2,1,3},{1,2,1,1,1,3},{0,1,2,0,1,2,1,1,3}};


// Permet de placer une piece.
// Prend en parametre la grille(tableau), la piece(tableau), la colonne et la ligne.

void PlacePiece(char* g, int* piece, int col,int lig){

    int curseur = 0 ;
    int nbrSaut = 0 ;

    for (int i = 0;*(piece+i)!=3;i++){

        curseur+=2;

        if (*(piece+i)==1){
            *(g+1+(lig-1)*22+(col-1)*2+curseur-2)='@';
        }

        else if (*(piece+i)==2){
            nbrSaut++;
            curseur = nbrSaut*22;
        }
    }
}


// Copie un tableau dans un autre (tab2 dans tab1).
// Prend en parametre les deux tableaux a echanger.

void takeTab(int* tab1,int* tab2){

    for(int i=0; i<10;i++){
        *(tab1+i) = *(tab2+i);
    }
}


// Prend en parametre le minimum et le maximum du chiffre aléaroire voulu et renvoie le  chiffre aléaroire.

int aleaNbr(int min,int max){

    srand(time(NULL));
    return (rand()%(max+1-min))+min;
}


// Donne une piece aléatoire et demande au joueur sa rotation.
// Prend en parametre le tableau dans lequelle stocker la piece et renvoie la piece choisie au hasard (ex: 7 pour P7)

int piecealea(int* copie){

    int rot;
    int nbr = aleaNbr(1,7);

    switch(nbr){

            case 1 :

                printf("Veuillez choisir l'orientation:\n\n\n\n");
                printf("               @@     @        @\n      @@@      @      @@@      @\n        @      @              @@\n\n       1       2       3       4\n");
                rot=scanS(1,4)-1;
                takeTab(copie,P7[rot]);
                return 7;

            case 2 :

                printf("Veuillez choisir l'orientation:\n\n\n\n");
                printf("               @        @     @@\n      @@@      @      @@@      @\n      @        @@              @\n\n       1       2       3       4\n");
                rot=scanS(1,4)-1;
                takeTab(copie,P6[rot]);
                return 6;

            case 3 :

                printf("Veuillez choisir l'orientation:\n\n\n\n");
                printf("                            @          @\n    @@@         @           @@        @@\n     @         @@@          @          @\n\n     1          2           3          4\n");
                rot=scanS(1,4)-1;
                takeTab(copie,P1[rot]);
                return 1;

            case 4 :

                printf("Veuillez choisir l'orientation:\n\n\n\n");
                printf("                     @\n    @@              @@\n     @@             @\n\n\n     1              2\n");
                rot=scanS(1,2)-1;
                takeTab(copie,P5[rot]);
                return 5;

            case 5 :

                printf("Veuillez choisir l'orientation:\n\n\n\n");
                printf("                    @\n     @@             @@\n    @@               @\n\n\n     1              2\n");
                rot=scanS(1,2)-1;
                takeTab(copie,P4[rot]);
                return 4;

            case 6 :

                printf("Veuillez choisir l'orientation:\n\n\n\n");
                printf("                    @\n                    @\n    @@@@            @\n                    @\n\n      1             2\n");
                rot=scanS(1,2)-1;
                takeTab(copie,P3[rot]);
                return 3;

            case 7 :

                printf("Voici votre piece:\n\n\n\n");
                printf("        @@\n        @@\n");
                takeTab(copie,P2);
                return 2;
    }
}


// Donne une piece completement aléatoire quand le joueur a dépasser le temps autorisé.
// Prend en parametre le tableau dans lequelle stocker la piece  et la piece choisie au hasard précédemment.

void piecefullalea(int* copie, int nbr){

    int rot;

    switch(nbr){

            case 1 :
                rot=aleaNbr(0,3);
                takeTab(copie,P1[rot]);
                break;

            case 2 :
                takeTab(copie,P2);
                break;

            case 3 :
                rot=aleaNbr(0,1);
                takeTab(copie,P3[rot]);
                break;

            case 4 :
                rot=aleaNbr(0,1);
                takeTab(copie,P4[rot]);
                break;

            case 5 :
                rot=aleaNbr(0,1);
                takeTab(copie,P5[rot]);
                break;

            case 6 :
                rot=aleaNbr(0,3);
                takeTab(copie,P6[rot]);
                break;
            case 7 :
                rot=aleaNbr(0,3);
                takeTab(copie,P7[rot]);
                break;
    }
}

