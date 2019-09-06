#include "menu.h"

void cadastra_venda(cliente **client, produto **prod, venda **compras){

	puts("-----\n");
	char cpf[MAX_SIZE];
	char codprod[MAX_SIZE];
	int quantidade;

	produto *p;
	venda *compra = (venda *) malloc(sizeof(venda));

	char codigo_produto[50];
	char cpf_cliente[14];
	
	
	puts("---------------REALIZAR COMPRA-----------------\n");
	printf("\nInforme o CPF:");
	scanf(" %[^\n]",cpf);

	printf("\nInforme o CODIGO do produto:");
	scanf(" %[^\n]",codprod);

	printf("\nInforme a QUANTIDADE desejada:");
	scanf(" %d",&quantidade);

	if(checarCpf(cpf, client) == 1){
		if((p = retornaProduto(codprod, prod)) != NULL){

			if(p->qtd >= quantidade){

				strcpy(compra->codigo_produto,codprod);
				strcpy(compra->cpf_cliente,cpf);
				compra->quantidade_venda = quantidade;
				p->qtd -= quantidade;

				puts("-----------COMPRA EFETUADA COM SUCESSO-----------\n");
				printf("Produto: %s \n", p->descricao);
				printf("Valor: %.2f \n", quantidade * p->preco);

			}else{
				printf("QUANTIDADE NÃO DISPONIVEL!!!");
				system("pause");
			}
		}else{
			printf("PRODUTO NÃO ENCONTRADO!!!");
			system("pause");
		}
	}else{
		printf("CPF NÃO ENCONTRADO!!!");
		system("pause");
	}
}

void buscar_vendas_por_cpf(venda **compras, produto **prod){

	char cpf_venda[MAX_SIZE];
	venda *lst = *compras;

	printf("\nInforme o CPF da venda:");
	scanf(" %[^\n]",cpf_venda);

	puts("----------------------------------------");
	puts("-------------VENDAS POR CPF-------------");
	puts("----------------------------------------\n");

	if (lst == NULL){
		return 0;
	}else{

		while(lst != NULL){

			if (comparaString(cpf_venda, lst->cpf_cliente) == 1)
			{
				produto *p = (produto *) malloc(sizeof(produto));

				p = retornaProduto(lst->codigo_produto, prod)

				printf("Código do Produto: %s\n", lst->codigo_produto);
				printf("Descrição do Produto: %s\n", p->descricao);
				printf("Quantidade Vendida: %s\n", lst->quantidade_venda);
				puts("------------------------------------");
			}

			lst = lst->prox;
		}
	}	

	system("pause");
}

void buscar_vendas_por_codProd(venda **compras, cliente **client){

	char codProd_venda[MAX_SIZE];
	venda *lst = *compras;

	printf("\nInforme o CÓDIGO DO PRODUTO na venda:");
	scanf(" %[^\n]",codProd_venda);

	puts("------------------------------------------");
	puts("------------VENDAS POR PRODUTO------------");
	puts("------------------------------------------\n");

	if (lst == NULL){
		return 0;
	}else{

		while(lst != NULL){

			if (comparaString(codProd_venda, lst->codigo_produto) == 1)
			{
				cliente *p = (cliente *) malloc(sizeof(cliente));

				p = retornaProduto(lst->codigo_produto, prod)

				printf("Código do Produto: %s\n", lst->codigo_produto);
				printf("Descrição do Produto: %s\n", retorna_nome_cliente(lst->cpf_cliente, client));
				printf("Quantidade Vendida: %s\n", lst->quantidade_venda);
				puts("--------------------------------------");
			}

			lst = lst->prox;
		}
	}	

	system("pause");
}