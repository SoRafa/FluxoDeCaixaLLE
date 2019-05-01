#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nodo{
    int cod;
    int data;
    float entrada;
    float saida;
    float valor;
    char desc[30];
  struct nodo * elo;
  }; typedef struct nodo Lista;

Lista * InicializaLLE()
{
  return NULL;
}

//Insere ordenado por Data
Lista * InsereLivro(Lista *L, int Cod, int Data, float Entrada, float Saida, char Desc[])
{ Lista *pAux, *novo;
  novo = (Lista *) malloc (sizeof (Lista));
  novo->cod = Cod;
  novo->data = Data;
  novo->entrada = Entrada;
  novo->saida = Saida;
  strcpy(novo->desc, Desc);
  novo->elo = NULL;
  if (L == NULL)
      L = novo;
 else{
    pAux = L; // p1 no início da lista
    while (pAux->elo != NULL){
        pAux = pAux->elo;   //p1 no final da lista
        }
    pAux->elo = novo; //encadeia com o novo
    }
  return L;
}

//Exibe lista completa
void ExibeLLE(Lista * L)
{
    Lista * Paux;
    Paux = L;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    return 0;
    }
      printf("Endereco inicial em %d\n",L);
      printf("COD\t DATA\t DESCRICAO\t SAIDA\t ENTRADA\n");
      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){ //Percorrer a lista
          printf("%d\t %d  %s  \t %d \t %d \n", Paux->cod, Paux->data,Paux->desc, Paux->saida, Paux->entrada);
          Paux = Paux->elo;
          }
          return 0;
  }

//Exibe a Lista utilizando a data
void ExibeData(Lista * L, int d){
    Lista * Paux;
    Paux = L;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    return 0;
    }
      printf("Endereco inicial em %d\n",L);
      printf("COD\t DATA\t DESCRICAO\t SAIDA\t ENTRADA\n");
      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){ //Percorrer a lista
                if(d == Paux->data){
          printf("%d\t %d  %s  \t %d \t %d \n", Paux->cod, Paux->data,Paux->desc, Paux->saida, Paux->entrada);
          }
        Paux = Paux->elo;
  }
  return 0;
}

//Remove o Nodo por código
Lista * RemoverCod(Lista * lAux,int cod ){

Lista *ptAux, *desaloca;
    if(lAux==NULL){
      printf("ERRO - Lista Vazia!\n\n");
      return lAux;
      }
    if(lAux->elo == NULL){
      lAux = NULL;
      return lAux;
    }
        ptAux = lAux; // p1 no início da lista
        while(ptAux->elo->cod != cod){
            ptAux = ptAux->elo;
            }
        desaloca = ptAux->elo;
        ptAux->elo = ptAux->elo->elo;
        free (desaloca);
    return lAux ;
}

//___________________________________________________
int main()
{
int opcao,x=0, i=0; //variaveis Menu
int COD,DATA,TIPO;
float VALOR, ENTRADA, SAIDA;
char DESC[30];
Lista * L;
L = InicializaLLE();

 do{
    system("cls");
    printf("\nEntre com a opcao:\n");
    printf(" 1 - Insere uma entrada/saida no livro\n");
    printf(" 2 - Remove entrada do livro\n");
    printf(" 3 - Consulta a movimentacao\n");
    printf(" 4 - Exibe todo o fluxo de caixa\n");
    printf(" 5 - Exibe o total de saidas, entradas e o saldo\n");
    printf(" 6 - Sair\n");

    scanf("%d",&opcao);
    fflush(stdin);  //para resolver alguns problemas do scanf, limpando o buffer de teclado
    switch (opcao)
    {
      case 1: printf("digite o codigo:\n");
              scanf("%d", &COD);
              printf("data que esta sendo inserido: (ANO/MES/DIA)\n");
              scanf("%d", &DATA);
              printf("digite o tipo de valor que vai ser inserido:\n");
              printf("1 - Entrada \t \t 2- Saida:\n");
              scanf("%d", &TIPO);
              printf("Digite o valor:");
              scanf("%f", &VALOR);
              if(TIPO == 1){
                ENTRADA = VALOR;
                SAIDA = 0;  } else {
                SAIDA = VALOR;
                ENTRADA = 0;}
                printf("digite a descricao:");
                scanf("%s", &DESC);
                printf("%f   %d\n", VALOR, TIPO);
                printf("%f   %f", ENTRADA, SAIDA);
                L = InsereLivro(L, COD, DATA, ENTRADA, SAIDA, DESC);
                system("pause");
              break;
      case 2:   printf("Digite o codigo do nodo que deseja remover: \n");
                scanf("%d", &i);
                L = RemoverCod(L, i);
              break;
      case 3:   printf("coloque uma data:\n");
                scanf("%d", &i);
                ExibeData(L,i);
                system("pause");
              break;
      case 4:ExibeLLE(L);
            system("pause");
              break;
      case 5: printf("Digite um valor para inserir:\n");

              break;
      case 6: exit(0);

            break;
      default:
            printf("\tOpcao invalida!\n");
            system("pause");
      }
  }while(x == 0);
}
