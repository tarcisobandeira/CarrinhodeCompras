#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
	int codigo;
	char descricao[9];
	float precounit;
} produto;

typedef struct{
	int numitem;
	struct produto *p;
	int qtd;
	float *precototal;
} carrinho;

void printar(produto p){
	fflush(stdin);
	printf("%d, %s, %.2f\n", p.codigo, p.descricao, p.precounit);
}

produto addProdutos(produto p, int i){
	p.codigo = i+1;
	fflush(stdin);
	strncpy(p.descricao, "Coca Cola", 9);
	p.precounit = (float) i + 0.5;
	
	return p;
}

void main(){
	setlocale(LC_ALL, "Portuguese");
	int i;
	produto estoque[99];
	
	for(i=0;i<=99;i++){
		estoque[i] = addProdutos(estoque[i],i);	
	}
	for(i=0;i<=99;i++){
		printar(estoque[i]);
	}
	
}
