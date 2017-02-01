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
int tripleZero(int Databis[], int v, int nint *neg){
	printf("\n\n\n%i\n\n\n", v);
	// cas ou V est positif	
	if(v==1){
		if (Databis[n-3]==1){
			Databis[n]=-1;
			Databis[n-2]=-1;
			*neg=-1;
		}
		else if(Databis[n-3]==-1){
			Databis[n]=-1;
			*neg=-1;
		}
	}
	
	//cas ou V est negatif
	if(v==-1){
		if (Databis[n-3]==-1){
			Databis[n]=1;
			Databis[n-2]=1;
			*neg=1;
		}
		else if(Databis[n-3]==1){
			Databis[n]=1;
			*neg=1;
		}
	}
	return -v;
} 

void convertTab(int Data[], int Databis[], int v){
	int n,comptZeros=0,neg=1;
	for(n=0;n<NBITS;n++){
		if(Data[n]==0){
			 comptZeros++;
			 Databis[n] = 0;
		}
		
		if(comptZeros==3){
			
			v=tripleZero(Databis,v,n,&neg);
			comptZeros=0;
		}
		else if(Data[n]!=0){
			comptZeros = 0;
			if(neg==1)Databis[n]=Data[n]; 
			else if(neg==-1)Databis[n]=-Data[n];
			neg=-neg;
		}	
	}
}

void afficher(int Databis[]){
	int i;
	printf("\n");
	for(i = 0; i < NBITS; i++){
		printf("%i ", Databis[i]);
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
    	afficher(Data);
    	afficher(Databis);
}
