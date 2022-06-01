#ifndef TETRIS_H
#define TETRIS_H
#endif
#define size(arr) ( sizeof(arr)/sizeof (arr[0] ))


// Fonction de Grille.c

void showTab(char* l);
void Initialisation(char* l);
int clearL(char*g,int*test);
void grav(char*g,int*test);


// Fonction de Piece.c

void PlacePiece(char* g, int* p, int c,int l);
int piecealea(int* dup);
void piecefullalea(int* dup, int nbr);
int aleaNbr(int min,int max);
void takeTab(int* l,int* l2);


// Fonction de Verif.c

int VerifC(char* g, int* p, int c,int alea);
int VerifL(char* g, int* p, int c);
void VerifP(char* g,int* comp);
int scanS(int min,int max);


// Fonction de Score.c

int nbL(FILE *fp);
void score(FILE *fp,int t,int point);
void TriSelec(int* l,char* g,int t);
void swap(int* a,int* b);
void swapC(char* a,char* b);
void show2(char* l,int* g,int nbr);


// Fonction de Menu.c

int Menue(void);
int rules(void);
int difficulte(int* dif);
int scorefull(FILE *fp);
int MiniMenu(void);
int temps(int dif);