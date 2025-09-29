#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Evento {
    private:
       string titulo;
       string data;
       string hora;
       string descricao; 
    
    public:
        Evento() {}
        Evento(string tituloEvent, string dataEvent, string horaEvent, string descrEvent) : titulo(tituloEvent),
         data(dataEvent), hora(horaEvent), descricao(descrEvent) {}

        void setTitulo(string tituloEvent){
            this->titulo=tituloEvent;
        }

        void setData(string dataEvent){
            this->data=dataEvent;
        }

        void setHora(string horaEvent){
            this->hora=horaEvent;
        }
        
        void setDescricao(string descrEvent){
            this->descricao=descrEvent;
        }

        string getTitulo(void) const {
            return (this->titulo);
        }

        string getData(void) const {
            return (this->data);
        }

        string getHora(void) const {
            return (this->hora);
        }

        string getDescricao(void) const {
            return (this->descricao);
        }

        void addEvent(void){
            string auxEvent;

            cout << "Digite o título do evento: ";
            cin.ignore();
            getline(cin, auxEvent); this->setTitulo(auxEvent);

            cout << "Digite a data do evento (dd/mm/aaaa): ";
            getline(cin, auxEvent); this->setData(auxEvent);

            cout << "Digite a hora do evento (hh:mm): ";
            getline(cin, auxEvent); this->setHora(auxEvent);

            cout << "Digite a descrição do evento: ";
            getline(cin, auxEvent); this->setDescricao(auxEvent);

            ofstream arquivo("agenda.txt", ios::app);

            if (arquivo.is_open()) {
                arquivo << this->getTitulo() << "," << this->getData() << "," << this->getHora() << "," << this->getDescricao() << endl;
                arquivo.close();
                cout << "Evento adicionado com sucesso." << endl;
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }

        void showEvents(void){
            ifstream arquivo("agenda.txt");
            if (arquivo.is_open()) {
                string linha;

                while (getline(arquivo, linha)) {
                    cout << linha << endl;
                }
                arquivo.close();
            } else {
                cout << "Erro ao abrir o arquivo." << endl;
            }
        }

        void editEvent(void){
            string tituloAntigo;
            cout << "Digite o título do evento que deseja editar: ";
            cin.ignore();
            getline(cin, tituloAntigo);

            ifstream arquivoAntigo("agenda.txt");

            if (arquivoAntigo.is_open()) {
                string linha;
                string conteudoNovo;
                string arquivoTemporario = "temp.txt";

                ofstream arquivoNovo(arquivoTemporario, ios::app);

                if (arquivoNovo.is_open()) {
                    while (getline(arquivoAntigo, linha)) {
                        size_t posicao = linha.find(tituloAntigo);
                        if (posicao != string::npos) {
                            cout << "Digite o novo título do evento: ";
                            getline(cin, conteudoNovo);
                            linha.replace(posicao, tituloAntigo.length(), conteudoNovo);
                        }
                        arquivoNovo << linha << endl;
                    }
                    arquivoAntigo.close();
                    arquivoNovo.close();
                    remove("agenda.txt");
                    rename("temp.txt", "agenda.txt");
                    cout << "Evento editado com sucesso." << endl;
                } else {
                    cout << "Erro ao abrir o arquivo temporário." << endl;
                }
            } else {
                cout << "Erro ao abrir o arquivo antigo." << endl;
            }
        }

        void deleteEvent(void){
            string tituloEvento;
            cout << "Digite o título do evento que deseja excluir: ";
            cin.ignore();
            getline(cin, tituloEvento);
            ifstream arquivoAntigo("agenda.txt");
            if (arquivoAntigo.is_open()) {
                string linha;
                string arquivoTemporario = "temp.txt";
                ofstream arquivoNovo(arquivoTemporario, ios::app);
                if (arquivoNovo.is_open()) {
                    while (getline(arquivoAntigo, linha)) {
                        size_t posicao = linha.find(tituloEvento);
                        if (posicao == string::npos) {
                            arquivoNovo << linha << endl;
                        }
                    }
                    arquivoAntigo.close();
                    arquivoNovo.close();
                    remove("agenda.txt");
                    rename("temp.txt", "agenda.txt");
                    cout << "Evento excluído com sucesso." << endl;
                } else {
                    cout << "Erro ao abrir o arquivo temporário." << endl;
                }
            } else {
                cout << "Erro ao abrir o arquivo antigo." << endl;
            }
        }

        void showOperations(void){
            int opcao;
            cout << "Bem-vindo ao Aplicativo de Agenda!" << endl;
            do {
                cout << "Selecione uma opção:" << endl;
                cout << "1 - Adicionar evento" << endl;
                cout << "2 - Visualizar eventos" << endl;
                cout << "3 - Editar evento" << endl;
                cout << "4 - Excluir evento" << endl;
                cout << "5 - Sair" << endl;
                cin >> opcao;

                switch (opcao) {
                    case 1:
                    this->addEvent();
                    break;
                case 2:
                    this->showEvents();
                    break;
                case 3:
                    this->editEvent();
                    break;
                case 4:
                    this->deleteEvent();
                    break;
                case 5:
                    cout << "Encerrando o programa..." << endl;
                    break;
                default:
                    cout << "Opção inválida." << endl;
                    break;
                }
            } while (opcao != 5);
        }
};