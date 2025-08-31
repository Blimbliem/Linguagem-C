#ifndef CONVERSOR_H
#define CONVERSOR_H

class Conversor {
public:
    // Construtor
    Conversor() {}

    // Métodos de conversão
    float kmParaMilhas(float km);
    float milhasParaKm(float milhas);
    float metrosParaPe(float metros);
    float peParaMetros(float pes);
};

#endif
