#include "menu.h"

void cadastra_venda(cliente **client, produto **prod, venda **lst_vendas){

	char cpf[MAX_SIZE];
	char codprod[MAX_SIZE];
	int quantidade;

	produto *p;

	limpar();

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

				criarVenda(codprod,cpf,quantidade,lst_vendas);

				p->qtd -= quantidade;

				puts("-----------COMPRA EFETUADA COM SUCESSO-----------\n");
				printf("Produto: %s \n", p->descricao);
				printf("Valor: %.2f \n", quantidade * p->preco);

			}else{
				printf("QUANTIDADE NAO DISPONIVEL!!!\n");
			}
		}else{
			printf("PRODUTO NAO ENCONTRADO!!!\n");
		}
	}else{
		printf("CPF NAO ENCONTRADO!!!\n");
	}

	pausa();
}

int criarVenda(char codprod[], char cpf[], int qtd, venda **lst_compras){

	venda *compra = (venda *) malloc(sizeof(venda));

	strcpy(compra->codigo_produto,codprod);
	strcpy(compra->cpf_cliente,cpf);
	compra->quantidade_venda = qtd;

	if (lst_compras == NULL){
		*lst_compras = compra;

		return 0;
	}else{
		compra->prox = *lst_compras;
		*lst_compras = compra;

		return 1;
	}

}

void buscar_vendas_por_cpf(venda **compras, produto **prod){

	char cpf_venda[MAX_SIZE];
	venda *lst = *compras;

	printf("\nInforme o CPF da venda:");
	scanf(" %[^\n]",cpf_venda);

	limpar();

	puts("----------------------------------------");
	puts("-------------VENDAS POR CPF-------------");
	puts("----------------------------------------\n");

	if (lst == NULL){

	}else{

		while(lst != NULL){

			/* Percorre todos os registros da lista mostrando apenas os que tenha o CPF informado */
			
			if (comparaString(cpf_venda, lst->cpf_cliente) == 1)
			{
				produto *p = (produto *) malloc(sizeof(produto));

				p = retornaProduto(lst->codigo_produto, prod);

				printf("Codigo do Produto: %s\n", lst->codigo_produto);
				printf("Descricao do Produto: %s\n", p->descricao);
				printf("Quantidade Vendida: %d\n", lst->quantidade_venda);
				puts("----------------------------------------");
			}

			lst = lst->prox;
		}
	}	

	pausa();
}

void buscar_vendas_por_codProd(venda **compras, cliente **client){

	char codProd_venda[MAX_SIZE];
	venda *lst = *compras;

	printf("\nInforme o CODIGO DO PRODUTO na venda:");
	scanf(" %[^\n]",codProd_venda);

	limpar();

	puts("------------------------------------------");
	puts("------------VENDAS POR PRODUTO------------");
	puts("------------------------------------------\n");


	while(lst != NULL){

		if (comparaString(codProd_venda, lst->codigo_produto) == 1)
		{
			printf("Codigo do Produto: %s\n", lst->codigo_produto);
			printf("Vendido para: %s\n", retorna_nome_cliente(lst->cpf_cliente, client));
			printf("CPF: %s\n", lst->cpf_cliente);
			puts("--------------------------------------");
		}

		lst = lst->prox;
	}	

	pausa();
}