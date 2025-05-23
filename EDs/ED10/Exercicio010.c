/*
 Exercicio10 - v0.0. - 13 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux :  gcc -o exercicio10 exercicio10.c
 Windows: gcc -o exercicio10 exercicio10.c
 Para executar em terminal (janela de comandos):
 Linux : ./exercicio10
 Windows: exercicio10
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX 100

// -------------------------- definicao de classe

/**
  * Metodo01.
  */
int RandomIntGenerate(int inferior, int superior) 
{
  int limite = (superior - inferior + 1);
  if (limite > 106) limite = 106;
  return inferior + rand() % limite;
}

void metodo01( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1011");
  int inferior = 0, superior = 0, n = 0;

    printf("\nInforme o valor inferior do intervalo: ");
    scanf("%d", &inferior);
    getchar();

    printf("\nInforme o valor superior do intervalo: ");
    scanf("%d", &superior);
    getchar();

    if (inferior > superior) {
        printf("\nLimite inferior maior que superior");
        return;
    }

    printf("\nInforme a quantidade de numeros a serem gerados: ");
    scanf("%d", &n);

    int valores[n];

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        valores[i] = RandomIntGenerate(inferior, superior);
    }

    FILE *arquivo = fopen("DADOS.TXT", "w");

    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "%d\n", n);

    for (int i = 0; i < n; i++) 
    {
        fprintf(arquivo, "%d\n", valores[i]);
    }

    fclose(arquivo);

    printf("Valores gravados com sucesso no arquivo DADOS.TXT\n");
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo01 ( )

/**
  * Metodo02.
  */

typedef struct descritor
{
    int  x;
    int  tamanho;
    int *referencia;
} descritor;

descritor readArrayFromFile(char nomeArquivo[])
{
    FILE *arquivo = fopen(nomeArquivo, "rt");
    descritor arranjo;
    arranjo.tamanho = 0;
    arranjo.referencia = NULL;

    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d", &arranjo.tamanho);
        arranjo.referencia = (int *) malloc(arranjo.tamanho * sizeof(int));

        if (arranjo.referencia != NULL)
        {
            for (arranjo.x = 0; arranjo.x < arranjo.tamanho; arranjo.x++)
            {
                fscanf(arquivo, "%d", &arranjo.referencia[arranjo.x]);
            }
        }

        fclose(arquivo);
    }
    else
    {
        printf("Erro ao abrir o arquivo!\n");
    }

    return arranjo;
}

int arraySearch(int valor, descritor arranjo)
{
    for (arranjo.x = 0; arranjo.x < arranjo.tamanho; arranjo.x++)
    {
        if (arranjo.referencia[arranjo.x] == valor)
        {
          return arranjo.x;
        }
    }
    return -1;
}
 
void metodo02 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1012");
  descritor arranjo;
  char nomeArquivo[MAX];
  int valor, posicao;

 
  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  getchar();  
  
  arranjo = readArrayFromFile(nomeArquivo);

  if (arranjo.referencia != NULL)
  {
      printf("\nValores no arranjo:\n");
      for (arranjo.x = 0; arranjo.x < arranjo.tamanho; arranjo.x++)
      {
          printf("%d ", arranjo.referencia[arranjo.x]);
      }

      printf("\n\nDigite o valor a procurar: ");
      scanf("%d", &valor);

      posicao = arraySearch(valor, arranjo);

      if (posicao >= 0)
      {
          printf("Valor %d encontrado na posicao %d.\n", valor, posicao);
      }
      else
      {
          printf("Valor %d NAO encontrado no arranjo.\n", valor);
      }

      free(arranjo.referencia);
      arranjo.referencia = NULL;
  }

// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo02 ( )

/**
  * Metodo03.
  */


int arrayCompare(descritor a, descritor b)
{
  if (a.tamanho != b.tamanho)
      return 0;

  for (a.x = 0; a.x < a.tamanho; a.x++)
  {
      if (a.referencia[a.x] != b.referencia[a.x])
          return 0;
  }

  return 1;
}

