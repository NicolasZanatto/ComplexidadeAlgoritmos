#include <stdio.h>
#include <stdlib.h>

int F[1001][100001];

int maiorValor(int a, int b){
	if(a > b)
		return a;
	
	return b;
}

void mochila(){
	int max, N,i,j;
	
	//leitura
	while(scanf("%d %d",&max,&N) != EOF){
		int V[N];
		for(i = 0; i<N;i++){
			scanf("%d",&V[i]);
		}
		int linhas = N+1; 
		int colunas = max + 1;
		
		
		//zerando matriz
		for(i =0; i<linhas; i++){
			for(j =0 ;j<colunas;j++){
				F[i][j] = 0;
			}
		}
		
		//execucao
		for(i =1; i<linhas; i++){
			for(j =1 ;j<colunas;j++){
				if(V[i-1] > j){
					F[i][j] = F[i-1][j];
				}	
				else{
					F[i][j] = maiorValor(F[i-1][j-V[i-1]] + V[i-1], F[i-1][j]);	
				}
			}
		}
		
		int ehPossivel = 0;
		for(i =0;i<linhas;i++){
			if(F[i][max] == max)
				ehPossivel = 1;
		}
		
		if(ehPossivel == 1)
			printf("S\n");
		else
			printf("N\n");
	}
}



int main(){
	mochila();
}
