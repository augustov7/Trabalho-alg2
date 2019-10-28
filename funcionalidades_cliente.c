#include "menu.h"

void cadastra_cliente(cliente **client){

	char nome[MAX_SIZE];
	char cpf[MAX_SIZE];
	char endereco[MAX_SIZE];
	char bairro[MAX_SIZE];
	char cidade[MAX_SIZE];
	char telefone[MAX_SIZE];

	printf("\nInforme o NOME:");
	scanf(" %[^\n]",nome);
	printf("\nInforme o CPF:");
	scanf(" %[^\n]",cpf);
	printf("\nInforme o ENDERECO:");
	scanf(" %[^\n]",endereco);
	printf("\nInforme o BAIRRO:");
	scanf(" %[^\n]",bairro);
	printf("\nInforme a CIDADE/ESTADO:");
	scanf(" %[^\n]",cidade);
	printf("\nInforme o TELEFONE de Contato:");
	scanf(" %[^\n]", telefone);


	if (retorna_nome_cliente(cpf,client) != NULL )
	{
		puts("CLIENTE JA CADASTRADO!!!");
		pausa();
	}else{
		criarCliente(nome,cpf,endereco,bairro,cidade,telefone,client);	
	}
	
	
}

int criarCliente(char nome[], char cpf[], char endereco[], char bairro[], char cidade[], char telefone[], cliente **client){

	cliente *p = (cliente *) malloc(sizeof(cliente));
	cliente *lst;

	strcpy(p->nome,nome);
	strcpy(p->cpf,cpf);
	strcpy(p->endereco,endereco);
	strcpy(p->bairro,bairro);
	strcpy(p->cidade_estado,cidade);
	strcpy(p->telefone,telefone);

	p->prox = NULL;

	lst = *client;

	if (lst == NULL){
		*client = p;
		return 0;
	}else{
		p->prox = *client;
		*client = p;
		return 1;
	}

	return -1;
}

void listar_cliente_nome(cliente **client){

	char nome_pesquisado[MAX_SIZE];

	cliente *lst = *client;

	printf("\nInforme o NOME:");
	scanf(" %[^\n]",nome_pesquisado);

	limpar();

	puts("----------------------------------------");
	puts("---------------CLIENTES-----------------");
	puts("----------------------------------------\n");

	
	while(lst != NULL){
		if (comparaString(nome_pesquisado,lst->nome)== 0){
			printf("Nome: %s\n", lst->nome);
			printf("CPF: %s\n", lst->cpf);
			printf("ENDEREcO: %s\n", lst->endereco);
			printf("BAIRRO: %s\n", lst->bairro);
			printf("CIDADE/ESTADO: %s\n", lst->cidade_estado);
			printf("TELEFONE: %s\n", lst->telefone);
			puts("\n------------------------------------");
		}

		lst = lst->prox;
	}
	
	
	pausa();
}

int checarCpf(char cpf[], cliente **client){

	cliente *lst = *client;

	while(lst != NULL){
		if (comparaString(cpf,lst->cpf) == 1){
			return 1;
		}				
		lst = lst->prox;
	}
	return 0;
}

void listar_cliente(cliente **client){

	cliente *lst = *client;

	if (lst == NULL){
		puts("nulo");
		pausa();
	}
	while(lst != NULL){

		printf("Nome: %s\n", lst->nome);
		printf("descricao: %s\n", lst->cpf);
		puts("------------------------------------");
		lst = lst->prox;
		pausa();
	}
}

char* retorna_nome_cliente(char *cpf, cliente **client){

	cliente *lst;
	lst = *client;

	while(lst != NULL){

		if(comparaString(cpf, lst->cpf) == 1){
			
			return lst->nome;
		}
		
		lst = lst->prox;
	}
	
	return NULL;
}