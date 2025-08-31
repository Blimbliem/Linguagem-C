#ifndef JOGO_DA_VELHA_H
#define JOGO_DA_VELHA_H

class JogoDaVelha {
private:
    char tabuleiro[3][3];

public:
    // Construtor
    JogoDaVelha();

    // Métodos do jogo
    void exibirTabuleiro() const;
    bool verificarVencedor(char jogador) const;
    bool verificarEmpate() const;
    bool fazerJogada(char jogador, int linha, int coluna);
};

#endif
