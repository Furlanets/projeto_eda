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
  int Status;
};typedef struct Tarefa Tarefa;

struct no {
  Tarefa info;
  struct no *prox;
};typedef struct no No;

struct fila {
  No *inicio;
  No *fim;
};typedef struct fila Fila;

void limparBuffer();

No* inserir_fim(No *f, Tarefa t);

void insereFila (Fila* f, Tarefa tarefa);

void imprimeFila (Fila* f);

Fila* liberaFila (Fila* f);

Fila* CriaFila ();

Tarefa Criar_Tarefa();

int ComparaDia(Data dataInicio, Data dataTermino);






  int main()
{
  Tarefa tarefa;

  tarefa = Criar_Tarefa();

  Fila* f =  CriaFila();

  insereFila(f, tarefa);

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

void insereFila (Fila* f, Tarefa tarefa)
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

Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
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

    printf("A tarefa possui alguma pendencia? (s - Sim, n - Nao)\n");

    char pendencia = getchar();
    fflush(stdin);

    if
    (pendencia == 's' || pendencia == 'S')
    {
      tarefa.Status = 1;
    }
    else

    if
    (pendencia == 'n' || pendencia == 'N')
    {
      tarefa.Status = 0;
    }

    else
    {
      printf("Opcao invalida, tente novamente.\n");
    }

    printf("Status: %d\n", tarefa.Status);

    return tarefa;
}

    

    ///tarefa.Status = 0;

  ////return tarefa;
///}

int ComparaDia(Data dataInicio, Data dataTermino) 

{     
  
if (dataInicio.ano > dataTermino.ano){return 1;}     
else 

if (dataInicio.ano != dataTermino.ano){return 0;}     
else 

if (dataInicio.mes > dataTermino.mes){return 1;}     
else 

if (dataInicio.mes == dataTermino.mes && dataInicio.dia > dataTermino.dia){return 1;}     

else

return 0;}
