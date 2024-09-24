#include <stdio.h>
#include <stdlib.h>

#include "lista.h"
#include "lista.c"

int main() {
    inicializar(); // Inicializando a lista encadeada

    int opcao = 0; // Variável para armazenar a opção do usuário
    char cpf[MAX_LENGTH]; // Variável para armazenar o CPF do usuário

    // Verifica a condição no início do loop principal
    while (opcao != 7) {
    printf("\nMenu:\n");
    printf("1. Adicionar\n");
    printf("2. Excluir\n");
    printf("3. Alterar\n");
    printf("4. Imprimir\n");
    printf("5. Imprimir todos\n");
    printf("6. Ordenar\n");
    printf("7. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    printf("\n");
    
    switch (opcao) {
        case 1:
            printf("Digite o CPF: ");
            scanf("%s", cpf);
            
            Pessoa pessoa; // Variável para armazenar os dados da pessoa
            strcpy(pessoa.cpf, cpf); // Copiando o CPF fornecido para a estrutura pessoa

            // Verificando se o CPF já está cadastrado na lista
            if (buscar(cpf) == -1) {  // -1 é utilizado para representar uma condição de "não encontrado"

                printf("Digite o nome: ");
                limparBuffer();
                fgets(pessoa.nome, MAX_LENGTH, stdin);
                pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; // Removendo o caractere de nova linha

                printf("Digite o endereco: ");
                limparBuffer();
                fgets(pessoa.endereco, MAX_LENGTH, stdin);
                pessoa.endereco[strcspn(pessoa.endereco, "\n")] = '\0'; // Removendo o caractere de nova linha

                printf("Digite o telefone: ");
                limparBuffer();
                fgets(pessoa.telefone, MAX_LENGTH, stdin);
                pessoa.telefone[strcspn(pessoa.telefone, "\n")] = '\0'; // Removendo o caractere de nova linha

                printf("Digite o email: ");
                limparBuffer();
                fgets(pessoa.email, MAX_LENGTH, stdin);
                pessoa.email[strcspn(pessoa.email, "\n")] = '\0'; // Removendo o caractere de nova linha

                // Adicionando a pessoa à lista
                if (adicionar(pessoa)) {
                    printf("Pessoa adicionada com sucesso.\n");
                } else {
                    printf("Falha ao adicionar pessoa.\n");
                }
            } 
            else {
                printf("CPF ja cadastrado.\n");
            }
            break;
        case 2:
            printf("Digite o CPF: ");
            scanf("%s", cpf);
            // Excluindo a pessoa com o CPF fornecido
            excluir(cpf);
            break;
        case 3:
            printf("Digite o CPF: ");
            scanf("%s", cpf);
            // Alterando os dados da pessoa com o CPF fornecido
            alterar(cpf);
            break;
        case 4:
            printf("Digite o CPF: ");
            scanf("%s", cpf);
            // Imprimindo os dados da pessoa com o CPF fornecido
            imprimir(cpf);
            break;
        case 5:
            // Imprimindo todos os registros da lista
            imprimirTodos();
            break;
        case 6:
            // Ordenando a lista por nome
            ordenar();
            printf("Lista ordenada por nome.\n");
            break;
        case 7:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            }
    }
    return 0;
}
