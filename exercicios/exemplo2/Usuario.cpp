#include "Usuario.h"
#include <iostream>
#include <fstream>

// construtores
Usuario::Usuario() : nome(""), idade(0), email("") {}
Usuario::Usuario(std::string n, int i, std::string e) : nome(n), idade(i), email(e) {}

// getters e setters
void Usuario::setNome(std::string n) { nome = n; }
std::string Usuario::getNome() const { return nome; }

void Usuario::setIdade(int i) { idade = i; }
int Usuario::getIdade() const { return idade; }

void Usuario::setEmail(std::string e) { email = e; }
std::string Usuario::getEmail() const { return email; }

// métodos do sistema
void Usuario::adicionarUsuario() {
    Usuario usuario;

    std::cout << "Digite o nome do usuário: ";
    // cin lê os dados até chegar o espaço em branco
    //utilizamos o cin.ignore para limpar o buffer
    std::cin.ignore();
    //getline lê uma linha inteira de texto incluindo espaços em branco
    std::getline(std::cin, usuario.nome);

    std::cout << "Digite a idade do usuário: ";
    std::cin >> usuario.idade;
    std::cin.ignore(); // evita bug no próximo getline

    std::cout << "Digite o email do usuario: ";
    std::getline(std::cin, usuario.email);

    // (fluxo de saida para arquivos) - serve para escrever em arquivos -> ofstream
    // o padrão do ofstream é sobrescrever o arquivo, para não apagar o que existe utilizamos o std::ios::app
    std::ofstream arquivo("usuarios.txt", std::ios::app);
    if (arquivo.is_open()) {
        arquivo << usuario.nome << "," << usuario.idade << "," << usuario.email << std::endl;
        arquivo.close();
        std::cout << "Usuario adicionado com sucesso." << std::endl;
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}


void Usuario::visualizarUsuario() {
    //ifstream é utilizado para ler arquivos
    std::ifstream arquivo("usuarios.txt");
    // esse método le linha por linha do arquivo
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

void Usuario::editarUsuario() {
    std::string nomeAntigo;
    std::cout << "Digite o nome do usuário que deseja editar: ";
    std::cin.ignore();
    std::getline(std::cin, nomeAntigo);

    //ifstream -> está lendo o arquivo antigo  para encontrar o usuário que será alterado
    std::ifstream arquivoAntigo("usuarios.txt");
    if (arquivoAntigo.is_open()) {
        std::string linha;
        std::string conteudoNovo;

        // cria a variavel do arquivo temporario
        std::string arquivoTemporario = "temp.txt";

        // ofstream cria o arquivo novo baseado no arquivo temporario
        std::ofstream arquivoNovo(arquivoTemporario, std::ios::app);
        if (arquivoNovo.is_open()) {
            //le o arquivo antigo linha por linha para encontrar o que precisa ser alterado
            while (std::getline(arquivoAntigo, linha)) {
                // cria a variavel posição que vai receber o indice em que for encontrado o que será alterado
                size_t posicao = linha.find(nomeAntigo);
                //isso é uma certificação que o nome que deverá ser alterado foi encontrado
                // npos traz um valor padrão "não encontrado"
                if (posicao != std::string::npos) {
                    // se o valor foi encontrado, o usuario devera digitar o novo valor
                    std::cout << "Digite o novo nome do usuário: ";
                    //guarda o novo valor em "conteudo novo"
                    std::getline(std::cin, conteudoNovo);
                    //substitui o conteudo novo na string "linha" onde estava o conteudo "velho"
                    linha.replace(posicao, nomeAntigo.length(), conteudoNovo);
                }
                //salva no novo arquivo a substituição
                arquivoNovo << linha << std::endl;
            }


            arquivoAntigo.close();
            arquivoNovo.close();

            //apaga o arquivo antigo
            std::remove("usuarios.txt");
            //renomeia o arquivo temporário (novo) para o nome original dos arquivos
            std::rename("temp.txt", "usuarios.txt");

            std::cout << "Usuário editado com sucesso." << std::endl;
        } else {
            std::cout << "Erro ao abrir o arquivo temporário." << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo antigo." << std::endl;
    }
}

void Usuario::excluirUsuario() {
    std::string nomeUsuario;
    std::cout << "Digite o nome do usuário que deseja excluir: ";
    std::cin.ignore();
    std::getline(std::cin, nomeUsuario);

    // lendo o arquivo usuarios
    std::ifstream arquivoAntigo("usuarios.txt");
    if (arquivoAntigo.is_open()) {
        std::string linha;
        std::string arquivoTemporario = "temp.txt";

        std::ofstream arquivoNovo(arquivoTemporario, std::ios::app);
        if (arquivoNovo.is_open()) {
            // passa linha por linha do arquivo
            while (std::getline(arquivoAntigo, linha)) {
                //valida se a posição de leitura é igual ao nome do usuario que desejam excluir
                size_t posicao = linha.find(nomeUsuario);
                // se a posição não foi encontrada ele salva a linha no arquivo novo - se for encontrada, ele ignora (não salvando no arquivo novo)
                if (posicao == std::string::npos) {
                    arquivoNovo << linha << std::endl;
                }
            }

            arquivoAntigo.close();
            arquivoNovo.close();

            std::remove("usuarios.txt");
            std::rename("temp.txt", "usuarios.txt");

            std::cout << "Usuário excluído com sucesso." << std::endl;
        } else {
            std::cout << "Erro ao abrir o arquivo temporário." << std::endl;
        }
    } else {
        std::cout << "Erro ao abrir o arquivo antigo." << std::endl;
    }
}
