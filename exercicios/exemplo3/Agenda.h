#ifndef AGENDA_H
#define AGENDA_H

#include <string>

class Agenda {
private:
    std::string titulo;
    std::string data;
    std::string hora;
    std::string descricao;

public:
    // Construtor
    Agenda();

    // Métodos do sistema
    void adicionarEvento();
    void visualizarEventos();
    void editarEvento();
    void excluirEvento();
};

#endif
