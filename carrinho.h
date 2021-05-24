#ifndef CARRINHO_H
#define CARRINHO_H

typedef struct carrinho{
	int numitem;
	int qnt_comp[10][1];
	Produto prod_car;
	Produto valProc[100];
} Carrinho;

void menuCarrinho(Produto * p);

void addCarrinho(int i, Produto * p);

void listarCarr();

void finalizar();

#endif
