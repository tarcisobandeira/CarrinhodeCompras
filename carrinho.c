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
		printf("\n 777 para ver a lista de itens no mercado.");
		printf("\n   0 para Finaliza a Compra.");
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
	
			case 777:
				system("cls");
				ListarProd(p);
				system("pause");
				system("cls");
				break;
			
			default:
				if(opt > 10){
					printf("\n\n Apenas códigos valido, favor usar o código 777 para listar os itens do mercado.\n\n");
					system("pause");
					system("cls");
				}else{
					if(!(car.numitem >= 100)){
						addCarrinho(opt, p);
					}else{
						printf("\n\n Seu Carrinho está lotado, porfavor finalize a compra.\n\n");
						system("pause");
						system("cls");
					}
				}
				break;
		}
		
	}while(opt != 0);
	system("cls");
	if(car.numitem > 0){
		finalizar(p);
	}else{
		printf("\n O mercadinho do Seu Manuel agradece a sua vinda.\n\n");
	}
	system("pause");
	system("cls");
	
}

void addCarrinho(int i, Produto * p){
	int j, k, t = 1;
	char s;
	i--;
	printf("---------------\n Produto: %s\n Código:  %d\n Valor:   %.2f\n---------------\n\n", p[i].descricao, p[i].codigo, p[i].precounit);
	
	printf(" Quer colocar esse item no carrinho?(S/N) ");
	fflush(stdin);
	scanf("%c", &s);
	
	if(s == 'S' || s == 's'){
			printf("\n Quantos? ");
		do{
			scanf("%d", &j);
			if(j>0){
				if(!(car.numitem+j > 100)){
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
					t = 1;
				}else{
					t = 2;
					printf("\n\n  Sua compra está passou de 100 itens(%d), favor não passar de 100 itens.", car.numitem+j);
					printf("\n\n  Favor digitar de novo: ");
				}
			}else{
				t = 2;
				printf("\n\n  Favor colocar um número maior que zero.");
				printf("\n\n  Favor digitar de novo: ");
			}
		}while(t != 1);
		system("pause");
	}
	system("cls");
}

void finalizar(Produto * p){
	printf("\n Nota da Compra:\n");
	
	int i,j=1;
	float total = 0;
	for(i=0;i<10;i++){
		if(car.qnt_comp[i][1] != 0){
			printf("\n %30s %3d X %.2f Reais\n", p[i].descricao, car.qnt_comp[i][1], p[i].precounit);
			j++;
		}
	}
	for(i=0;i<car.numitem;i++){
		total+= car.valProc[i].precounit;
	}
	printf("\n\n %30s: %.2f\n\n", "Total",total);
	system("pause");
	system("cls");
	printf("\n Obrigado por compra no Seu Manuel.\n\n");
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
