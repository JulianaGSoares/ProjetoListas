#ifndef LISTA_H
#define LISTA_H

#define MAX_LENGTH 100

typedef struct {
    char nome[MAX_LENGTH];
    char endereco[MAX_LENGTH];
    char cpf[MAX_LENGTH];
    char telefone[MAX_LENGTH];
    char email[MAX_LENGTH];
} Pessoa;

// Protótipos das funções
void inicializar();
int adicionar(Pessoa pessoa);
void excluir(char *cpf);
int buscar(char *cpf);
void alterar(char *cpf);
void imprimir(char *cpf);
void imprimirTodos();
void ordenar();
void limparBuffer();

#endif
