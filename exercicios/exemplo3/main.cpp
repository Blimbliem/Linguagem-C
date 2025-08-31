#include <iostream>
#include "Agenda.h"

int main() {
    int opcao;
    Agenda agenda; // Cria o objeto da classe Agenda

    std::cout << "Bem-vindo ao Aplicativo de Agenda!" << std::endl;

    do {
        std::cout << "\nSelecione uma opção:" << std::endl;
        std::cout << "1 - Adicionar evento" << std::endl;
        std::cout << "2 - Visualizar eventos" << std::endl;
        std::cout << "3 - Editar evento" << std::endl;
        std::cout << "4 - Excluir evento" << std::endl;
        std::cout << "5 - Sair" << std::endl;
        std::cin >> opcao;

        switch (opcao) {
            case 1: agenda.adicionarEvento(); break;
            case 2: agenda.visualizarEventos(); break;
            case 3: agenda.editarEvento(); break;
            case 4: agenda.excluirEvento(); break;
            case 5: std::cout << "Encerrando o programa..." << std::endl; break;
            default: std::cout << "Opção inválida." << std::endl; break;
        }
    } while (opcao != 5);

    return 0;
}
