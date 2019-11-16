#include <stdio.h>
#include <stdlib.h>

int V[4] = {10,7,25,24};
int P[4] = {2,1,6,5};
int max = 7;

int F[5][8];

void inicializarF(){
	int i,j;
	for(i =0; i<5; i++){
		for(j =0 ;j<8;j++){
			F[i][j] = 0;
		}
	}
}

int maiorValor(int a, int b){
	if(a > b)
		return a;
	
	return b;
}

void executar(){
	int i,j;
	for(i =1; i<5; i++){
		for(j =1 ;j<8;j++){
			if(P[i-1] > j){
				F[i][j] = F[i-1][j];
			}	
			else{
				F[i][j] = maiorValor(F[i-1][j-P[i-1]] + V[i-1], F[i-1][j]);	
			}
		}
	}
}

void mostrarF(){
	int i,j;
	for(i =0; i<5; i++){
		for(j =0 ;j<8;j++){
			printf("%d\t",F[i][j]);
		}
		printf("\n");
	}
}

void mochila(){
	inicializarF();
	executar();
	mostrarF();
}



int main(){
	mochila();
}
