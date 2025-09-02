#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

// Declaração da função aplicarForma
void aplicarForma(int forma[5][5], int linha, int coluna, int tabuleiro[LINHAS][COLUNAS]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (forma[i][j] == 1 && linha + i < LINHAS && coluna + j < COLUNAS) {
        if (tabuleiro[linha + i][coluna + j] == 3) {
          tabuleiro[linha + i][coluna + j] = 5; // navio + habilidade
        } else {
          tabuleiro[linha + i][coluna + j] = 1; // só habilidade
        }
      }
    }
  }
}

int main() {

  int tamanhoNavio = 3;
  int linhaInicialV = 2;
  int colunaInicialV = 1;
  int linhaInicialH = 5;
  int colunaInicialH = 3;
  int linhaInicialD1 = 0;
  int colunaInicialD1 = 0;
  int linhaInicialD2 = 4;
  int colunaInicialD2 = 7;

  // Definindo posições para cada habilidade
  int coneLinha = 1, coneColuna = 1; // Cone no canto superior esquerdo
  int cruzLinha = 3, cruzColuna = 5; // Cruz no meio
  int octaLinha = 6, octaColuna = 1; // Octaedro no canto inferior esquerdo

  int cone[5][5] = {0};
  
  int cruz[5][5] = {0};
  
  int octaedro[5][5] = {0};

  int tabuleiro[LINHAS][COLUNAS] = {0};

  //HABILIDADES - CONE/CRUZ/OCTAEDRO
  printf("\nCONE 🚢\n\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cone[i][j] = 0;
      if ((i == 1 && j == 2) || (i == 2 && j >= 1 && j <= 3) || (i == 3)) {
        cone[i][j] = 1;
      }
      printf("%d ", cone[i][j]);
    }
    printf("\n");
  }

  printf("\nCRUZ 🚢\n\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cruz[i][j] = 0;
      if ((i >= 0 && j == 2) || (i == 2 && j >=  0 && j <= 5)) {
        cruz[i][j] = 1;
      }
      printf("%d ", cruz[i][j]);
    }
    printf("\n");
  }

  printf("\nOCTAEDRO 🚢\n\n");
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      octaedro[i][j] = 0;
      if ((i == 1 && j == 2) || (i == 2 && j >=  1 && j <= 3) || (i == 3 && j == 2)) {
        octaedro[i][j] = 1;
      }
      printf("%d ", octaedro[i][j]);
    }
    printf("\n");
  }


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

  // APLICAR HABILIDADES EM POSIÇÕES DIFERENTES
  aplicarForma(cone, coneLinha, coneColuna, tabuleiro);
  aplicarForma(cruz, cruzLinha, cruzColuna, tabuleiro);
  aplicarForma(octaedro, octaLinha, octaColuna, tabuleiro);
  
  printf("\nJOGO BATALHA NAVAL 🚢\n\n");
  printf("Legenda: 0 = Vazio, 1 = Habilidade, 3 = Navio, 5 = Navio+Habilidade\n\n");

  for (int i = 0; i < LINHAS; i++){
    for (int j = 0; j < COLUNAS; j++){
      printf("%d ", tabuleiro[i][j]);
    }
    printf("\n");
  };


  printf("\nCOORDENADAS DOS NAVIOS 🚢\n\n");
  for (int i = 0; i < LINHAS; i++){
    for (int j = 0; j < COLUNAS; j++){
      if ((tabuleiro[i][j] == 3) || (tabuleiro[i][j] == 5)){
        printf("(%d, %d)\n", i, j );
      }
    }
  }

    return 0;
}
