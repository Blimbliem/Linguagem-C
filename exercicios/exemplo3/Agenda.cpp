#include "Agenda.h"
#include <iostream>
#include <fstream>

// criando um evento com informações vazias (inicializando)
Agenda::Agenda() : titulo(""), data(""), hora(""), descricao("") {}

// Adicionar evento
void Agenda::adicionarEvento() {
    std::cout << "Digite o título do evento: ";
    std::cin.ignore();
    std::getline(std::cin, titulo);

    std::cout << "Digite a data do evento (dd/mm/aaaa): ";
    std::getline(std::cin, data);

    std::cout << "Digite a hora do evento (hh:mm): ";
    std::getline(std::cin, hora);

    std::cout << "Digite a descrição do evento: ";
    std::getline(std::cin, descricao);

    std::ofstream arquivo("agenda.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << titulo << "," << data << "," << hora << "," << descricao << std::endl;
        arquivo.close();
        std::cout << "Evento adicionado com sucesso." << std::endl;
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

// Visualizar eventos
void Agenda::visualizarEventos() {
    std::ifstream arquivo("agenda.txt");
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

// Editar evento
void Agenda::editarEvento() {
    std::string tituloAntigo;
    std::cout << "Digite o título do evento que deseja editar: ";
    std::cin.ignore();
    std::getline(std::cin, tituloAntigo);

    std::ifstream arquivoAntigo("agenda.txt");
    if (!arquivoAntigo.is_open()) {
        std::cout << "Erro ao abrir o arquivo antigo." << std::endl;
        return;
    }

    std::ofstream arquivoNovo("temp.txt", std::ios::app);
    if (!arquivoNovo.is_open()) {
        std::cout << "Erro ao abrir o arquivo temporário." << std::endl;
        return;
    }

    std::string linha, conteudoNovo;
    while (std::getline(arquivoAntigo, linha)) {
        size_t posicao = linha.find(tituloAntigo);
        if (posicao != std::string::npos) {
            std::cout << "Digite o novo título do evento: ";
            std::getline(std::cin, conteudoNovo);
            linha.replace(posicao, tituloAntigo.length(), conteudoNovo);
        }
        arquivoNovo << linha << std::endl;
    }

    arquivoAntigo.close();
    arquivoNovo.close();

    std::remove("agenda.txt");
    std::rename("temp.txt", "agenda.txt");

    std::cout << "Evento editado com sucesso." << std::endl;
}

// Excluir evento
void Agenda::excluirEvento() {
    std::string tituloEvento;
    std::cout << "Digite o título do evento que deseja excluir: ";
    std::cin.ignore();
    std::getline(std::cin, tituloEvento);

    std::ifstream arquivoAntigo("agenda.txt");
    if (!arquivoAntigo.is_open()) {
        std::cout << "Erro ao abrir o arquivo antigo." << std::endl;
        return;
    }

    std::ofstream arquivoNovo("temp.txt", std::ios::app);
    if (!arquivoNovo.is_open()) {
        std::cout << "Erro ao abrir o arquivo temporário." << std::endl;
        return;
    }

    std::string linha;
    while (std::getline(arquivoAntigo, linha)) {
        if (linha.find(tituloEvento) == std::string::npos) {
            arquivoNovo << linha << std::endl;
        }
    }

    arquivoAntigo.close();
    arquivoNovo.close();

    std::remove("agenda.txt");
    std::rename("temp.txt", "agenda.txt");

    std::cout << "Evento excluído com sucesso." << std::endl;
}
