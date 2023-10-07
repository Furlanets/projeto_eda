#include <stdio.h>
#include <stdlib.h>
#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
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

No* retira_inicio (No* ini) 
{
    No* p = inicio->prox;
    free(inicio);
    return p;
}

int RetiraFila (Fila* f)
{
    int v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    v = f->inicio->info;
    f->inicio = retira_inicio(f->inicio);
    if (f->inicio == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void imprimeFila (Fila* f)
{
    No* q;
    printf("\n\t\t");
    for (q=f->inicio; q!=NULL; q=q->prox)
    {
        printf("%d - ",q->info);
    }
    printf("\n");
}

Fila* liberaFila (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

}
  int main() {



  return 0;
}
