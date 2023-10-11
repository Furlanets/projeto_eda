#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct data{
    int dia;
    int mes;
    int ano;
};
typedef struct data Data;
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

No* inserir_fim(No *f, Tarefa t);

void InsereFila (Fila* f, Tarefa tarefa);

void imprimeFila (Fila* f);

Fila* liberaFila (Fila* f);

void limparBuffer();

Tarefa Criar_Tarefa();

  int main()
{
  Tarefa tarefa;

  tarefa = Criar_Tarefa();

  return 0;
}

void limparBuffer()
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);      //E0F = End of File;    Roda o bufer inteiro de memoria registrando os "\n", quando n'ao houver mais nenhum, ele detecta que eh o fim do arquivo]
}

No* inserir_fim(No *f, Tarefa t) {
  No *novo = (No*) malloc(sizeof(No));
  novo->info = t;
  novo->prox = NULL;
  if (f == NULL) {
    return novo;
  } else {
    f->prox = novo;
    return novo;
  }
}

void InsereFila (Fila* f, Tarefa tarefa)
{
    f->fim = inserir_fim(f->fim,tarefa);
    if (f->inicio==NULL) /* fila antes vazia? */
    f->inicio = f->fim;
}

void imprimeFila (Fila* f)
{
    No* q;
    printf("\n\t\t");
    for (q=f->inicio; q!=NULL; q=q->prox)
    {
        printf("Codigo: %d, Nome: %s, Projeto: %s, Data de inicio: %d/%d/%d, Data de termino: %d/%d/%d\n",
               q->info.codigo, q->info.nome, q->info.projeto,
               q->info.inicio.dia, q->info.inicio.mes, q->info.inicio.ano,
               q->info.termino.dia, q->info.termino.mes, q->info.termino.ano);
    }
    printf("\n");
}

Fila* liberaFila (Fila* f)
{
    No* q = f->inicio;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

Tarefa Criar_Tarefa()
{
  Tarefa tarefa;

    printf("Digite o codigo da tarefa: \n");

    scanf("%d", &tarefa.codigo);

    limparBuffer();

    printf("Digite o nome da tarefa: \n");

    scanf("%s", tarefa.nome);

    limparBuffer();

    printf("Digite o nome do projeto: \n");

    scanf("%s", tarefa.projeto);

    limparBuffer();

    printf("Digite a data de inicio: \n");

    scanf("%d", &tarefa.inicio.dia);
    limparBuffer();
    scanf("%d", &tarefa.inicio.mes);
    limparBuffer();
    scanf("%d", &tarefa.inicio.ano);
    limparBuffer();

    printf("Digite a data de termino: \n");

    scanf("%d", &tarefa.termino.dia);
    limparBuffer();
    scanf("%d", &tarefa.termino.mes);
    limparBuffer();
    scanf("%d", &tarefa.termino.ano);
    limparBuffer();

    printf("Codigo: %d\n", tarefa.codigo);

    printf("Nome: %s\n", tarefa.nome);

    printf("Projeto: %s\n", tarefa.projeto);

    printf("Data de inicio: %d/%d/%d\n", tarefa.inicio.dia, tarefa.inicio.mes, tarefa.inicio.ano);

    printf("Data de termino: %d/%d/%d\n", tarefa.termino.dia, tarefa.termino.mes, tarefa.termino.ano);

  return tarefa;
}
