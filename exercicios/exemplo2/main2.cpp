#include <iostream>
#include "Usuario.h"

int main() {
    int opcao;
    Usuario usuario; // criar um objeto para chamar os métodos

    std::cout << "Bem-vindo ao Sistema de Cadastro!" << std::endl;

    do {
        std::cout << "\nSelecione uma opção:" << std::endl;
        std::cout << "1 - Adicionar usuário" << std::endl;
        std::cout << "2 - Visualizar usuários" << std::endl;
        std::cout << "3 - Editar usuário" << std::endl;
        std::cout << "4 - Excluir usuário" << std::endl;
        std::cout << "5 - Sair" << std::endl;
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                usuario.adicionarUsuario();
                break;
            case 2:
                usuario.visualizarUsuario(); // aqui é no singular
                break;
            case 3:
                usuario.editarUsuario();
                break;
            case 4:
                usuario.excluirUsuario();
                break;
            case 5:
                std::cout << "Encerrando o programa..." << std::endl;
                break;
            default:
                std::cout << "Opção inválida." << std::endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}
