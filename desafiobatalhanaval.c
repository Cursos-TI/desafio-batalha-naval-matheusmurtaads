#include <stdio.h>

#define SIZE 10

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[SIZE][SIZE], const char *nomeTabuleiro) {
    printf("\n%s:\n", nomeTabuleiro);
    printf("   A B C D E F G H I J\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%2d ", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar o navio na horizontal (colunas D, E, F)
void posicionarNavioHorizontal(int tabuleiro[SIZE][SIZE]) {
    int linha = 3; // Linha D
    for (int i = 3; i <= 5; i++) { // Colunas D, E, F
        tabuleiro[linha][i] = 3;
    }
}

// Função para posicionar o navio na vertical (linhas 6, 7, 8)
void posicionarNavioVertical(int tabuleiro[SIZE][SIZE]) {
    int coluna = 7; // Coluna H
    for (int i = 5; i <= 7; i++) { // Linhas 6, 7, 8
        tabuleiro[i][coluna] = 3;
    }
}

// Função para posicionar 2 navios na diagonal
void posicionarNaviosDiagonal(int tabuleiro[SIZE][SIZE]) {
    // Primeiro navio diagonal (da linha 1 para a linha 4, da coluna A para C)
    for (int i = 0; i < 4; i++) {
        tabuleiro[i][i] = 3;
    }
    // Segundo navio diagonal (da linha 3 para a linha 6, da coluna I para G)
    for (int i = 3; i < 7; i++) {
        tabuleiro[i][9 - i] = 3;
    }
}

// Função para desenhar a cruz (representada por 3)
void desenharCruz(int tabuleiro[SIZE][SIZE]) {
    // Cruz centralizada no meio do tabuleiro (linha 5 e coluna 5)
    for (int i = 3; i <= 7; i++) {
        tabuleiro[4][i] = 3; // Linha central, cruz menor
        tabuleiro[i][4] = 3; // Coluna central
    }
}

// Função para desenhar o triângulo pequeno (representado por 1)
void desenharTriangulo(int tabuleiro[SIZE][SIZE]) {
    // Triângulo com base na linha 7 e altura subindo até a linha 3
    for (int i = 5; i >= 3; i--) {
        for (int j = 4 - (5 - i); j <= 5 + (5 - i); j++) {
            tabuleiro[i][j] = 1;
        }
    }
}

// Função para desenhar o triângulo grande com 8 casas (representado por 2)
void desenharTrianguloGrande(int tabuleiro[SIZE][SIZE]) {
    // Triângulo maior, com 8 casas, base na linha 9
    int base = 8;
    int altura = 4;
    for (int i = 6; i < 10; i++) {
        for (int j = base - altura; j <= base + altura; j++) {
            tabuleiro[i][j] = 2;
        }
        base--;
        altura--;
    }
}

// Função para adicionar os números 3 nas colunas específicas (E1, E2, E3, D2, F2)
void adicionarPosicoesEspecificas(int tabuleiro[SIZE][SIZE]) {
    // Colunas E1, E2, E3, D2, F2
    tabuleiro[0][4] = 3; // E1
    tabuleiro[1][4] = 3; // E2
    tabuleiro[2][4] = 3; // E3
    tabuleiro[1][3] = 3; // D2
    tabuleiro[1][5] = 3; // F2
}

int main() {
    int tabuleiroNovato[SIZE][SIZE];
    int tabuleiroAventureiro[SIZE][SIZE];
    int tabuleiroAvancado[SIZE][SIZE];

    // Inicializa todos os tabuleiros
    inicializarTabuleiro(tabuleiroNovato);
    inicializarTabuleiro(tabuleiroAventureiro);
    inicializarTabuleiro(tabuleiroAvancado);

    // Tabuleiro Novato
    printf("DESAFIO BATALHA NAVAL!\n");
    posicionarNavioHorizontal(tabuleiroNovato);  // Colocando navio horizontal
    posicionarNavioVertical(tabuleiroNovato);    // Colocando navio vertical
    exibirTabuleiro(tabuleiroNovato, "Tabuleiro Novato");  // Exibindo o tabuleiro Novato

    // Tabuleiro Aventureiro
    posicionarNavioHorizontal(tabuleiroAventureiro);  // Colocando navio horizontal
    posicionarNavioVertical(tabuleiroAventureiro);    // Colocando navio vertical
    posicionarNaviosDiagonal(tabuleiroAventureiro);   // Colocando os 2 navios na diagonal
    exibirTabuleiro(tabuleiroAventureiro, "Tabuleiro Aventureiro");  // Exibindo o tabuleiro Aventureiro

    // Tabuleiro Avançado
    desenharCruz(tabuleiroAvancado);           // Desenhando a cruz
    desenharTriangulo(tabuleiroAvancado);     // Desenhando o triângulo pequeno
    desenharTrianguloGrande(tabuleiroAvancado); // Desenhando o triângulo grande
    adicionarPosicoesEspecificas(tabuleiroAvancado); // Adicionando números 3 nas colunas específicas
    exibirTabuleiro(tabuleiroAvancado, "Tabuleiro Avançado");  // Exibindo o tabuleiro Avançado

    return 0;
}