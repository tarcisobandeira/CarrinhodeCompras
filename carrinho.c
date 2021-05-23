#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "carrinho.h"

struct carrinho{
	int numitem;
	struct Produto * prod_car;
	int qtd;
	struct Produto * precototal;
};
