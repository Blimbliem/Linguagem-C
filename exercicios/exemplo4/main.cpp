#include <iostream>
#include "JogoDaVelha.h"

using namespace std;

int main() {
    JogoDaVelha jogo;
    char jogadorAtual = 'X';
    int linha, coluna;

    cout << "Bem-vindo ao Jogo da Velha!" << endl;

    do {
        jogo.exibirTabuleiro();

        cout << "Jogador " << jogadorAtual << ", faça sua jogada." << endl;
        cout << "Digite a linha (1-3): ";
        cin >> linha;
        cout << "Digite a coluna (1-3): ";
        cin >> coluna;

        if (jogo.fazerJogada(jogadorAtual, linha, coluna)) {
            if (jogo.verificarVencedor(jogadorAtual)) {
                jogo.exibirTabuleiro();
                cout << "Jogador " << jogadorAtual << " venceu o jogo!" << endl;
                break;
            } else if (jogo.verificarEmpate()) {
                jogo.exibirTabuleiro();
                cout << "O jogo terminou em empate!" << endl;
                break;
            } else {
                jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Jogada inválida. Tente novamente." << endl;
        }
    } while (true);

    return 0;
}
