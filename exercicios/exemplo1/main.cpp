// incluindo a classe
#include "calculator.cpp"
#include <iostream>
#include <string>


using namespace std;

int main() {
    int operation;
    calculator calculadora = calculator(12,34);
    calculadora.optionsOperation();
    cin >> operation;
    operation = calculadora.selectionOperation(operation);
    cout << "Resultado: " << operation << endl;
    cout << calculadora.soma();
    return 0;
}