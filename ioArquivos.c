#include "menu.h"

int salvarCliente(cliente **client){

    cliente *lst;
    lst = *client;

    FILE *ptArq;
    ptArq = fopen("DadosClientes.csv", "w");

    if(ptArq == NULL){
        printf("erro");
        return 0;
    }
    while(lst != NULL){

        fprintf(ptArq, "%s;", lst->nome);
        fprintf(ptArq, "%s;", lst->cpf);
        fprintf(ptArq, "%s;", lst->endereco);
        fprintf(ptArq, "%s;", lst->bairro);        
        fprintf(ptArq, "%s;", lst->cidade_estado);
        fprintf(ptArq, "%s;\n", lst->telefone);

        lst = lst->prox;
    }
    fclose(ptArq);
    return 1;
}

int salvarProduto(produto **prod){

    produto *lst;
    lst = *prod;

    FILE *ptArq;
    ptArq = fopen("DadosProdutos.csv", "w");

    if(ptArq == NULL){
        printf("erro");
        return 0;
    }
    while(lst != NULL){

        fprintf(ptArq, "%s;", lst->codigo);
        fprintf(ptArq, "%s;", lst->descricao);
        fprintf(ptArq, "%s;", lst->data_validade);
        fprintf(ptArq, "%s;", lst->fornecedor);        
        fprintf(ptArq, "%d;", lst->qtd);
        fprintf(ptArq, "%lf;\n", lst->preco);

        lst = lst->prox;
    }
    fclose(ptArq);
    return 1;
}


int recuperaCliente(cliente **client){

    FILE *ptArq;
    ptArq = fopen("DadosClientes.csv", "r");

    if(ptArq == NULL){
        return 0;
    }else{

        char linha[180];

        char *nome;
        char *cpf;
        char *endereco;
        char *bairro;
        char *cidade_estado;
        char *telefone;

        while(fgets(linha,180,ptArq) != NULL){
            nome = strtok(linha,";");
            cpf = strtok(NULL,";");
            endereco = strtok(NULL,";");
            bairro = strtok(NULL,";");
            cidade_estado = strtok(NULL,";");
            telefone = strtok(NULL,";");

            printf(" leitura: %d", criarCliente(nome,cpf,endereco,bairro,cidade_estado,telefone, client));
            system("pause");
        }

        fclose(ptArq);
        return 1;
    }
}