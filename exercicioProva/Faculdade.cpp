#include <iostream>
#include <string>

using namespace std;

class Faculdade{
    private:
    string nome;
    string endereco;
    int ano;

    public:
    Faculdade(){}
    Faculdade(string nome, int ano) : nome(nome), ano(ano){
        this->endereco = "null";
    }

    //setters
    void setNome (string nome){
        this->nome = nome;
    }

    void setEndereco(string endereco){
        this->endereco = endereco;
    }
    void setAno(int ano){
        this->ano = ano;
    }

    //getters
    string getNome(void) const{
        return this -> nome;
    }

    string getEndereco(void) const{
        return this -> endereco;
    }

    int getAno(void) const{
        return this -> ano;
    }

    void Faculdade :: inserir(){
        Faculdade faculdade;
        //pega nome 
        cout << "Digite o nome da faculdade: ";
        cin.ignore();
        getline(cin,faculdade.nome);
        this->setNome(nome);
        }
        //pega endereço

}