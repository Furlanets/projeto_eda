#include <stdio.h>

typedef struct {
  int codigo; // Definindo o código da tarefa 
  char nome[30]; // Definindo o nome da tarefa com no maximo 30 caracteres
  char projeto[30]; // Definindo o nome do projeto com no maximo 30 caracteres  
  struct { 
    int dia; // Data de início: valor do dia
    int mes; // Data de início: valor do mês
    int ano; // Data de início: valor do ano
  } data_inicio;
  struct { 
    int dia; // Data de término: valor do dia
    int mes; // Data de término: valor do mês
    int ano; // Data de término: valor do ano
  } data_termino;
  int status; // Status da tarefa: 1 = Atrasada, 0 = Em dia e -1 = atrasada
} Tarefa;

typedef struct no {
  Tarefa tarefa; // Dados da tarefa
  struct no *prox; // Ponteiro para o próximo nó da fila
} No;

typedef struct {
  No *inicio; // Ponteiro para o início da fila
  No *fim; // Ponteiro para o fim da fila
} Fila;

// Função que inicializa a fila, atribuindo NULL aos ponteiros de início e fim
void inicializar_fila(Fila *f) {
  f->inicio = NULL;
  f->fim = NULL;
}

// Função que verifica se a fila está vazia, retornando 1 se sim e 0 se não
int fila_vazia(Fila *f) {
  return (f->inicio == NULL);
}

// Função que insere uma nova tarefa no fim da fila, alocando memória para um novo nó e atribuindo os dados da tarefa
void inserir_fila(Fila *f, Tarefa t) {
  No *novo = (No*) malloc(sizeof(No)); // Aloca memória para um novo nó
  novo->tarefa = t; // Atribui os dados da tarefa ao nó
  novo->prox = NULL; // Atribui NULL ao ponteiro para o próximo nó
  if (fila_vazia(f)) { // Se a fila estiver vazia, o novo nó será o início e o fim da fila
    f->inicio = novo;
    f->fim = novo;
  } else { // Se não estiver vazia, o novo nó será o fim da fila, e o antigo fim apontará para ele
    f->fim->prox = novo;
    f->fim = novo;
  }
}
