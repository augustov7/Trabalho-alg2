#include "menu.h"

/*	CADASTROS	*/
void cadastrar_produto(produto **prod){

	char codprod[MAX_SIZE];
	char descricao[MAX_SIZE];
	char fornecedor[MAX_SIZE];
	char data_validade[MAX_SIZE];
	int qtd;
	double preco;

	printf("\nInforme o CODIGO do produto:");
	scanf(" %[^\n]",codprod);
	printf("\nInforme a DESCRICAO do produto:");
	scanf(" %[^\n]",descricao);
	printf("\nInforme a FORNECEDOR do produto:");
	scanf(" %[^\n]",fornecedor);
	printf("\nInforme a DATA DE VALIDADE do produto:");
	scanf(" %[^\n]",data_validade);
	printf("\nInforme a QTD do produto:");
	scanf(" %d", &qtd);
	printf("\nInforme a PRECO do produto:");
	scanf(" %lf", &preco);

	criarProduto(codprod, descricao, fornecedor, data_validade, qtd, preco,prod);

}

int criarProduto(char codprod[], char descricao[], char fornecedor[], char data_validade[], int quantidade, int preco,produto **prod){

	produto *p = (produto *) malloc(sizeof(produto));

	strcpy(p->codigo,codprod);
	strcpy(p->descricao,descricao);
	strcpy(p->fornecedor,fornecedor);
	strcpy(p->data_validade,data_validade);
	p->qtd = quantidade;
	p->preco = preco;
	p->prox = NULL;

	/* Inserindo o Produto na lista */
	if(*prod == NULL){
		*prod = p;
		return 0;
	}else{

		produto *lst;
		lst = *prod;
		while(lst != NULL){

			if(comparaString(lst->codigo,codprod) == 1){

				puts("Codigo ja cadastrado !!!");
				pausa();
				return -1;
			}

			lst = lst->prox;

		}

		p->prox = *prod;
		*prod = p;
		return 1;
	}
	puts("Criado");
	pausa();
}


void pesquisar_por_descricao(produto **prod){

	char descricao_produto[MAX_SIZE];
	produto *lst = *prod;

	printf("\nInforme a DESCRICAO do produto:");
	scanf(" %[^\n]",descricao_produto);

	limpar();

	puts("----------------------------------------");
	puts("---------------PRODUTOS-----------------");
	puts("----------------------------------------\n");

	if (lst == NULL){
		
	}else{

		while(lst != NULL){

			if (comparaString(descricao_produto, lst->descricao) != -1)
			{
				printf("Codigo: %s\n", lst->codigo);
				printf("descricao: %s\n", lst->descricao);
				printf("validade: %s\n", lst->data_validade);
				printf("fornecedor: %s\n", lst->fornecedor);
				printf("qtd: %d\n", lst->qtd);
				printf("valor: %.2f\n", lst->preco);
				puts("------------------------------------");
			}

			lst = lst->prox;
		}
	}	

	pausa();
}

void pesquisar_por_fornecedor(produto **prod){

	char fornecedor_produto[MAX_SIZE];
	produto *lst = *prod;

	printf("\nInforme o FORNECEDOR do produto:");
	scanf(" %[^\n]",fornecedor_produto);

	limpar();

	puts("----------------------------------------");
	puts("--------PRODUTOS POR FORNECEDOR---------");
	puts("----------------------------------------\n");

	while(lst != NULL){

		if (comparaString(fornecedor_produto, lst->fornecedor) != -1)
		{
			printf("Nome: %s\n", lst->codigo);
			printf("descricao: %s\n", lst->descricao);
			printf("validade: %s\n", lst->data_validade);
			printf("fornecedor: %s\n", lst->fornecedor);
			printf("qtd: %d\n", lst->qtd);
			printf("valor: %.2f\n", lst->preco);
			puts("------------------------------------");
		}

		lst = lst->prox;
	}

	pausa();
}

produto* retornaProduto(char codProd[], produto **prod){

	produto *lst = *prod;

	while(lst != NULL){

		if(comparaString(codProd, lst->codigo) == 1){

			return lst;
		}
		
		lst = lst->prox;
	}
	
	return NULL;
}

void altera_quantidade_produto(produto **prod){
	
	char codigo_produto[MAX_SIZE];
	int qtd;

	produto *p = (produto *) malloc(sizeof(produto));

	printf("\nInforme o CODIGO do produto: ");
	scanf(" %s", codigo_produto);

	p = retornaProduto( codigo_produto,prod);
	if (p == NULL)
	{
		printf("\n Produto invalido!!!");
	}else{
		printf("\nInforme a quantidade a ser adicionada: ");
		scanf(" %d", &qtd);

		if (qtd > 0)
		{
			p->qtd += qtd;
		}else{
			printf("\nquantidade invalida!!! \n");
			pausa();
		}
	}
}