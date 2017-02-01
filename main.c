#include <stdio.h>
#include <stdlib.h>

#define NBITS 24

void initZero(int tab[], int taille){
    int i;
    for(i = 0; i < taille; i++){
        tab[i] = 0; 
    }
}

void dataBis(int Databis[], int P[], int N[]){
    int i;
    for(i = 0; i < NBITS; i++){
        switch(Databis[i]{
            case 1: P[i] = 1; break;
            case -1: N[i] = 1; break;
            case 0: break;
            default: printf("erreur, valeur %i de dataBis invalide", i); 
        }
    }
}
               
void afficher(
               
void main(){
    int v = -1;
    int P[NBITS];
    int N[NBITS];
    int dataBis[NBITS];
    initZero(N, NBITS);
    initZero(P, NBITS);
    int Data[NBITS]={1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0}; 
    v = convertTab(Data, Databis, v);
    dataBis(Databis, P, N);
}
