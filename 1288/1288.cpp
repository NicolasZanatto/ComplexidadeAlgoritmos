#include <stdio.h>
#include <stdlib.h>

int maiorValor(int a, int b){
	if(a > b)
		return a;
	
	return b;
}

void mochila(){
	int T,N,i,j,k,max,R;
	
	scanf("%d",&T);
	for(k =0; k<T;k++){
		scanf("%d",&N);
		int V[N];
		int P[N];
		for(i =0; i<N;i++){
			scanf("%d %d",&V[i],&P[i]);
		}
		scanf("%d",&max);
		scanf("%d", &R);
		int F[N+1][max+1];
		for(i =0; i<N+1; i++){
			for(j =0 ;j<max+1;j++){
				F[i][j] = 0;
			}
		}
		
		for(i=1; i<N+1; i++){
			for(j =1 ;j<max+1;j++){
				if(P[i-1] > j){
					F[i][j] = F[i-1][j];
				}	
				else{
					F[i][j] = maiorValor(F[i-1][j-P[i-1]] + V[i-1], F[i-1][j]);	
				}
			}
		}
		
		if(F[N][max] >=R)
			printf("Missao completada com sucesso\n");
		else
			printf("Falha na missao\n");
		
	}
}



int main(){
	mochila();
}
