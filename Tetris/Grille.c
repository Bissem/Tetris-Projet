#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Affiche la grille.
// Prend en parametre la grille

void showTab(char* g){

    printf("\n\n 1 2 3 4 5 6 7 8 9 10\n\n");

    for(int i=0 ; i<220 ; i++){
        printf("%c",*(g + i));
    }

    printf("\n");

}


// Initilialise la grille en debut de jeu.
// Prend en parametre la grille

void Initialisation(char* g){

    for (int i = 0; i<220;i+=2){
        *(g+i) = '|';
    }

    for (int i = 1; i<221;i+=2){
        *(g+i) = ' ';
    }

    for (int i = 21; i<221;i+=22){
        *(g+i) = '\n';
    }
}


// Retire les lignes pleines et renvoie leurs nombres.
// Prend en parametre la grille et le tableau qui donne les lignes pleine et renvoie le nombre de ligne pleine;

int clearL(char*g,int* ligne){

    int pts = 0;

    for(int i =0;i<10;i++){
        if (*(ligne+i)==1){
            for(int j=0;j<10;j++){
                *(g+1+2*j+22*i)=' ';
            }
            pts++;
        }
    }
    return pts;
}


//  Fait tomber les lignes une fois que celles pleines sont retirées.
// Prend en parametre la grille et le tableau qui donne les lignes pleine

void grav(char*g,int* ligne){

    for(int i =1;i<10;i++){

        if (*(ligne+i)==1){

            for(int j=(i*22)+19;j>22;j-=2){

                if(*(g+j-22)!='\n'){
                    *(g+j)=*(g+j-22);
                }
            }

            for(int k =0;k<10;k++){
                *(g+1+(k*2))=' ';
            }
        }
    }
}


