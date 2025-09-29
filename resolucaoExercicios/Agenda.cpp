#include <iostream>
#include <string>

using namespace std;

class Agenda{
    private:
        string titulo;
        string data;
        string hora;
        string descricao;

    public:

    Agenda(){}
    Agenda(string tituloAgend, string dataAgend, string horaAgend, string descricaoAgend) : titulo(tituloAgend), data(dataAgend), hora(horaAgend), descricao(descricaoAgend);

    void setTitulo(string tituloAgend){
        this ->titulo = tituloAgend;
    }
    void setData(string dataAgend){
        this ->data = dataAgend;
    }
    void setHora(string horaAgend){
        this ->hora = horaAgend;
    }
    void setDescricao(string descricaoAgend){
        this ->descricao = descricaoAgend;    
    }

    string getTitulo(void) const{
        return(this->titulo);
    } 
    string getData(void) const{
        return(this->data);
    }
    
    string getHora(void) const{
        return(this->hora);
    }
    
    string getDescricao(void) const{
        return(this->descricao;
    }

}