#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Prend en parametre le fichier et renvoi son nombre de ligne.

int nbL(FILE *fp) {

    int nbr =0;
    char cara;

    while ((cara=getc(fp))!=EOF){
		if (cara=='\n'){
            nbr++;
        }
	}

    rewind(fp);
    return nbr+1;
}


// Affiche les scores.
// Prend en parametre le tableau qui contient les pseudo, le tableau qui contient les scores et le nombre de ligne à afficher.

void show2(char* l,int* g,int nbr){

    for(int j=0 ; j<nbr ; j++){

        printf("%d) ",j+1);

        for(int i=0 ; i<15 ; i++){
            if(*(l +i+j*15)==';'){
                break;
            }

            printf("%c",*(l +i+j*15));
        }

        printf("   %d\n",*(g + j));
    }
}


// Inverse deux variables de type int.
// Prend en parametre les adresses de ces 2 variables.

void swap(int* a,int* b){

    int temp = *a ;
    *a = *b ;
    *b = temp ;
}


// Inverse deux variables de type char.
// Prend en parametre ces deux tableaux de caractère.

void swapC(char* a,char* b){

    char temp[15];

    for(int i =0;i<15;i++){
        temp[i] = *(a+i);
        if(*(a+i)==';'){
            break;
        }
    }

    for(int j =0;j<15;j++){
        *(a+j) = *(b+j);
        if(*(b+j)==';'){
            break;
        }
    }

    for(int k =0;k<15;k++){
        *(b+k) = temp[k];
        if(temp[k]==';'){
            break;
        }
    }
}


// Tri selective décroissant du tableau ou est stocké le score (et effectue les meme échanges sur le tableau des pseudo).
// Prend en parametre le tableau des scores, le tableau des pseudo et la partie a trier.

void TriSelec(int* l,char*g,int taille){

    for(int i=0;i<taille;i++){
        int tri = i;

        for(int j=1+i;j<taille;j++){
            if(*(l+tri)<*(l+j)){
                tri = j;
            }
        }

        swap(l+tri,l+i);
        swapC(g+tri*15,g+i*15);
    }
}


// Met les pseudo et les scores dans un fichier et ajoute les scores et pseudo de la partie dans le fichier si demandé.
// Prend en parametre le fichier, les option pour laquelle utilisé la fonction et le score.

void score(FILE *fp,int option,int point){

    int nbr = nbL(fp);
    char nom[1000][15];
    int pts[1000];
    int verif = 0;


    // Stock les infos du fichier dans des tableaux utilisables.

    for(int i=0;i<nbr;i++){
        fscanf(fp,"%s %d",nom+i,pts+i);
    }

    pts[nbr]= EOF;
    nom[nbr][0]= EOF;


    // Sauvegarde les points avec un pseudo.

    if (option==1){
        int check =1;
        char name[14];
        printf("Veuillez entrer votre pseudo (max 14 caracteres):\n\n");

        while(check){
            scanf("%s",&name);

            for(int j=0;j<nbr;j++){
                check = 1;

                for(int k=0;k<14;k++){
                    if(nom[j][k]==';'){
                        break;
                    }

                    else if(nom[j][k]!=name[k]){
                        check =0;
                        break;
                    }
                }

                if(check){
                    printf("\nVotre pseudo est deja prit, veuillez en choisir un autre:\n\n");
                    break;
                }
            }
        }

        fseek(fp,0,SEEK_END);
        fputc('\n',fp);
        fprintf(fp,"%s; %d",name,point);
        rewind(fp);
        verif=1;
        score(fp,0,point);
    }


    // Affiche le score.

    if(verif!=1){
        TriSelec(pts,nom[0],nbr);

        if(option==0 || option==1){
            printf("\nVoici le top 10:\n\n");
            show2(nom[0],pts,10);
        }

        else{
            printf("\nVoici la totalite des scores sauvegardes:\n\n");
            show2(nom[0],pts,nbr);
        }
    }
}
