#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
/*#include <conio.h>*/

#ifndef _WIN32
	#include "getch.h" 
#else
	#include <conio.h>
#endif 

#define MAX_SIZE 30

typedef struct produto{
	char codigo[50];
	char descricao[30];
	char data_validade[20];
	char fornecedor[30];
	int qtd;
	double preco;
	struct produto *prox;
}produto;

typedef struct cliente{
	char nome[50];
	char cpf[14];
	char endereco[30];
	char bairro[30];
	char cidade_estado[30];
	char telefone[12];
	struct cliente *prox;
}cliente;

typedef struct venda{
	char codigo_produto[10];
	char cpf_cliente[14];
	int quantidade_venda;
	struct venda *prox;
}venda;

int menu_principal();

int submenu1();

int submenu2();

int submenu3();

int comparaString(char str1[], char str2[]);

void pausa();

void limpar();

/* PRODUTO */

void cadastrar_produto(produto **prod);

int salvarProduto(produto **prod);

void pesquisar_por_descricao(produto **prod);

produto* retornaProduto(char codProd[], produto **prod);

void pesquisar_por_fornecedor(produto **prod);

int criarProduto(char codprod[], char descricao[], char fornecedor[], char data_validade[], int quantidade, int preco,produto **prod);

int recuperaProduto(produto **prod);

void altera_quantidade_produto(produto **prod);

/* CLIENTE */

void cadastra_cliente(cliente **client);

void listar_cliente(cliente **client);

void listar_cliente_nome(cliente **client);

int salvarCliente(cliente **lst);

int criarCliente(char nome[], char cpf[], char endereco[], char bairro[], char cidade[], char telefone[], cliente **client);

int checarCpf(char cpf[], cliente **client);

int recuperaCliente(cliente **client);


/* VENDA */

void cadastra_venda(cliente **client,produto **prod, venda **compras);

void buscar_vendas_por_cpf(venda **compras, produto **prod);

char* retorna_nome_cliente(char *cpf_cliente,cliente **client);

void buscar_vendas_por_codProd(venda **compras, cliente **client);

int salvarVenda(venda **compras);

int criarVenda(char codigo_produto[], char cpf_cliente[], int qtd, venda **lst_compras);

int recuperaVenda(venda **compras);