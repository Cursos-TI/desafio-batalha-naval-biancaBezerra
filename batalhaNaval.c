#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINHAS 10
#define COLUNAS 10



int main() {

  srand(time(0));

  int tamanhoNavio = 3;
  int linhaInicialV = rand() % (LINHAS - tamanhoNavio + 1);
  int colunaInicialV = rand() % COLUNAS;
  int linhaInicialH = rand() % LINHAS;
  int colunaInicialH = rand() % (COLUNAS - tamanhoNavio + 1);
  int linhaInicialD1 = rand() % (LINHAS - tamanhoNavio + 1);
  int colunaInicialD1 = rand() % (COLUNAS - tamanhoNavio + 1);
  int linhaInicialD2 = rand() % (LINHAS - tamanhoNavio + 1);
  int colunaInicialD2 = rand() % (COLUNAS - tamanhoNavio + 1) + (tamanhoNavio - 1);

  int tabuleiro[LINHAS][COLUNAS] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
  };

  //POSIÇÃO NAVIO VERTICAL
  if (linhaInicialV + tamanhoNavio <= LINHAS){
    for (int k = 0; k < tamanhoNavio; k++){
      if (tabuleiro[linhaInicialV + k][colunaInicialV] == 0) {
        tabuleiro[linhaInicialV + k][colunaInicialV] = 3;
      }
    }
  }
  
  //POSIÇÃO NAVIO HORIZONTAL
  if (colunaInicialH + tamanhoNavio <= COLUNAS){
      for (int k = 0; k < tamanhoNavio; k++){
        if (tabuleiro[linhaInicialH][colunaInicialH + k] == 0) {
          tabuleiro[linhaInicialH][colunaInicialH + k] = 3;
        }
      }
    }

  //POSIÇÃO NAVIO DIAGONAL ESQ. - DIR.
  if ((linhaInicialD1 + tamanhoNavio <= LINHAS) && (colunaInicialD1 + tamanhoNavio <= COLUNAS)){
    for (int k = 0; k < tamanhoNavio; k++){
      if (tabuleiro[linhaInicialD1 + k][colunaInicialD1 + k] == 0) {
        tabuleiro[linhaInicialD1 + k][colunaInicialD1 + k] = 3;
      }
    }
  }

  //POSIÇÃO NAVIO DIAGONAL DIR. - ESQ.
  if ((colunaInicialD2 + tamanhoNavio <= COLUNAS) && (linhaInicialD2 + tamanhoNavio <= LINHAS)){
    for (int k = 0; k < tamanhoNavio; k++){
      if (tabuleiro[linhaInicialD2 + k][colunaInicialD2 - k] == 0) {
        tabuleiro[linhaInicialD2 + k][colunaInicialD2 - k] = 3;
      }
    }
  }


  printf("\nJOGO BATALHA NAVAL 🚢\n\n");

  for (int i = 0; i < LINHAS; i++){
    for (int j = 0; j < COLUNAS; j++){
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  };


  printf("\nCOORDENADAS DOS NAVIOS 🚢\n\n");

  for (int i = 0; i < LINHAS; i++){
    for (int j = 0; j < COLUNAS; j++){
      if (tabuleiro[i][j] == 3){
        printf("(%d, %d)\n", i, j );
      }
    }
  }

    

    



    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
