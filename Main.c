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

Lista * InicializaLLE(){
  return NULL;
}

//Insere 
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
    if(lAux->cod == cod){
      desaloca = lAux;
      lAux = lAux->elo;
      free (desaloca);
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

//Exibe a Lista utilizando a data para filtrar
void ExibeData(Lista * L, int d){
    Lista * Paux;
    Paux = L;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    return 0;
    } if(d == Paux->data){
    printf("COD\t  DATA\t     DESCRICAO\t SAIDA\t   ENTRADA\n");
    Paux = L;}
      while (Paux != NULL){
        if(d == Paux->data){
          printf("%d\t %d  %s  \t %.2f \t %.2f \n", Paux->cod, Paux->data,Paux->desc, Paux->saida, Paux->entrada);
      }
    Paux = Paux->elo;
  }
  return 0;
}

//Salve lista completa em Arquivo de Texto
void ExibeLLE(Lista * L)
{
    Lista * Paux;
    Paux = L;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    return 0;
    }
      printf("COD\t DATA\t     DESCRICAO\t SAIDA\t   ENTRADA\n");
      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){ //Percorrer a lista
          printf("%d\t %d    %s  \t %.2f \t %.2f \n", Paux->cod, Paux->data,Paux->desc, Paux->saida, Paux->entrada);
          Paux = Paux->elo;
        }
    return 0;
  }

//Exibe lista completa
void SalvaArquivo(Lista * L)
{
    char nome[10]="Fluxo.txt";
    FILE * FFluxo;
    Lista * Paux;
    Paux = L;
    if (L == NULL){ //nenhum elemento
      printf("\nLista vazia!\n\n");
    return 0;
    }
      FFluxo = fopen(nome, "a+");
      fprintf(FFluxo,"COD\t DATA\t     DESCRICAO\t SAIDA\t   ENTRADA\n");
      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){ //Percorrer a lista
          fprintf(FFluxo,"%d\t %d    %s  \t %.2f \t %.2f \n", Paux->cod, Paux->data,Paux->desc, Paux->saida, Paux->entrada);
          Paux = Paux->elo;
        }
      fclose(FFluxo);
    return 0;
  }

void MostraSaldo(Lista * L){
Lista * Paux;
float SomaE=0;
float SomaS=0;
float saldo=0;
    if (L == NULL){ //nenhum elemento
      printf("\nLista vazia!\n\n");
    return 0;
    }
      Paux = L; //Paux recebe o endereço do início da lista
        printf("\nEntradas:\n");
        while (Paux != NULL){
            if(Paux->entrada == 0){Paux = Paux->elo;
              }else{
                printf(" Valor: %.2f \n Descricao: %s\n\n",Paux->entrada,Paux->desc);
                SomaE = Paux->entrada + SomaE;
                Paux = Paux->elo;
            }
          }
        printf("Total: %.2f\n\n", SomaE);

        Paux = L; //Paux recebe o endereço do início da lista
        printf("\nSaidas:\n");
        while (Paux != NULL){
            if(Paux->saida == 0){Paux = Paux->elo;
              }else{
                printf(" Valor: %.2f \n Descricao: %s\n\n",Paux->saida,Paux->desc);
                SomaS = Paux->saida + SomaS;
                Paux = Paux->elo;
            }
          }
        printf("Total: %.2f \n\n", SomaS);

            saldo = SomaE - SomaS;
            printf("\n Saldo = %.2f\n",saldo);
        return 0;
}


//___________________________________________________
int main()
{
int opcao,x=0, i=0; //variaveis Menu
int COD = 1,DATA,TIPO;
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
      case 1: printf("data que esta sendo inserido: (ANO/MES/DIA)\n");
              scanf("%d", &DATA);
              printf("digite o tipo de valor que vai ser inserido:\n");
              printf("1 - Entrada \t \t 2- Saida:\n");
              scanf("%d", &TIPO);
              printf("Digite o valor:");
              scanf("%f", &VALOR);
                if(TIPO == 1){
                  ENTRADA = VALOR;
                  SAIDA = 0;  
                  } else {
                  SAIDA = VALOR;
                  ENTRADA = 0;}
                printf("digite a descricao:");
                scanf("%s", &DESC);
                printf("%.2f   %d\n", VALOR, TIPO);
                printf("%.2f   %.2f\n", ENTRADA, SAIDA);
                L = InsereLivro(L, COD, DATA, ENTRADA, SAIDA, DESC);
                COD++;
                system("pause");
              break;
      case 2: printf("Digite o codigo do nodo que deseja remover: \n");
              scanf("%d", &i);
              L = RemoverCod(L, i);
              break;
      case 3: printf("coloque uma data:\n");
              scanf("%d", &i);
              ExibeData(L,i);
              system("pause");
              break;
      case 4: ExibeLLE(L);
              printf("voce deseja salvar a lista?\n");
              printf("1 - Sim \t \t 2-Nao\n");
              scanf("%d",&TIPO);
                if (TIPO == 1){
                  SalvaArquivo(L);
                }
              break;
      case 5: MostraSaldo(L);
              system("pause");
              break;
      case 6: exit(0);
              break;
      default:
            printf("\tOpcao invalida!\n");
            system("pause");
      }
  }while(x == 0);
}
