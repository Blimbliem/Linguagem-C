#include "Conversor.h"

// Converte quilômetros para milhas
float Conversor::kmParaMilhas(float km) {
    return km * 0.621371;
}

// Converte milhas para quilômetros
float Conversor::milhasParaKm(float milhas) {
    return milhas / 0.621371;
}

// Converte metros para pés
float Conversor::metrosParaPe(float metros) {
    return metros * 3.28084;
}

// Converte pés para metros
float Conversor::peParaMetros(float pes) {
    return pes / 3.28084;
}