void metodo03 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo1013");
   descritor arranjo1, arranjo2;
   char nomeArquivo1[MAX], nomeArquivo2[MAX];

   printf("\n\tMetodo1013\n");

    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", nomeArquivo1);
    arranjo1 = readArrayFromFile(nomeArquivo1);

    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", nomeArquivo2);
    arranjo2 = readArrayFromFile(nomeArquivo2);

    printf("\nArranjo 1: ");
    for (arranjo1.x = 0; arranjo1.x < arranjo1.tamanho; arranjo1.x++)
    {
        printf("%d ", arranjo1.referencia[arranjo1.x]);
    }

    printf("\nArranjo 2: ");
    for (arranjo2.x = 0; arranjo2.x < arranjo2.tamanho; arranjo2.x++)
    {
        printf("%d ", arranjo2.referencia[arranjo2.x]);
    }

    if (arrayCompare(arranjo1, arranjo2))
        printf("\nArranjos sao iguais");
    else
        printf("\nArranjos sao diferentes");

    free(arranjo1.referencia);
    free(arranjo2.referencia);
    arranjo1.referencia = NULL;
    arranjo2.referencia = NULL;
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo03 ( )

/**
  * Metodo04.
  */

descritor arrayAdd(descritor a, int constante, descritor b) 
{
  descritor resultado;
  resultado.tamanho = 0;
  resultado.referencia = NULL;

  if (a.tamanho == b.tamanho) {
      resultado.tamanho = a.tamanho;
      resultado.referencia = (int*) malloc(resultado.tamanho * sizeof(int));

      if (resultado.referencia != NULL) {
          for (a.x = 0; a.x < resultado.tamanho; a.x++) {
              resultado.referencia[a.x] = a.referencia[a.x] + constante * b.referencia[a.x];
          }
      }
  } else {
      printf("Tamanhos incompativeis: %d != %d\n", a.tamanho, b.tamanho);
      getchar();
  }

  return resultado;
}

void metodo04 ( void )
{
 // Identificar
   printf("\n%s\n", "\n\tMetodo1014");
   descritor arranjo1, arranjo2, resultado;
   char nomeArquivo1[MAX], nomeArquivo2[MAX];
   int constante = 0;

    printf("\nDigite o nome do primeiro arquivo: ");
    scanf("%s", nomeArquivo1);
    arranjo1 = readArrayFromFile(nomeArquivo1);
    getchar();

    printf("\nDigite o nome do segundo arquivo: ");
    scanf("%s", nomeArquivo2);
    getchar();

    arranjo2 = readArrayFromFile(nomeArquivo2);

    printf("\nDigite a constante multiplicadora: ");
    scanf("%d", &constante);
    getchar();

    resultado = arrayAdd(arranjo1, constante, arranjo2);

    if (resultado.referencia != NULL) {
        printf("\nResultado da soma: ");
        for (resultado.x = 0; resultado.x < resultado.tamanho; resultado.x++) {
            printf("%d ", resultado.referencia[resultado.x]);
        }
        printf("\n");

        free(resultado.referencia);
        resultado.referencia = NULL;
    }

    free(arranjo1.referencia);
    free(arranjo2.referencia);
    arranjo1.referencia = NULL;
    arranjo2.referencia = NULL;
// Encerrar
   printf("\n%s\n", "Apertar ENTER para continuar.");
   getchar();
} // fim metodo04 ( )

/**
  * Metodo05.
  */

int isArrayDecrescent(descritor arranjo) 
{
    int resultado = 1;

    for (arranjo.x = 1; arranjo.x < arranjo.tamanho; arranjo.x++) 
    {
        if (arranjo.referencia[arranjo.x - 1] < arranjo.referencia[arranjo.x]) 
        {
            resultado = 0;
        }
    }

    return resultado;
}

