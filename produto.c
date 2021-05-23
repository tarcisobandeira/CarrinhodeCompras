#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto {
	int codigo;
	char descricao[30];
	float precounit;
};

void ListarProd(Produto * p) {
	int i;
	for(i=0;i<10;i++){
		if(i==9){
			printf("---------------\nProduto: %s\nCódigo:  %d\nValor:   %.2f\n---------------\n\n", p[i].descricao, p[i].codigo, p[i].precounit);
		}else{
			printf("---------------\nProduto: %s\nCódigo:  %d\nValor:   %.2f\n", p[i].descricao, p[i].codigo, p[i].precounit);
		}
	}
}

void addProdutos(Produto * p) {
	int i = 0;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Coca Cola");
	p[i].precounit = 7.00;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Doritos");
	p[i].precounit = 14.50;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Arroz Z");
	p[i].precounit = 24.00;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Milho de Pipoca");
	p[i].precounit = 5.19;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Cebola");
	p[i].precounit = 3.64;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Batata");
	p[i].precounit = 5.47;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Farinha");
	p[i].precounit = 14.36;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Candida");
	p[i].precounit = 17.10;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Queijo");
	p[i].precounit = 4.56;

	i++;

	p[i].codigo = i+1;
	strcpy(p[i].descricao, "Pão");
	p[i].precounit = 6.25;
}
