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
        	switch(Databis[i]){
           	 case 1: P[i] = 1; break;
            	case -1: N[i] = 1; break;
            	case 0: break;
            	default: printf("erreur, valeur %i de dataBis invalide", i); 
        	}
   	 }
}
int tripleZero(int Data[], int v, int n){
	// cas ou V est positif	
	if(v==1){
		if (Data[n-3]==1){
			Data[n]=-1;
			Data[n-2]=-1;
		}
		else if(Data[n-3]==-1){
			Data[n]=-1;
		}
	}
	
	//cas ou V est negatif
	if(v==-1){
		if (Data[n-3]==-1){
			Data[n]=1;
			Data[n-2]=1;
		}
		else if(Data[n-3]==1){
			Data[n]=1;
		}
	}
	return -v;
} 

int convertTab(int Data[], int Databis[], int v){
	int n,comptZeros=0,neg=0;
	for(n=0;n<NBITS;n++){
		if(Data[n]==0) comptZeros++;
		if(comptZeros==3){
			v=tripleZero(Databis,v,n);
			comptZeros=0;
		}
		else{
			if(neg==0)Databis[n]=Data[n]; 
			else if(neg==1)Databis[n]=-Data[n];
			neg=-neg;
		}	
	}
	return v;
}

void afficher(int Databis[]){
	int i;
	for(i = 0; i < NBITS; i++){
		printf("%i", Databis[i]);
	}
}
               
void main(){
	int v = -1;
    	int P[NBITS];
    	int N[NBITS];
    	int Databis[NBITS];
    	initZero(N, NBITS);
    	initZero(P, NBITS);
    	int Data[NBITS]={1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0}; 
    	v = convertTab(Data, Databis, v);
    	dataBis(Databis, P, N);
    	afficher(Databis);
}
