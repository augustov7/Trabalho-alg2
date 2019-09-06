#include "menu.h"

int comparaString(char str1[50], char str2[50]){
	int i = 0,j = 0,aux = 0;

	while(str1[i] != '\0' && str2[j] != '\0'){
		if(str1[i] == str2[j]){
			i++;
			j++;
		}else{
			aux++;
			i = 0;
			j = aux;
		}
	}
    if(i == j && str1[i] == '\0' && str2[j] == '\0') return 1;/* RETORNA 1 CASO STR1 E STR2 SEJA IGUAIS */
    if(str1[i] == '\0') return 0;/* RETORNA 0 CASO STR2 CONTENHA STR1 */
    return -1;/* RETORNA -1 CASO STR1 E STR2 SEJA TOTALMENTE DIFERENTE*/
}


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
	printf("\nInforme a PREÇO do produto:");
	scanf(" %lf", &preco);
 /*
	produto *p = (produto *) malloc(sizeof(produto));

	strcpy(p->codigo,codprod);
	strcpy(p->descricao,descricao);
	strcpy(p->fornecedor,fornecedor);
	strcpy(p->data_validade,data_validade);
	p->qtd = qtd;
	p->preco = preco;
	p->prox = NULL;

	 Inserindo o Produto na lista 
	system("pause");
	if(*prod == NULL){
		*prod = p;
	}else{

		produto *lst;
		Colocar FOR dentro de outra função
		for(lst = *prod;lst->prox != NULL; lst = lst->prox){

			if(comparaString(lst->codigo, p->codigo) == 1){
				puts("Código já cadastrado !!!");
				break;
			}
			if(lst->prox != NULL){
				lst = lst->prox;
			}else{
				lst->prox = p;	
				break;		
			}		
		}
	} */
}

criarProduto(produto **prod){

	produto *p = (produto *) malloc(sizeof(produto));

	strcpy(p->codigo,codprod);
	strcpy(p->descricao,descricao);
	strcpy(p->fornecedor,fornecedor);
	strcpy(p->data_validade,data_validade);
	p->qtd = qtd;
	p->preco = preco;
	p->prox = NULL;

	/* Inserindo o Produto na lista */
	system("pause");
	if(*prod == NULL){
		*prod = p;
	}else{

		produto *lst;
		/*Colocar FOR dentro de outra função*/
		for(lst = *prod;lst->prox != NULL; lst = lst->prox){

			if(comparaString(lst->codigo, p->codigo) == 1){
				puts("Código já cadastrado !!!");
				break;
			}
			if(lst->prox != NULL){
				lst = lst->prox;
			}else{
				lst->prox = p;	
				break;		
			}		
		}
	}
}

void listar(produto **prod){

	produto *lst = *prod;

	if (lst == NULL){
		puts("nulo");
	}

	while(lst != NULL){

		printf("Nome: %s\n", lst->codigo);
		printf("descricao: %s\n", lst->descricao);
		printf("validade: %s\n", lst->data_validade);
		printf("fornecedor: %s\n", lst->fornecedor);
		printf("qtd: %d\n", lst->qtd);
		printf("valor: %.2f\n", lst->preco);
		puts("------------------------------------");
		lst = lst->prox;
	}

	system("pause");
}

void pesquisar_por_descricao(produto **prod){

	char descricao_produto[MAX_SIZE];
	produto *lst = *prod;

	printf("\nInforme a DESCRIÇÃO do produto:");
	scanf(" %[^\n]",descricao_produto);

	puts("----------------------------------------");
	puts("---------------PRODUTOS-----------------");
	puts("----------------------------------------\n");

	if (lst == NULL){
		return 0;
	}else{

		while(lst != NULL){

			if (comparaString(descricao_produto, lst->descricao) != -1)
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
	}	

	system("pause");
}

void pesquisar_por_fornecedor(produto **prod){

	char fornecedor_produto[MAX_SIZE];
	produto *lst = *prod;

	printf("\nInforme o FORNECEDOR do produto:");
	scanf(" %[^\n]",fornecedor_produto);

	puts("----------------------------------------");
	puts("--------PRODUTOS POR FORNECEDOR---------");
	puts("----------------------------------------\n");

	if (lst == NULL){
		return 0;
	}else{

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
	}	

	system("pause");
}

produto* retornaProduto(char codProd[], produto **prod){

	produto *lst = *prod;

	while(lst != NULL){

		if(comparaString(codProd, lst->codigo) == 1){
			//checar ponteiro
			return lst;
		}
		
		lst = lst->prox;
	}
	
	return NULL;
}