#include <iostream>
#include "JogoDaVelha.h"

using namespace std;

// Construtor
JogoDaVelha::JogoDaVelha() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = ' ';
}

// Exibir tabuleiro
void JogoDaVelha::exibirTabuleiro() const {
    cout << "  1   2   3" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++) {
            cout << tabuleiro[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "  ---------" << endl;
    }
}

// Verificar vencedor
bool JogoDaVelha::verificarVencedor(char jogador) const {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador)
            return true;
    }
    if ((tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) ||
        (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador))
        return true;

    return false;
}

// Verificar empate
bool JogoDaVelha::verificarEmpate() const {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (tabuleiro[i][j] == ' ')
                return false;
    return true;
}

// Fazer jogada
bool JogoDaVelha::fazerJogada(char jogador, int linha, int coluna) {
    if (linha >= 1 && linha <= 3 && coluna >= 1 && coluna <= 3 && tabuleiro[linha-1][coluna-1] == ' ') {
        tabuleiro[linha-1][coluna-1] = jogador;
        return true;
    }
    return false;
}
