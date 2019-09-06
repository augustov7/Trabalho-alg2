#include <stdio.h>
#include <stdlib.h>

/*
#ifndef _WIN32
	#include "getch.h"  Biblioteca para linux 
#else
	#include <conio.h>  Biblioteca para windows 
#endif  */

#include <conio.h> 

int menu_principal(){
	char op;
	system("cls");
	printf("\n1 PRODUTO\n2 CLIENTE\n3 COMPRA \nS SAIR \n\nOPCAO: ");
	op = getch();
	return op;
}

int submenu1(){
	char op;
	system("cls");
	printf("\n1 PESQUISAR POR DESCRICAO \n2 PESQUISAR POR FORNECEDOR \n3 CADASTRAR PRODUTO \n0 Voltar \n\nOPCAO: ");
	op = getch();
	return op;
}

int submenu2(){
	char op;
	system("cls");
	printf("\n1 PESQUISAR POR NOME \n2 CADASTRAR CLIENTE \n0 Voltar \n\nOPCAO: ");
	op = getch();
	return op;
}

int submenu3(){
	char op;
	system("cls");
	printf("\n1 PESQUISAR COMPRA PELO CPF DO CLIENTE \n2 PESQUISAR COMPRA PELO CODIGO DO PRODUTO \n3 REALIZAR COMPRA \n0 Voltar \n\nOPCAO: ");
	op = getch();
	return op;
}
