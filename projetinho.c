#include <stdio.h>
#include <stdlib.h>

struct data{;
    int dia;
    int mes;
    int ano;
};typedef struct data Data;
struct Tarefa {
  int codigo;
  char nome[30];
  char projeto[30];
  Data inicio;
  Data termino;
};typedef struct Tarefa Tarefa;

struct no {
  Tarefa info;
  struct no *prox;
};typedef struct no No;

struct fila {
  No *inicio;
  No *fim;
};typedef struct fila Fila;



No* inserir_fim(No *f, Tarefa t) {
  No *novo = (No*) malloc(sizeof(No));
  novo->info = t;
  novo->prox = NULL;
  if (f==NULL) {
    f->prox = novo;

  return novo;
  }
void InsereFila (Fila* f, Tarefa tarefa)
{
    f->fim = inserir_fim(f->fim,tarefa);
    if (f->inicio==NULL) /* fila antes vazia? */
    f->inicio = f->fim;
}



}
  int main() {


  return 0;
}
