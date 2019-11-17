#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mochila(int w[], int v[], int m[], int N, int T, int count){
	m[0] = 0;
	int i,j;
	for(i = 1;i<=T;i++){
		m[i] = m[i-1];
		for(j = 0;j<N;j++){
			if(w[j]<=i && m[i-w[j]] + v[j]> m[i])
				m[i] = m[i-w[j]]+ v[j];	
		}
	}
	
	printf("Instancia %d\n%d\n\n",count,m[T]);	
}


int main(){
	int i,N,T;
	int count = 1;
	scanf("%d %d",&N,&T);
	while(N != 0){
		int w[N], v[N], m[T];
		
		memset(m,-1,sizeof(m));
		
		for(i=0;i<N;i++)
			scanf("%d %d",&w[i],&v[i]);
		
		mochila(w,v,m,N,T,count);
		
		scanf("%d %d",&N,&T);
		count++;
	}		
}

