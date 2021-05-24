#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "carrinho.h"

Carrinho car;

void menuCarrinho(Produto * p){
	int opt;
	car.numitem = 0;
	do{
		printf("\n Carrinho de Compras\n");
		printf("\n Itens no Carrinho: %3d", car.numitem);
		printf("\n -----------------");
		printf("\n 555 para ver seu carrinho.");
		printf("\n 0 Finaliza a Compra.");
		printf("\n -----------------\n\n");
		printf(" Digite o código do produto: ");
		scanf("%d", &opt);
		
		switch(opt){
			case 0:
				break;
				
			case 555:
				if(car.numitem > 0){
					listarCarr();
				}else{
					printf("\n\n Você não tem itens no seu carrinho. \n\n\n");					
				}
				system("pause");
				system("cls");
				break;

			default:
				addCarrinho(opt, p);
				break;
		}
		
	}while(opt != 0);
	system("cls");
	finalizar(p);
	system("pause");
	system("cls");
	
}

void addCarrinho(int i, Produto * p){
	int j, k;
	char s;
	i--;
	printf("---------------\nProduto: %s\nCódigo:  %d\nValor:   %.2f\n---------------\n\n", p[i].descricao, p[i].codigo, p[i].precounit);
	
	printf(" Quer colocar esse item no carrinho?(S/N) ");
	fflush(stdin);
	scanf("%c", &s);
	
	if(s == 'S' || s == 's'){
		printf("\n Quantos? ");
		scanf("%d", &j);
		
		if(j>1){
			for(k=0;k<j;k++){
				car.valProc[car.numitem].codigo = p[i].codigo;
				strcpy(car.valProc[car.numitem].descricao, p[i].descricao);
				car.valProc[car.numitem].precounit = p[i].precounit;
		
				car.numitem += 1;
			}
			car.qnt_comp[i][1] += j;
			printf("\n Produtos adicionados.\n\n");
			
		}else{
			car.valProc[car.numitem].codigo = p[i].codigo;
			strcpy(car.valProc[car.numitem].descricao, p[i].descricao);
			car.valProc[car.numitem].precounit = p[i].precounit;
		
			car.numitem += 1;
			car.qnt_comp[i][1] += j;
			printf("\n Produto adicionado.\n\n");
		}
		system("pause");
	}
	system("cls");
}

void finalizar(Produto * p){
	printf("\n Nota da Compra:\n\n");
	
	int i,j=1;
	float total = 0;
	for(i=0;i<10;i++){
		if(car.qnt_comp[i][1] != 0){
			printf(" ---------------\n %3d° %s %3d X %.2f Reais\n", j, p[i].descricao, car.qnt_comp[i][1], p[i].precounit);
			j++;
		}
	}
	for(i=0;i<car.numitem;i++){
		total+= car.valProc[i].precounit;
	}
	printf(" ---------------\n\n Total: %.2f\n\n", total);
}

void listarCarr(){
	int i;
	float total = 0;
	for(i=0;i<car.numitem;i++){
		if(i==car.numitem-1){
			printf(" ---------------\n %3d° %s %.2f Reais\n ---------------\n\n", i+1, car.valProc[i].descricao, car.valProc[i].precounit);
		}else{
			printf(" ---------------\n %3d° %s %.2f Reais\n", i+1, car.valProc[i].descricao, car.valProc[i].precounit);
		}
		total+= car.valProc[i].precounit;
	}
	printf("\n Total: %.2f\n\n", total);
}
