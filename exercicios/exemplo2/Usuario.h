//include guard
#ifndef USUARIO_H
#define USUARIO_H

//biblioteca padrão da linguagem para uso de strings
#include <string>

// classe que irá encapsular os dados e os métodos para manipulação dos usuarios
class Usuario {
   //atributos dentro de uma classe são privados por padrão
   std::string nome;
   int idade;
   std::string email;

    public:
    // construtores
    // inicia o usuario com valor padrão
    Usuario ();
    //inicia o usuário com valores fornecidos (n,i,e)
    Usuario (std::string n, int i, std::string e);


    // getters e setters - metodos para acessar e modificar atributos privados
    void setNome(std::string n);
    std::string getNome() const;

    void setIdade(int i);
    int getIdade () const;

    void setEmail(std::string e);
    std::string getEmail () const;

    // métodos do sistema - métodos que implementam a lógica do sistema.

     void adicionarUsuario();
     void visualizarUsuario();
     void editarUsuario();
     void excluirUsuario();
};

#endif