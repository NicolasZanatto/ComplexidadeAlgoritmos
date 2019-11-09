#include <stdio.h>
#include <stdlib.h>

int vetor[100000];

int verificar(int v, int q){
	if((v<0)||(q<0)){
    	return 0;
	}
	if(v==0){
    	return 1;
	}
	return verificar(v-vetor[q],q-1)||verificar(v,q-1);
}

int main(){
	int v,q,i;
	char saida='N';
	while(scanf("%d %d",&v,&q)!=EOF){	
		for(i=1;i<=q;i++){
	    	scanf("%d",&vetor[i]);
		}
		if (verificar(v,q)!=0){
	    	saida='S';   
		}
	}
	printf("%c/n",saida);
}


