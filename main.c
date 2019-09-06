#include "menu.h"

/* 
CD C:\Users\Augusto\Desktop\Trabalho alg2

gcc *.c -o trab.exe -ansi -pedantic -Wall 

main.c
*/

int main(){
	
	char op, subop;

	produto *prod;

	cliente *client;

	venda *compras;

	prod= NULL;
	client = NULL;
	compras = NULL;


	recuperaCliente(&client);


	op = menu_principal();

	/* Enquanto não pressionar 'ESC', 'S' ou 's' */
	while (op != 27 && op != 'S' && op != 's'){
		switch(op){
			case '1':
			subop = submenu1();
				/* Enquanto n�o pressionar '0' */
			while (subop != '0'){
				switch(subop){

						/* PESQUISAR PRODUTO POR DESCRIÇÃO */
					case '1':

							//listar(&prod);
					pesquisar_por_descricao(&prod);

					break;

						/* PESQUISAR PRODUTO POR FORNECEDOR */
					case '2': 

					pesquisar_por_fornecedor(&prod);

					break;

						/* CADASTRAR PRODUTO */
					case '3':

					cadastrar_produto(&prod);

					break;
					default:
					break;
				}
				subop = submenu1();
			}
			break;

			case '2':
			subop = submenu2();

				/* Enquanto não pressionar '0' */

			while (subop != '0'){
				switch(subop){

					/* PESQUISAR CLIENTE POR NOME */
					case '1':

					listar_cliente_nome(&client);

					break;

					/* CADASTRAR CLIENTE */
					case '2':		

					cadastra_cliente(&client);

					break;

					default:
					break;
				}
				subop = submenu2();
			}
			break;

			case '3':
			subop = submenu3();
				/* Enquanto n�o pressionar '0' */
			while (subop != '0'){
				switch(subop){

					/* PESQUISAR COMPRAS PELO CPF DO CLIENTE */
					case '1':
					buscar_vendas_por_cpf(&compras, &prod);
					break;

					/* PESQUISAR COMPRAS PELO CODIGO DO PRODUTO */
					case '2':
					buscar_vendas_por_codProd(&compras, &client);
					break;

					/* REALIZAR COMPRA */
					case '3':

					cadastra_venda(&client, &prod, &compras);
					system("pause");

					break;
					default:
					break;
				}
				subop = submenu3();
			}
			break;

			default:
			break;
		}
		op = menu_principal();
	}

	salvarCliente(&client);
	salvarProduto(&prod);
	printf("\n");

	return 0;
}