void metodo05 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1015");
  descritor arranjo;
  char nomeArquivo[MAX];
  int resultado = 0;

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  getchar();

  arranjo = readArrayFromFile(nomeArquivo);

  if (arranjo.referencia != NULL) 
  {
      resultado = isArrayDecrescent(arranjo);

      if (resultado) {
          printf("\nO arranjo esta em ordem decrescente");
      } else {
          printf("\nO arranjo nao esta em ordem decrescente");
      }

      free(arranjo.referencia);
      arranjo.referencia = NULL;
  }
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo05 ( )

/**
  * Metodo06.
  */

typedef struct {
    int linhas;
    int colunas;
    int **referencia;
} descritorMatriz;

descritorMatriz readMatrixFromFile(char nomeArquivo[]) {
    descritorMatriz matriz;
    FILE *arquivo = fopen(nomeArquivo, "rt");

    matriz.linhas = 0;
    matriz.colunas = 0;
    matriz.referencia = NULL;

    if (arquivo != NULL) {
        fscanf(arquivo, "%d %d", &matriz.linhas, &matriz.colunas);

        matriz.referencia = (int **) malloc(matriz.linhas * sizeof(int *));
        for (int i = 0; i < matriz.linhas; i++) {
            matriz.referencia[i] = (int *) malloc(matriz.colunas * sizeof(int));
        }

        for (int i = 0; i < matriz.linhas; i++) {
            for (int j = 0; j < matriz.colunas; j++) {
                fscanf(arquivo, "%d", &matriz.referencia[i][j]);
            }
        }

        fclose(arquivo);
    } else {
        printf("Erro ao abrir o arquivo: %s\n", nomeArquivo);
    }

    return matriz;
}

void freeMatrix(descritorMatriz matriz) {
    for (int i = 0; i < matriz.linhas; i++) {
        free(matriz.referencia[i]);
    }
    free(matriz.referencia);
}

descritorMatriz matrixTranspose(descritorMatriz matriz) {
    descritorMatriz transposta;
    transposta.linhas = matriz.colunas;
    transposta.colunas = matriz.linhas;

    transposta.referencia = (int **) malloc(transposta.linhas * sizeof(int *));
    for (int i = 0; i < transposta.linhas; i++) {
        transposta.referencia[i] = (int *) malloc(transposta.colunas * sizeof(int));
    }

    for (int i = 0; i < matriz.linhas; i++) {
        for (int j = 0; j < matriz.colunas; j++) {
            transposta.referencia[j][i] = matriz.referencia[i][j];
        }
    }

    return transposta;
}

void mostrarMatriz(descritorMatriz matriz) 
{
  for (int i = 0; i < matriz.linhas; i++) 
  {
      for (int j = 0; j < matriz.colunas; j++) 
      {
        printf("%d ", matriz.referencia[i][j]);
      }
      printf("\n");
  }
}

void metodo06( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1016");
  char nomeArquivo[MAX];
  descritorMatriz matriz, transposta;

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  getchar();

  matriz = readMatrixFromFile(nomeArquivo);
  transposta = matrixTranspose(matriz);

  printf("\nMatriz original: \n");
  mostrarMatriz(matriz);

  printf("\nMatriz transposta: \n");
  mostrarMatriz(transposta);

  freeMatrix(matriz);
  freeMatrix(transposta);

// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
} // fim metodo06 ( )

/**
  * Metodo07.
  */

int matrixZero(descritorMatriz matriz) 
{
  int resultado = 1;

  for (int i = 0; i < matriz.linhas; i++) 
  {
      for (int j = 0; j < matriz.colunas; j++) 
      {
          if (matriz.referencia[i][j] != 0) 
          {
              resultado = 0;
          }
      }
  }

  return resultado;
}


void metodo07( void ) {
//identificar
  printf("\n%s\n", "\n\tMetodo1017");
  char nomeArquivo[MAX];
  descritorMatriz matriz;
  int resposta = 0;

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);
  getchar();

  matriz = readMatrixFromFile(nomeArquivo);

  resposta = matrixZero(matriz);

  if (resposta) {
      printf("\nA matriz contem apenas zeros");
  } else {
      printf("\nA matriz nao contem apenas zeros");
  }
  getchar();

  freeMatrix(matriz);
// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo07 ( )

