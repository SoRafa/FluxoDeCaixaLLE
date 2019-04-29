#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct nodo{
    int cod;
    int data;
    int tipo;
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

//slide 14 - insere no meio, na posicao desejada
Lista * InsereLivro(Lista *L, int Cod, int Data, float Entrada, float Saida , char Desc[])
{ Lista *pAux, *novo; int n;
  novo = (Lista *) malloc (sizeof (Lista));
  novo->cod = Cod;
  novo->data = Data;
  novo->entrada = Entrada;
  novo->saida = Saida;
  novo->desc = Desc;
  if (novo.data < pAux.data){
     novo->elo = L;
     L = novo;
  }
  else {
     if(L == NULL){
      printf("Posicao invalida, lista vazia!\n\n");
      system("pause");
      return L;
     }
     pAux = L;
     for (n = 0; n < posicao-2; n++)
     {
        if (pAux->elo == NULL) {
           printf("Posicao %d invalida na insersao!\n\n",posicao);
           system("pause");
           return L;
         }
         pAux = pAux->elo;
      }
      novo->elo = pAux->elo;
      pAux->elo = novo;
   }
  return L;
}

//Remove
Lista * RemoveLLE_I(Lista * paux){
  Lista *desaloca;
  if(paux==NULL)
{
  printf("ERRO - Lista Vazia!\n\n");
  return paux;
}
  desaloca = paux;
  paux = paux->elo;
  free (desaloca);
return paux;
}

void ExibeData(Lista * L, int d){
    Lista * Paux;
    int cont=0;
    if (L == NULL){ //nenhum elemento
    printf("\nLista vazia!\n\n");
    }else if(d==Paux.data){
      printf("Endereco inicial em %d\n",L);
      printf("COD\t DATA\t DESCRICAO\t SAIDA\t ENTRADA\n");
      Paux = L; //Paux recebe o endereço do início da lista
        while (Paux != NULL){ //Percorrer a lista
          printf("%d\t %d \t\t   %d\t\t %d \n", Paux->cod, Paux->data,Paux->desc,);
          Paux = Paux->elo;
          cont++;
    }
  }
}

void RemoveCod(Lista * L, int c){
  printf("Digite o codigo do nodo que deseja remover: \n");
  scanf("%d", c);

}

//___________________________________________________
int main()
{
int opcao,x=0; //variaveis Menu
int COD,DATA,TIPO;
float VALOR,ENTRADA = 0,SAIDA = 0;
char DESC[];
Lista * L;
L = InicializaLLE();

 do{
    system("cls");
    printf("\nEntre com a opcao:\n");
    printf(" 1 - Insere uma entrada/saida no livro\n");
    printf(" 2 - Remove entrada do livro\n");
    printf(" 3 - Consulta a movimentação\n");
    printf(" 4 - Exibe todo o fluxo de caixa\n");
    printf(" 5 - Exibe o total de saídas, entradas e o saldo\n");
    printf(" 6 - Sair\n");


    scanf("%d",&opcao);
    fflush(stdin);  //para resolver alguns problemas do scanf, limpando o buffer de teclado
    switch (opcao)
    {
      case 1: printf("digite o código:\n");
              scanf("%d", &COD);
              printf("data que está sendo inserido: (ANOMESDIA)\n");
              scanf("%d", &DATA);
              printf("digite o tipo de valor que vai ser inserido:\n");
              printf("1 - Entrada \t \t 2- Saida:\n");
              scanf("%d", &TIPO);
              printf("Digite o valor:");
              scanf("%f", &VALOR);
              if(TIPO == 1){
                ENTRADA = VALOR;
                SAIDA = 0;  }else{
                SAIDA = VALOR;
                ENTRADA = 0;}
              printf("digite a descricao:");
              scanf("%s", &DESC);
              InsereLivro(L, COD, DATA, ENTRADA, SAIDA, DESC);
              system("pause");
              break;
      case 2: printf("Digite um valor para inserir:\n");

              break;
      case 3:
              break;
      case 4:
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
