#include <iostream>
#include "Conversor.h"

using namespace std;

int main() {
    Conversor conversor;
    int opcao;
    float valor;

    cout << "Bem-vindo ao Conversor de Unidades!" << endl;

    do {
        cout << "\nSelecione uma opção:" << endl;
        cout << "1 - Converter quilômetros para milhas" << endl;
        cout << "2 - Converter milhas para quilômetros" << endl;
        cout << "3 - Converter metros para pés" << endl;
        cout << "4 - Converter pés para metros" << endl;
        cout << "5 - Sair" << endl;
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite o valor em quilômetros: ";
                cin >> valor;
                cout << valor << " km = " << conversor.kmParaMilhas(valor) << " milha(s)." << endl;
                break;
            case 2:
                cout << "Digite o valor em milhas: ";
                cin >> valor;
                cout << valor << " milha(s) = " << conversor.milhasParaKm(valor) << " km." << endl;
                break;
            case 3:
                cout << "Digite o valor em metros: ";
                cin >> valor;
                cout << valor << " m = " << conversor.metrosParaPe(valor) << " pé(s)." << endl;
                break;
            case 4:
                cout << "Digite o valor em pés: ";
                cin >> valor;
                cout << valor << " pé(s) = " << conversor.peParaMetros(valor) << " m." << endl;
                break;
            case 5:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida." << endl;
                break;
        }
    } while (opcao != 5);

    return 0;
}
