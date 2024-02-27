#include <stdio.h>
#include <stdlib.h>
#define MAX_CLIENTES 100      //Diretiva da macro 

    struct Cliente {
        int id;               //Identificador
        char nome[50];
        char email[50];
    };
    
    // Protótipos de funções
    void cadastrarCliente(struct Cliente *clientes, int *count);
    void exibirTodos(struct Cliente *clientes, int count);
    void exibirPrimeiros(struct Cliente *clientes, int count);
    void exibirUltimos(struct Cliente *clientes, int count);
    int buscarCliente(struct Cliente *clientes, int count, int idBuscado);
    void salvarClientes(struct Cliente *clientes, int count);
    void carregarClientes(struct Cliente *clientes, int *count);

    int main() {
        struct Cliente clientes[MAX_CLIENTES];      //Inicialização da estrutura
        int count = 0;                          //Número atual de clientes
        char continuar = 'S';

        carregarClientes(clientes, &count);

        do {
            printf("\n\tMENU\n\n1. Cadastrar\n2. Consultar\n3. Consultar cliente pelo id\n4. Atualizar o cadastro de um cliente\n5. Excluir\n");
            int opcao;
            printf("\nEscolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    cadastrarCliente(clientes, &count);
                    salvarClientes(clientes, count);
                    break;

                case 2:
                    printf("\nModo de consulta:\n");
                    printf("a. 5 primeiros registros\nb. 5 ultimos registros\nc. Todos os registros\n\nEscolha uma opcao: ");
                    char opcaoConsulta;
                    scanf(" %c", &opcaoConsulta);
                   
                    switch (opcaoConsulta)
                    {
                    case 'a':
                        printf("\n");
                        exibirPrimeiros(clientes, count);
                        break;
                       
                    case 'b':
                        printf("\n");
                        exibirUltimos(clientes, count);
                        break;

                    case 'c':
                        printf("\n");
                        exibirTodos(clientes, count);
                        break;
                   
                    default:
                        printf("Opcao invalida!\n");
                        break;
                    }
                   
                    break;
                    
                case 3:
                    printf("\nBusca de cliente pelo id\n");
                    int idBuscado;
                    printf("Insira o id a ser buscado: ");
                    scanf("%d", &idBuscado);
                    printf("\n");

                    int index = buscarCliente(clientes, count, idBuscado);
                    if (index != -1) {
                        printf("%d\t%s\t%s\n", clientes[index].id, clientes[index].nome, clientes[index].email);
                    } else {
                        printf("\nCliente nao encontrado.\n");
                    }
                    printf("\n");
                    break;

                case 4:
                    printf("\nAtualizar o cadastro de um cliente\n");
                    printf("Insira o id do cliente a ser atualizado: ");
                    scanf("%d", &idBuscado);

                    int idxAtualizar = buscarCliente(clientes, count, idBuscado);
                    if (idxAtualizar != -1) {
                        printf("Insira o novo nome: ");
                        scanf("%s", clientes[idxAtualizar].nome);

                        printf("Insira o novo email: ");
                        scanf("%s", clientes[idxAtualizar].email);

                        salvarClientes(clientes, count);
                        printf("\nCadastro atualizado!\n");
                    } else {
                        printf("\nCliente não encontrado.\n");
                    }
                    break;

                case 5:
                    printf("\nExcluir cliente\n");
                    printf("Insira o id do cliente a ser removido: ");
                    scanf("%d", &idBuscado);

                    int idxExcluir = buscarCliente(clientes, count, idBuscado);
                    if (idxExcluir != -1) {
                        for (int i = idxExcluir; i < count - 1; i++) {
                            clientes[i] = clientes[i + 1];
                        }
                        count--;
                        salvarClientes(clientes, count);
                        printf("\nCliente removido!\n");
                    } else {
                        printf("\nCliente nao encontrado.\n");
                    }
                    break;

                default:
                    printf("Opcao invalida!\n");
            }

            printf("\nDeseja continuar? (S/N): ");
            scanf(" %c", &continuar);

        } while (continuar == 'S' || continuar == 's');

        return 0;
    }
    
    void cadastrarCliente(struct Cliente *clientes, int *count) {
        char opcaoCadastro;
        printf("\nPreferencia do registro:\n");
        printf("\n\ta. Inicio\n\tb. Final\n\nEscolha uma opcao: ");
        scanf(" %c",&opcaoCadastro);
       
        switch (opcaoCadastro) {
            case 'a':
                for (int i = *count; i > 0; i--) {
                clientes[i] = clientes[i - 1];
                }
                printf("\nInsira o id: ");
                scanf("%d", &clientes[0].id);
   
                printf("Insira o nome: ");
                scanf(" %s", clientes[0].nome);
   
                printf("Insira o email: ");
                scanf(" %s", clientes[0].email);
                (*count)++;
                printf("\nCadastro feito!\n");
                break;
               
            case 'b':
                printf("\nInsira o id: ");
                scanf("%d", &clientes[*count].id);
   
                printf("Insira o nome: ");
                scanf(" %s", clientes[*count].nome);
   
                printf("Insira o email: ");
                scanf(" %s", clientes[*count].email);
                (*count)++;
                printf("\nCadastro feito!\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }

    void exibirTodos(struct Cliente *clientes, int count) {
        printf("ID\tNome\tEmail\n");
        for (int i = 0; i < count; i++) {
            printf("%d\t%s\t%s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
        }
    }

    void exibirPrimeiros(struct Cliente *clientes, int count) {
        printf("ID\tNome\tEmail\n");
        for (int i = 0; i < 5 && i < count; i++) {
            printf("%d\t%s\t%s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
        }

    }

    void exibirUltimos(struct Cliente *clientes, int count) {
        printf("ID\tNome\tEmail\n");
        if (count <= 5) {
            for (int i = 0; i < count; i++) {
                printf("%d\t%s\t%s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
            }
        }
        else {
            for (int i = count - 5; i < count && i >= 0; i++) {
                printf("%d\t%s\t%s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
            }
        }
    }

    int buscarCliente(struct Cliente *clientes, int count, int idBuscado) {
        for (int i = 0; i < count; i++) {
            if (clientes[i].id == idBuscado) {
                return i;
            }
        }
        return -1; // Retorna -1 se não encontrar o cliente com o ID fornecido
    }

    void salvarClientes(struct Cliente *clientes, int count) {
        FILE *arquivo = fopen("clientes.txt", "w");       //Modo escrita
        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }

        for (int i = 0; i < count; i++) {
            fprintf(arquivo, "%d %s %s\n", clientes[i].id, clientes[i].nome, clientes[i].email);
        }

        fclose(arquivo);
    }

    void carregarClientes(struct Cliente *clientes, int *count) {   
        FILE *arquivo = fopen("clientes.txt", "r");       //Modo leitura
        if (arquivo == NULL) {
            printf("Arquivo de clientes não encontrado. Criando um novo.\n");
            return;
        }

        while (fscanf(arquivo, "%d %s %s", &clientes[*count].id, clientes[*count].nome, clientes[*count].email) == 3) {
            (*count)++;
            if (*count >= MAX_CLIENTES) {                 //Controle de limite
                printf("Limite de clientes atingido. Nao eh possivel carregar mais clientes.\n");
                break;
            }
        }

        fclose(arquivo);
    }
