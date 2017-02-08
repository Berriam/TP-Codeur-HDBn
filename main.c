#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NHDM 2

int NBITS = 500;


void decodeur(int Databis[], int Data[]){
	int i;
	int j;
	int d_bit = 0;
	for(i = 0; i < NBITS; i++){
		if(Databis[i] == -d_bit || Databis[i] == 0){
			Data[i] = fabs(Databis[i]);
			if(Databis[i] == -d_bit) d_bit = -d_bit;
		}
		else if(Databis[i] == d_bit){
			for(j = i; j >= i-NHDM; j--) Data[j] = 0;
		}
		else if(Databis[i] != 0){
			Data[i] = 1;
			d_bit = 1;
		}
		
	}
}

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

void afftab(int tab[]){
	int i;
	printf("\n\n\n");
	for(i = 0; i < NBITS; i++){
		printf("%i ", tab[i]);
	}
	printf("\n\n\n");
}

void NPtoDB(int P[], int N[], int Databis[]){
	int i;
	initZero(Databis, NBITS);
	for(i = 0; i < NBITS; i++){
		if(P[i]) Databis[i] = 1;
		if(N[i]) Databis[i] = -1;
	}
}

void entrerSequence(int Data[]){
	char serie[500];
	char c;
	int i;
	printf("entrez une série sans espace terminée par f: ");
	scanf("%s", serie);
	for(i = 0; i < 500; i++){
		c = serie[i];
		if(c != 'f' && c != '0' && c !='1'){
			printf("valeur %i incorrecte", i);
			break;
		}
		else {
			switch(c){
				case '0': Data[i] = 0; break;
				case '1': Data[i] = 1; break;
				case 'f': NBITS = i; i = 500; break;
			}
		}
	}
}


int encoder(int P[], int N[]){
	int choix = 0;
	int v = -1;
    	int Databis[NBITS];

    	int Data[NBITS]; 
    	
	printf("1. entrer une séquence à décoder\n");
	printf("2. décoder une séquence d'un fichier\n");
	printf("3. retour");
	printf("votre choix: ");
	scanf("%i", &choix);
	while (choix < 1 || choix > 3){
		printf("choix incorrect.\n");
		printf("entrez votre choix: ");
		scanf("%i", &choix);		
	}
	switch(choix){
		case 1: entrerSequence(Data); break;
		case 2: /*parFichier(2, NBITS, NHDM, Data);*/ break;
		case 3: return 1; break;
		default: printf("erreur"); break;
	}
	convertTab(Data, Databis, v);
    	dataBis(Databis, P, N);
    	afficher(P, N);
}  
               
void main(){
	int P[NBITS];
	int N[NBITS];
    	initZero(N, NBITS);
    	initZero(P, NBITS);
	int choix = 0;
	while(choix != 3){
		printf("1. encoder\n");
		printf("2. décoder\n");
		printf("3. quitter\n");
		printf("entrez votre choix: ");
		scanf("%i", &choix);
		while (choix < 1 || choix > 3){
			printf("choix incorrect.\n");
			printf("entrez votre choix: ");
			scanf("%i", &choix);		
		}
		switch(choix){
			case 1: choix = encoder(P, N); break;
			case 2: /*choix = decoder();*/ break;
			case 3: break;
			default: printf("erreur"); break;
		}
	}
	int NData[NBITS];/*
	int v = -1;
    	int P[NBITS];
    	int N[NBITS];
    	int Databis[NBITS];
    	initZero(N, NBITS);
    	initZero(P, NBITS);
    	int Data[NBITS]={1,0,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0}; 
    	convertTab(Data, Databis, v);
    	dataBis(Databis, P, N);
    	afficher(P, N);*/
    	
    	/*NPtoDB(P, N, Databis);
    	decodeur(Databis, NData);*/
    	afftab(NData);
}
