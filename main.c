// realisé par BRINON Baptiste et BERARD William
#include <stdio.h>
#include <stdlib.h>

#define NBITS 23
#define NHDM 2

void initZero(int tab[], int taille){
    	int i;
    	for(i = 0; i < taille; i++){
     	   tab[i] = 0; 
    	}
}
// conversion de Databis en 2 tableaux P et N
void dataBis(int Databis[], int P[], int N[]){
    	int i;
    	for(i = 0; i < NBITS; i++){
        	switch(Databis[i]){
           	case 1: P[i] = 1; break;
            	case -1: N[i] = 1; break;
            	case 0: break;
            	default: printf("erreur, valeur %i de dataBis invalide", i); 
        	}
   	 }
}
// applique l'algorithme en cas de depassement du nombre autorisé de zeros de suite
int tropZero(int Databis[], int v, int n,int *signe){
	// cas ou V est positif	
	if(v==1){
		if (Databis[n-(NHDM+1)]==1){
			Databis[n]=-1;
			Databis[n-NHDM]=-1;
			*signe=1;
		}
		else if(Databis[n-(NHDM+1)]==-1){
			Databis[n]=-1;
			*signe=1;
		}
	}
	
	//cas ou V est negatif
	if(v==-1){
		if (Databis[n-(NHDM+1)]==-1){
			Databis[n]=1;
			Databis[n-NHDM]=1;
			*signe=-1;
		}
		else if(Databis[n-(NHDM+1)]==1){
			Databis[n]=1;
			*signe=-1;
		}
	}
	return -v;
} 

void convertTab(int Data[], int Databis[], int v){
	int n,comptZeros=0,signe=1; // signe indique si le 1 à venir est negatif ou positif
	for(n=0;n<NBITS;n++){
		//cas ou le chiffre traité est 0
		if(Data[n]==0){
			 comptZeros++;
			// verification du depassement ou non de 0 autorisés
			if(comptZeros==(NHDM+1)){	
				v=tropZero(Databis,v,n,&signe);
				comptZeros=0;
			}
			else Databis[n] = 0;
		}
		
		// cas s'il s'agit de 1
		else {
			comptZeros = 0;
			if(signe==1)Databis[n]=Data[n]; 
			else if(signe==-1)Databis[n]=-Data[n];
			signe=-signe;
		}	
	}
}

void afficher(int P[], int N[]){
	int i;
	printf("\n");
	for(i = 0; i < NBITS; i++){
		printf("%i ", P[i]-1*N[i]);
	}
	printf("\n");
}
               
void main(){
	int v = -1;
    	int P[NBITS];
    	int N[NBITS];
    	int Databis[NBITS];
    	initZero(N, NBITS);
    	initZero(P, NBITS);
    	int Data[NBITS]={1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0}; 
    	convertTab(Data, Databis, v);
    	dataBis(Databis, P, N);
    	afficher(P, N);
}
