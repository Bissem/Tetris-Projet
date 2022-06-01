
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Verifie si le chiffre entré pour la colonne est valide (entre 1 et 10 et si la pièce ne depasse pas de la grille).
// Prend en parametre la grille, la piece, la colonne choisie et si la fonction est ouverte en mode "caché" et renvoie si la colonne est bien placé ou non.

int VerifC(char* g, int* piece, int col,int alea){

    if ((col<0||col>10) && alea!=1){
        printf("Veuillez choisir une colonne entre 1 et 10 :\n");
        return 1 ;
    }

    else{
        int curseur = 0 ;
        int nbrSaut = 0 ;
        for (int i = 0;*(piece+i)!=3;i++) {
            curseur+=2;

            if (*(piece+i)==1){
                if (*(g+1+22+(col-1)*2+curseur-2)=='\n'){
                    if(alea!=1){
                        printf("Veuillez choisir une colonne qui ne depasse pas de la grille :\n");
                    }

                    return 1;
                }
            }

            else if (*(piece+i)==2){
                nbrSaut++;
                curseur = nbrSaut*22;
            }
        }

        return 0 ;
    }
}


// Verifie si la partie est perdue et sinon renvoie la ligne où dois etre positionné la piece.
// Prend en parametre la grille, la piece et la colonne et renvoie la ligne ou placer la piece.

int VerifL(char* g, int* piece, int col){

    int curseur = 0 ;
    int nbrSaut = 0 ;
    int ligne = 1;


    // Verifie si la partie est perdu.

    for(int i = 0;*(piece+i)!=3;i++){
        curseur+=2;

        if (*(piece+i)==1){
            if (*(g+1+(col-1)*2+curseur-2-22)=='@'){
                return 0;
            }
        }

        else if (*(piece+i)==2){
            nbrSaut++;
            curseur = nbrSaut*22;
        }
    }


    // Donne la ligne sur laquelle placé la pièce.

    while (ligne<=10){
        curseur = 0;
        nbrSaut = 0;

        for (int i = 0;*(piece+i)!=3;i++) {
            curseur+=2;

            if (*(piece+i)==1){
                if (*(g+1+(col-1)*2+curseur-2+(ligne-1)*22)=='@'){
                    return ligne-1;

                }
            }

            else if (*(piece+i)==2){
                nbrSaut++;
                curseur = nbrSaut*22;
            }
        }

        ligne++;
    }

    return ligne-(nbrSaut+1);
}


// Scanf sécurisé : verifie si ce que l'utilisateur entre est bien un chiffre et si il est bien compris entre le min et le max donné.
// Prend en parametre le minimum et le maximum du scanf et renvoie le scanf reussi.

int scanS(int min,int max){

    int val;

    while(1){
        if (scanf("%d",&val)==0){
            printf("\nVeuillez ecrire un chiffre :\n\n");
        }

        else if(val<min || val>max){
            printf("\nVeuillez ecrire un chiffre entre %d et %d:\n\n",min,max);

        }

        else{
            return val;
        }

        scanf("%*[^\n]%*1[\n]");

    }
}


// Verifie si une ligne est complète.
// Prend en parametre la grille, et un tableau et renvoie ce tableau avec un 1 si la ligne est pleine sinon un 0, chaque case du tableau vaut une ligne.

void VerifP(char* g,int* tab){

    for (int j=0;j<10;j++){
        *(tab+j)=1;

        for (int i=0;i<10;i++){
            if(*(g+1+2*i+j*22) == ' '){
                *(tab+j)=0;
            }
        }
    }
}