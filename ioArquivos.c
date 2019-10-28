#include "menu.h"

int salvarCliente(cliente **client){

    cliente *lst;
    FILE *ptArq;

    lst = *client;
    
    ptArq = fopen("DadosClientes.csv", "w");

    if(ptArq == NULL){
        printf("Erro ao salvar Clientes");
        pausa();
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
    FILE *ptArq;

    lst = *prod;
    
    ptArq = fopen("DadosProdutos.csv", "w");

    if(ptArq == NULL){
        printf("Erro ao salvar Produtos");
        pausa();
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

int salvarVenda(venda **compras){

    venda *lst;
    FILE *ptArq;

    lst = *compras;

    ptArq = fopen("DadosVendas.csv", "w");

    if(ptArq == NULL){
        printf("erro ao salvar venda");
        pausa();
        return 0;
    }
    while(lst != NULL){

        fprintf(ptArq, "%s;", lst->codigo_produto);
        fprintf(ptArq, "%s;", lst->cpf_cliente);
        fprintf(ptArq, "%d;\n", lst->quantidade_venda);

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

            criarCliente(nome,cpf,endereco,bairro,cidade_estado,telefone, client);
        }

        fclose(ptArq);
        return 1;
    }
}


int recuperaProduto(produto **prod){

    FILE *ptArq;
    ptArq = fopen("DadosProdutos.csv", "r");

    if(ptArq == NULL){
        return 0;
    }else{

        char linha[180];

        char *codigo;
        char *descricao;
        char *data_validade;
        char *fornecedor;
        char *qtd_str;
        char *preco_str;
        int qtd;
        double preco;


        while(fgets(linha,180,ptArq) != NULL){
            codigo = strtok(linha,";");
            descricao = strtok(NULL,";");
            fornecedor = strtok(NULL,";");
            data_validade = strtok(NULL,";");
            qtd_str = strtok(NULL,";");
            preco_str = strtok(NULL,";");

            qtd = atoi(qtd_str);
            preco = atof(preco_str);

            printf(" %d",criarProduto(codigo,descricao, data_validade, fornecedor,qtd,preco, prod));
        }

        fclose(ptArq);
        return 1;
    }
}

int recuperaVenda(venda **lst_vendas){
    FILE *ptArq;

    ptArq= fopen("DadosVendas.csv","r");

    if (ptArq == NULL){
        return 0;
    }else{


        char linha[40];

        char *codigo_produto;
        char *cpf_cliente;
        char *qtd_str;

        int qtd;

        while(fgets(linha,180,ptArq) != NULL){
            codigo_produto = strtok(linha,";");
            cpf_cliente = strtok(NULL,";");
            qtd_str = strtok(NULL,";");

            qtd = atoi(qtd_str);

            criarVenda(codigo_produto,cpf_cliente,qtd,lst_vendas);
        }

        fclose(ptArq);
        return 1;
    }
}


