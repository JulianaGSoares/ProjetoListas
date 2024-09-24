#include <stdio.h>
#include <string.h>

#include "lista.h" 

Pessoa lista[MAX_LENGTH]; // Declaração da lista de pessoas com um tamanho máximo definido
int count = 0; // Variável global para controlar o número de pessoas na lista

void inicializar() {
    count = 0; // Função para inicializar a lista, zerando o contador de pessoas
}

int adicionar(Pessoa pessoa) {
    if (buscar(pessoa.cpf) == -1) { // Verifica se o CPF da pessoa já está cadastrado na lista
        if (count < MAX_LENGTH) { // Verifica se ainda há espaço na lista para adicionar uma nova pessoa
            strcpy(lista[count].nome, pessoa.nome); // Copia o nome da nova pessoa para a lista na posição atual
            strcpy(lista[count].endereco, pessoa.endereco);
            strcpy(lista[count].cpf, pessoa.cpf);
            strcpy(lista[count].telefone, pessoa.telefone);
            strcpy(lista[count].email, pessoa.email);
            count++; // Incrementa o contador de pessoas na lista
            
            return 1; // Retorna 1 para indicar sucesso na adição da nova pessoa
        } 
        else {
            printf("A lista esta cheia.\n"); // Imprime uma mensagem de erro caso a lista esteja cheia
            return 0;
        }
    } 
    else {
        printf("CPF ja cadastrado.\n"); // Imprime uma mensagem de erro caso o CPF já esteja cadastrado
        return 0;
    }
}

void excluir(char *cpf) {
    int posicao = buscar(cpf); // Busca a posição do CPF na lista
    if (posicao != -1) { // Verifica se o CPF foi encontrado na lista
        for (int i = posicao; i < count - 1; i++) {
            lista[i] = lista[i + 1]; // Desloca os elementos à direita do elemento a ser excluído uma posição para a esquerda
        }
        count--; // Decrementa o contador de pessoas na lista
        printf("Pessoa excluida com sucesso.\n"); // Imprime uma mensagem de sucesso na exclusão
    }
}

int buscar(char *cpf) {
    for (int i = 0; i < count; i++) {
        if (strcmp(lista[i].cpf, cpf) == 0) {
            return i; // Retorna a posição do CPF na lista se encontrado
        }
    }
    return -1; // Retorna -1 caso o CPF não seja encontrado na lista
}

void alterar(char *cpf) {
    int posicao = buscar(cpf); // Busca a posição do CPF na lista
    if (posicao != -1) { // Verifica se o CPF foi encontrado na lista
        // Solicita e atualiza os dados da pessoa na posição encontrada na lista
        printf("Digite o novo nome (ou pressione Enter para manter): ");
        limparBuffer();
        fgets(lista[posicao].nome, MAX_LENGTH, stdin);
        lista[posicao].nome[strcspn(lista[posicao].nome, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Digite o novo endereco (ou pressione Enter para manter): ");
        limparBuffer();
        fgets(lista[posicao].endereco, MAX_LENGTH, stdin);
        lista[posicao].endereco[strcspn(lista[posicao].endereco, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Digite o novo telefone (ou pressione Enter para manter): ");
        limparBuffer();
        fgets(lista[posicao].telefone, MAX_LENGTH, stdin);
        lista[posicao].telefone[strcspn(lista[posicao].telefone, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Digite o novo email (ou pressione Enter para manter): ");
        limparBuffer();
        fgets(lista[posicao].email, MAX_LENGTH, stdin);
        lista[posicao].email[strcspn(lista[posicao].email, "\n")] = '\0'; // Remove o caractere de nova linha

        printf("Alteracoes realizadas com sucesso.\n"); // Imprime uma mensagem de sucesso na alteração
    } 
    else {
        printf("CPF nao cadastrado.\n"); // Imprime uma mensagem de erro caso o CPF não seja encontrado
    }
}

void imprimir(char *cpf) {
    int posicao = buscar(cpf); // Busca a posição do CPF na lista
    if (posicao != -1) { // Verifica se o CPF foi encontrado na lista
        // Imprime os dados da pessoa na posição encontrada na lista
        printf("Nome: %s \n", lista[posicao].nome);
        printf("Endereco: %s \n", lista[posicao].endereco);
        printf("CPF: %s \n", lista[posicao].cpf);
        printf("Telefone: %s \n", lista[posicao].telefone);
        printf("Email: %s \n", lista[posicao].email);
    } 
    else {
        printf("CPF nao cadastrado.\n"); // Imprime uma mensagem de erro caso o CPF não seja encontrado
    }
}

void imprimirTodos() {
    // Percorre toda a lista e imprime os dados de todas as pessoas
    for (int i = 0; i < count; i++) {
        printf("Nome: %s \n", lista[i].nome);
        printf("Endereco: %s \n", lista[i].endereco);
        printf("CPF: %s \n", lista[i].cpf);
        printf("Telefone: %s \n", lista[i].telefone);
        printf("Email: %s \n", lista[i].email);
        printf("\n");
    }
}

void ordenar() {
    // Implementação de um algoritmo de ordenação (exemplo: bubble sort) para ordenar a lista por nome
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(lista[j].nome, lista[j + 1].nome) > 0) {
                Pessoa temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

void limparBuffer() {
    scanf("%*c");
}
