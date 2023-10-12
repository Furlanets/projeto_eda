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

Tarefa Criar_Tarefa(int codigo, int Status);

int ComparaDia(Data dataInicio, Data dataTermino);

int menu();

void Modifica_Tarefa();

void trocatarefa(Fila* fila, Tarefa tarefa);

int main()
{
    
  int codigo = 0;
  int looping = 1;
  int Status = 2;
  Fila* fila = CriaFila();

  do{
  
  Status = 2;

  int escolha = menu();

  switch(escolha){

    case 1:
      printf("\n\n-Inserindo tarefa-\n");
      Tarefa t = Criar_Tarefa(codigo, Status);
      insereFila(fila, t);
      break;

    case 2:
      printf("\n\n-Removendo tarefa-\n");
      break;

    case 3:
      printf("\n\n-Modificando tarefa-\n");
      Modifica_Tarefa(fila);
      break;

    case 4:
      printf("\n\n-Listando tarefas\n");
      imprimeFila(fila);
      break;

    case 5:
      printf("\n\n-Programa terminado-\n");
      return 0;
      break;
  }

  } while(looping == 1);

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
    printf("\n\n");
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

Tarefa Criar_Tarefa(int codigo, int Status)

{
  Tarefa tarefa;

if(codigo == 0){

    printf("\nDigite o codigo da tarefa: \n\n");

    scanf("%d", &tarefa.codigo);}

    else{

    tarefa.codigo = codigo;

    }

    limparBuffer();

    printf("\nDigite o nome da tarefa: \n\n");

    scanf("%s", tarefa.nome);

    limparBuffer();

    printf("\nDigite o nome do projeto: \n\n");

    scanf("%s", tarefa.projeto);

    limparBuffer();

    printf("\nDigite a data de inicio: \n\n");

    scanf("%d", &tarefa.inicio.dia);
    limparBuffer();
    scanf("%d", &tarefa.inicio.mes);
    limparBuffer();
    scanf("%d", &tarefa.inicio.ano);
    limparBuffer();

    printf("\nDigite a data de termino: \n");

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
    
    if(Status == 0 || Status == 1){
        tarefa.Status = Status;
    }
    else{
        
        printf("A tarefa possui alguma pendencia? (s - Sim, n - Nao)\n");
    fflush(stdin);
    char pendencia = getchar();
    fflush(stdin);

    if
    (pendencia == 's' || pendencia == 'S')
    {
      tarefa.Status = 1;
      printf("\nTarefa definida como pendente.\n\n");
    }
    else

    if
    (pendencia == 'n' || pendencia == 'N')
    {
      tarefa.Status = 0;
      printf("\nTarefa definida como concluida.\n\n");
    }

    else
    {
      printf("\nOpcao invalida, tente novamente.\n\n");
    }
    
    }
return tarefa;
}

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

int menu()
{
  int escolha;

  printf("Bem vindo ao sistema de gerenciamento de tarefas!\n");

  printf("Digite 1 para inserir uma tarefa\n");

  printf("Digite 2 para remover uma tarefa\n");

  printf("Digite 3 para modificar uma tarefa\n");

  printf("Digite 4 para listar as tarefas\n");

  printf("Digite 5 para terminar o programa\n");

  printf("Digite sua escolha: \n");

  scanf("%d", &escolha);

  limparBuffer();

return escolha;}

void Imprime_Tarefa(Tarefa info)
{
printf("Codigo da tarefa: %d\n", info.codigo);
    printf("Nome da tarefa: %s\n", info.nome);
    printf("Nome do projeto: %s\n", info.projeto);
    printf("Data de inicio da tarefa: %2d/%2d/%2d\n", info.inicio.dia, info.inicio.mes, info.inicio.ano);
    printf("Data de termino da tarefa: %2d/%2d/%2d\n", info.termino.dia, info.termino.mes, info.termino.ano);
    printf("Status da tarefa: %d\n", info.Status);
    printf("\n");
}

void Modifica_Tarefa(Fila* f)

{   No* aux = f->inicio;

    int codigo = 0;
    Tarefa tarefa_aux;
    printf("teste");

    printf("Digite o codigo da tarefa que deseja modificar: \n");
    scanf("%d", &codigo);

    while(aux!=NULL)
    {

        if(aux->info.codigo == codigo)
        {
        tarefa_aux = aux->info;
        Imprime_Tarefa(aux->info);
        }
        
        aux = aux->prox;

    }

    Tarefa nova_tarefa = Criar_Tarefa(codigo, tarefa_aux.Status);
    trocatarefa(f, nova_tarefa);

    menu();
}

void trocatarefa(Fila* fila, Tarefa tarefa)
{

    No *aux = fila->inicio;
    while(aux != NULL){
    printf("%s", aux->info.codigo);
        if(aux->info.codigo == tarefa.codigo){
            printf("Tarefa encontrada\n");

            aux->info = tarefa;
        }
        aux = aux->prox;
    }
    
}
