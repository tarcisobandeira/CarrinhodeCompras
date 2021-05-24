#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct{
	int codigo;
	char descricao[30];
	float precounit;
}Produto;

void addProdutos(Produto * p);

void ListarProd(Produto * p);

#endif
