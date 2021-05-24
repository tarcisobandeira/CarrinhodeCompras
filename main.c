#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "produto.h"
#include "carrinho.h"

void main(){
	setlocale(LC_ALL, "Portuguese");
	int opt;
	Produto prod[10];
	addProdutos(prod);
	
	do{
		printf("\n Loginha do Manuel\n");
		printf(" -----------------\n");
		printf(" 1 - Comprar\n");
		printf(" 2 - Ver a Lista dos Produtos\n");
		printf(" 0 - Sair\n");
		printf(" -----------------\n");
		printf("Escolha: ");
		scanf("%d", &opt);
		
		fflush(stdin);
		
		switch(opt){
			case 1:
				system("cls");
				menuCarrinho(prod);
				break;
			case 2:
				system("cls");
				ListarProd(prod);
				system("pause");
				system("cls");
				break;
			case 0:
				break;
			default:
					printf("\n Instruções:\n\tSó pode usar números de 0 a 2.\n\n");
					system("pause");
					system("cls");
		}
	}while(opt != 0);
	printf("Desligando...");
}
