#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Tetris.h"


// Gère la difficulté.
// Prend en parametre la difficulté choisie retourne les secondes disponiilbes pour répondre.

int temps(int dif){

    if (dif ==1){
        return 30;
    }
    else if (dif ==2){
        return 15;
    }
    else if (dif ==3){
        return 8;
    }
    return 4;
}


// Menue du Jeu, relié aux différentes modules du jeu.
// Renvoie le choix pour naviguer dans les modules.

int Menue(void){

    printf("\n\n  *++++++++++++++++++*   ------------------+   :::::::::::::::::::   -================       -=======      ++*************\n  ********************   -================-+   .:::::::::::::::::-   -==================     -=======    +***************\n  ********************   ------------------+   .:::::::::::::::::-   -===================    -=======   +**************+\n  ********************   ------============+   .:::::::::::::::::-   -===================+   -=======  =+++++++++******\n        ********         ------+                     -:::::-         ------=-   *-------=*   -=======  =+++++++++\n        ********         :-----+                     :.....-         ------=    +-------+    -------=   =++++++++\n        ********         ::::::+                     ::::::-         -------    -------=     =------=    +++++++*\n        ********         ::::::-----:::-+            -------         =*+++**  =++===--+      =------+     +++++++++\n        ********         ::::::::--==++*             -------         =++++++=:+++++++*       =------+      ++=====++\n        ********         ::--=========*              -------         =++++++   +++++++*      =+++==-+       .+======*\n        ********         ============*               ::::::-         =++++++    ++++++++     =+++++++         +======+\n        ********         ======+                     ::::::-         ======+     +=======    ==++++++          *======+*\n        ********         ======+                     ::::::-         ======+      ========   +======+           ++======*\n        ********         =-----+                     ::::::-         =======       =======+  +======+            *+======*\n        ********         =-----=                     :::::::         =======        ======+  +======+            ***+=====*\n        ********         =-------=====-------        :::::::         +-----=         =---=*  +======*   *********++++++===*\n        ********         +--------------------       ......:         +-----=          =---*  *=====-*   ++++++++++++++++++\n        ********          +--------------------      ......:         +------           ---*  *------*   ++++++++++++++++*\n        ********            =-:::::::::::::::::-     ......:         +:-----            --*  *------*   *+++++++++++++*=\n\n\n\n\n ");
    printf("\n\n\n-----------------------------------------------------------------------------------------\n\n");
    printf("     1)Lancer une partie\n\n     2)Regle du jeu\n\n     3)Difficulte\n\n     4)Score\n\n     5)Quitter la partie\n\n");
    printf("-----------------------------------------------------------------------------------------\n\n");

    return scanS(1,5);
}


// Permet de relié les modules du jeu entre eux.
// Renvoie le choix pour naviguer dans les modules.

int MiniMenu(void){

    printf("\n\n\n-----------------------------------------------------------------------------------------\n\n");
    printf("    1)Lancer une partie\n\n    2)Revenir au Menu\n\n    3)Quitter\n\n");
    printf("-----------------------------------------------------------------------------------------\n\n");

    int choix = scanS(1,3);
    switch (choix){
    case 1:
        return 1;
    case 2:
        return 6;
    case 3:
        return 5;
    }
}


// Module donnant les régles.
// Renvoie le choix pour naviguer dans les modules.

int rules(void){

    printf("\nTetris met le joueur au defi de realiser des lignes completes en deplacant des pieces de formes differentes, les tetrominos, qui apparaisent au hasard parmis les 7 disponibles chaque tour.\nLes lignes completees disparaissent tout en rapportant des points et le joueur peut de nouveau remplir les cases liberees.\n\n");
    printf("Chaque tour vous pouvez choisir l'orientation de vos pieces en entrant des chiffres de 1 a 4.\nPuis vous pouvez choisir la colonne ou votre piece tombera en ecrivant un chiffre entre 1 et 10 (attention a ne pas faire depasse votre piece de la grille).\nLa colonne que vous choisirez correspondera a la position de l'@ la plus a gauche de la rotation choisie.\n\n");
    printf("Vous possedez un temps limite pour donner votre orientation et votre colonne chaque tour.\nCe temps est defini par la difficulte du jeu (par defaut : Facile(30s)).\nSi vous repondez trop tard, la piece sera placee avec une orientaion et une colonne tirees aleatoirement.\n\n");
    printf("\nLes points sont calcules de cette facon :\n  - Votre score commence a 0.\n  - Des point sont ajoutes a chaque fois que vous detruisez des lignes.\n  - Les points ajoutes correspondent aux nombres de lignes detruites simulatnement au carre.\n             ex) 3 lignes detruites = 9 points.\n\n");

    return MiniMenu();
}

// Module donnant la difficulté.
// Prend en parametre l'adresse de la varible ou est stocker la difficulté et renvoie le choix pour naviguer dans les modules.

int difficulte(int* dif){

    printf("\nVeuillez choisir votre difficulte, elle changera la duree que vous aurez pour repondre chaque tour:\n\n");
    printf("\n  1) Facile(30s)\n\n  2) Normal(15s)\n\n  3) Dur(8s)\n\n  4) Extreme(4s)\n");
    *(dif) = scanS(1,4);

    return MiniMenu();
}

// Module donnant les scores.
// Prend en parametre le fichier et renvoie le choix pour naviguer dans les modules

int scorefull(FILE *fp){

    score(fp,2,0);

    return MiniMenu();
}
