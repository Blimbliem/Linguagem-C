#include <iostream>
#include <string>

using namespace std;

class calculator {
private:
    int num1;
    int num2;
  

public:
    
    // Construtor
    calculator() {}
    calculator(int number1, int number2) : num1(number1) , num2(number2) {}

    //encapsulando
    // método set 
    void setNum1(int vlr_num1) {
        num1 = vlr_num1;
    }
    void setNum2(int vlr_num2) {
        num2 = vlr_num2;
    }
    // método get p
    int getNum1() const {
        return num1;
    }
    int getNum2() const {
        return num2;
    }

    // Métodos - this referencia o atributo na classe, é como se fosse uma documentação da classe
    int soma(void) { 
        return (this->num1+this->num2);
    }

    int subtracao(void) { 
        return (this->num1-this->num2);
    }

    int multiplicacao(void) { 
        return (this->num1*this->num2);
    }

    int divisao(void){
        int result;
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Divisão por zero não é permitida." << endl;
            result=-1000;
        }
        return result;
    }

    // cin é como se fosse o scanner
    void entranceData(void){
        int aux=-1;
        cout << "Digite o primeiro número: ";
        cin >> aux; setNum1(aux);
        aux=-1;
        cout << "Digite o segundo número: ";
        cin >> aux; setNum2(aux);
    }

    void optionsOperation(void){
        cout << "Selecione o operador:\n";
        cout << "1 - Adição\n";
        cout << "2 - Subtração\n";
        cout << "3 - Multiplicação\n";
        cout << "4 - Divisão\n";
    }

    int selectionOperation(int operation){
        int result;
        switch (operation) {
        case 1:
            result = soma();
            break;
        case 2:
            result = subtracao();
            break;
        case 3:
            result = multiplicacao();
            break;
        case 4:
            
            break;
        default:
            cout << "Operador inválido." << endl;
            result=-1000;
            break;
        }
        return result;
    }

};