/**
  * Metodo08.
  */

int matrixCompare(descritorMatriz m1, descritorMatriz m2) 
{
  if (m1.linhas != m2.linhas || m1.colunas != m2.colunas) 
  {
      return 0;
  }

  for (int i = 0; i < m1.linhas; i++) 
  {
      for (int j = 0; j < m1.colunas; j++) 
      {
          if (m1.referencia[i][j] != m2.referencia[i][j]) 
          {
              return 0;
          }
      }
  }

  return 1;
}

void metodo08( void ) 
{
//Identificar
  printf("\n%s\n", "\n\tMetodo1018");
  char nomeArquivo1[MAX], nomeArquivo2[MAX];
  descritorMatriz matriz1, matriz2;
  int resultado = 0;

  printf("Digite o nome do primeiro arquivo: ");
  scanf("%s", nomeArquivo1);
  getchar();

  printf("Digite o nome do segundo arquivo: ");
  scanf("%s", nomeArquivo2);
  getchar();

  matriz1 = readMatrixFromFile(nomeArquivo1);
  matriz2 = readMatrixFromFile(nomeArquivo2);

  resultado = matrixCompare(matriz1, matriz2);

  if (resultado) 
  {
      printf("\nAs matrizes sao iguais");
  } else 
  {
      printf("\nAs matrizes sao diferentes");
  }

  getchar();
  freeMatrix(matriz1);
  freeMatrix(matriz2);

// Encerrar
  printf("\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo08 ( )

/**
  * Metodo09.
  */

descritorMatriz matrixAdd(descritorMatriz a, int constante, descritorMatriz b) 
{
  descritorMatriz resultado;
  resultado.linhas = 0;
  resultado.colunas = 0;
  resultado.referencia = NULL;

  if (a.linhas == b.linhas && a.colunas == b.colunas) 
  {
      resultado.linhas = a.linhas;
      resultado.colunas = a.colunas;

      resultado.referencia = (int **) malloc(resultado.linhas * sizeof(int *));
      for (int i = 0; i < resultado.linhas; i++) 
      {
          resultado.referencia[i] = (int *) malloc(resultado.colunas * sizeof(int));
      }

      for (int i = 0; i < resultado.linhas; i++) 
      {
          for (int j = 0; j < resultado.colunas; j++) 
          {
              resultado.referencia[i][j] = a.referencia[i][j] + constante * b.referencia[i][j];
          }
      }
  }

  return resultado;
}

void metodo09 ( void )
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1019");
  char nome1[MAX], nome2[MAX];
  int constante = 0;

  printf("\nArquivo da primeira matriz: ");
  scanf("%s", nome1);
  getchar();

  printf("\nArquivo da segunda matriz: ");
  scanf("%s", nome2);
  getchar();

  printf("\nConstante para multiplicar a segunda matriz: ");
  scanf("%d", &constante);
  getchar();

  descritorMatriz m1 = readMatrixFromFile(nome1);
  descritorMatriz m2 = readMatrixFromFile(nome2);
  descritorMatriz resultado = matrixAdd(m1, constante, m2);

  if (resultado.referencia != NULL) 
  {
    printf("\nMatriz resultante:\n");
    mostrarMatriz(resultado);
  } else 
  {
    printf("\nErro: Matrizes com tamanhos incompativeis");
  }
  getchar();
  freeMatrix(m1);
  freeMatrix(m2);
  freeMatrix(resultado);

// encerrar
  printf("%s\n", "\nApertar ENTER para continuar\n");
  getchar( );

 } // fim metodo09 ( )

/**
  * Metodo10.
  */

descritorMatriz matrixProduct(descritorMatriz a, descritorMatriz b) 
{
  descritorMatriz resultado;
  resultado.linhas = 0;
  resultado.colunas = 0;
  resultado.referencia = NULL;

  if (a.colunas != b.linhas) 
  {
    printf("\nErro: Matrizes incompativeis para multiplicacao\n");
    return resultado;
  }

  resultado.linhas = a.linhas;
  resultado.colunas = b.colunas;
  resultado.referencia = (int **) malloc(resultado.linhas * sizeof(int *));

  for (int i = 0; i < resultado.linhas; i++) 
  {
    resultado.referencia[i] = (int *) malloc(resultado.colunas * sizeof(int));
  }

  for (int i = 0; i < resultado.linhas; i++) 
  {
    for (int j = 0; j < resultado.colunas; j++) 
    {
        resultado.referencia[i][j] = 0;
    }
  }

  for (int i = 0; i < a.linhas; i++) 
  {
    for (int j = 0; j < b.colunas; j++) 
    {
        for (int k = 0; k < a.colunas; k++) 
        {
            resultado.referencia[i][j] += a.referencia[i][k] * b.referencia[k][j];
        }
    }
  }

  return resultado;
}

void metodo10( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo1020");
  
  char nome1[MAX], nome2[MAX];
  descritorMatriz m1, m2, produto;

  printf("\nArquivo da primeira matriz: ");
  scanf("%s", nome1);
  getchar();

  printf("\nArquivo da segunda matriz: ");
  scanf("%s", nome2);
  getchar();

  m1 = readMatrixFromFile(nome1);
  m2 = readMatrixFromFile(nome2);
  produto = matrixProduct(m1, m2);

  if (produto.referencia != NULL) {
      printf("\nMatriz resultante:\n");
      mostrarMatriz(produto);
  } else {
      printf("\nNao foi possivel calcular o produto");
  }
  getchar();

  freeMatrix(m1);
  freeMatrix(m2);
  freeMatrix(produto);
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 10 ( )

/**
  * Metodo11.
  */

descritor sortArrayDown(descritor original) 
{
  descritor ordenado;
  ordenado.tamanho = original.tamanho;
  ordenado.referencia = (int *) malloc(ordenado.tamanho * sizeof(int));

  if (ordenado.referencia == NULL) 
  {
    printf("\nErro: Memoria insuficiente");
    ordenado.tamanho = 0;
    return ordenado;
  }

  for (int i = 0; i < original.tamanho; i++) 
  {
    ordenado.referencia[i] = original.referencia[i];
  }

  for (int i = 0; i < ordenado.tamanho - 1; i++) 
  {
      for (int j = 0; j < ordenado.tamanho - 1 - i; j++) 
      {
        if (ordenado.referencia[j] < ordenado.referencia[j + 1]) 
        {
          int temp = ordenado.referencia[j];
          ordenado.referencia[j] = ordenado.referencia[j + 1];
          ordenado.referencia[j + 1] = temp;
        }
      }
  }

  return ordenado;
}


void metodo11( void ) 
{
// Identificar
  printf("\n%s\n", "\n\tMetodo10E1");
  descritor arranjo;
  descritor ordenado;
  char nomeArquivo[MAX];

  printf("Digite o nome do arquivo: ");
  scanf("%s", nomeArquivo);

  arranjo = readArrayFromFile(nomeArquivo);
    
  if (arranjo.referencia != NULL) 
  {
      ordenado = sortArrayDown(arranjo);

      printf("\nArranjo ordenado em ordem decrescente:\n");
      for (int i = 0; i < ordenado.tamanho; i++) 
      {
        printf("%d ", ordenado.referencia[i]);
      }
      printf("\n");

      free(arranjo.referencia);
      free(ordenado.referencia);
  } else {
      printf("\nErro ao ler o arranjo do arquivo");
  }
  getchar();
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 11 ( )

 
/**
  * Metodo12.
  */

bool identityMatrix(descritorMatriz matriz) 
{
  if (matriz.linhas != matriz.colunas) return false;

  for (int i = 0; i < matriz.linhas; i++) 
  {
      for (int j = 0; j < matriz.colunas; j++) 
      {
          if ((i == j && matriz.referencia[i][j] != 1) ||
              (i != j && matriz.referencia[i][j] != 0))   
            {
              return false;
            }
      }
  }
  return true;
}


void metodo12( void ) {
// Identificar
  printf("\n%s\n", "\n\tMetodo10E2");
  descritorMatriz matriz1, matriz2, produto;
  char nome1[MAX], nome2[MAX];

  printf("Digite o nome do primeiro arquivo: ");
  scanf("%s", nome1);
  getchar();

  printf("Digite o nome do segundo arquivo: ");
  scanf("%s", nome2);
  getchar();  

  matriz1 = readMatrixFromFile(nome1);
  matriz2 = readMatrixFromFile(nome2);

  if (matriz1.colunas == matriz2.linhas) {
      produto = matrixProduct(matriz1, matriz2);

      if (identityMatrix(produto)) {
          printf("\nO produto das matrizes resulta em matriz identidade");
      } else {
          printf("\nO produto das matrizes nao resulta em matriz identidade");
      }

      freeMatrix(produto);
  } else 
  {
      printf("\nTamanhos incompativeis para multiplicacao.");
  }

  getchar();
  freeMatrix(matriz1);
  freeMatrix(matriz2);
// Encerrar
  printf("\n\n%s\n", "Apertar ENTER para continuar.");
  getchar();
}// fim metodo 12 ( )

// identificar
 void menuOpcoes ( void ) 
 {
   printf ( "\n" );             // para saltar linha
   printf ( "%s\n", "Exercicio10 - v.0.0 - 13/05/2025"       );
   printf ( "%s\n", "Matricula: 842527 Nome: Gabriel Ferreira Pereira" );

// mostrar opcoes
   printf ( "%s\n", "Opcoes:   "     );
   printf ( "%s\n", " 0 - parar"     );
   printf ( "%s\n", " 1 - metodo 1011" );
   printf ( "%s\n", " 2 - metodo 1012" );
   printf ( "%s\n", " 3 - metodo 1013" );
   printf ( "%s\n", " 4 - metodo 1014" );
   printf ( "%s\n", " 5 - metodo 1015" );
   printf ( "%s\n", " 6 - metodo 1016" );
   printf ( "%s\n", " 7 - metodo 1017" );
   printf ( "%s\n", " 8 - metodo 1018" );
   printf ( "%s\n", " 9 - metodo 1019" );
   printf ( "%s\n", " 10- metodo 1020" );
   printf ( "%s\n", " 11- metodo 10E1" );
   printf ( "%s\n", " 12- metodo 10E2" );
   printf ( "%s\n", "" );        // para saltar linha
 }


// -------------------------- definicao do metodo principal

 int main ( void )
 {
 // definir dados/resultados
    int opcao = 0;

 // repetir ate' desejar parar
    do
    {
      menuOpcoes();
     // ler opcao
        printf ( "%s", "Qual a sua opcao? " );
        scanf  ( "%d", &opcao ); getchar ( );
        printf ( "%d",  opcao );

     // escolher acao
        switch ( opcao )
        {
           case  0:               
                break;
           case  1: metodo01 ( ); 
                break;
           case  2: metodo02 ( ); 
                break;
           case  3: metodo03 ( );
                break;
           case  4: metodo04 ( ); 
                break;
           case  5: metodo05 ( ); 
                break;
           case  6: metodo06 ( ); 
                break;
           case  7: metodo07 ( ); 
                break;
           case  8: metodo08 ( ); 
                break;
           case  9: metodo09 ( ); 
                break;
           case 10: metodo10 ( ); 
                break;
           case 11: metodo11 ( );
                break;
           case 12: metodo12 ( );
                break;
           default: printf ( "\n%s\n\n", "ERRO: Opcao invalida." );
                break;
        } // fim escolher
    }
    while ( opcao != 0 );

 // encerrar execucao
    printf ( "\n%s\n\n", "Apertar ENTER para terminar." );
    getchar( );

    return 0;
 } // end main ( )


/*
----------------------------- documentacao complementar

----------------------------- notas / observacoes / comentarios

----------------------------- previsao de testes

----------------------------- historico

Versao	Data		      Modificacao
  0.1	__/__		      esboco

 ---------------------------- testes

Versao	Teste
  0.1	01. ( OK )	      identificacao de programa

*/