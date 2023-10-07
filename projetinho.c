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
  int main() 
{
  struct Tarefa tarefa; 
  
    printf("Digite o codigo da tarefa: "/n);
  
    scanf("%d", &tarefa.codigo);
  
    printf("Digite o nome da tarefa: "/n);
  
    scanf("%s", &tarefa.nome);
  
    printf("Digite o nome do projeto: "/n);
  
    scanf("%s", &tarefa.projeto); 
   
    printf("Digite a data de inicio: "/n);

    scanf("%d", &tarefa.inicio.dia);
    scanf("%d", &tarefa.inicio.mes);
    scanf("%d", &tarefa.inicio.ano);

    printf("Digite a data de termino: "/n);

    scanf("%d", &tarefa.termino.dia);
    scanf("%d", &tarefa.termino.mes);
    scanf("%d", &tarefa.termino.ano);

    printf("Codigo: %d\n", tarefa.codigo);

    printf("Nome: %s\n", tarefa.nome);

    printf("Projeto: %s\n", tarefa.projeto);

    printf("Data de inicio: %d/%d/%d\n", tarefa.inicio.dia, tarefa.inicio.mes, tarefa.inicio.ano);

    printf("Data de termino: %d/%d/%d\n", tarefa.termino.dia, tarefa.termino.mes, tarefa.termino.ano);



  return 0;
}
