#include <iostream>
using namespace std;

int main() {
    int num1, num2;

    // Letra A
    cout << "Digite o primeiro número inteiro: ";
    cin >> num1;

    cout << "Digite o segundo número inteiro: ";
    cin >> num2;

    int soma = num1 + num2;
    int subtracao = num1 - num2;
    int multiplicacao = num1 * num2;
    int divisaoInteira = num1 / num2;
    double divisaoReal = static_cast<double>(num1) / num2;

    cout << "\nResultados das operações:" << endl;
    cout << "Soma: " << soma << endl;
    cout << "Subtração: " << subtracao << endl;
    cout << "Multiplicação: " << multiplicacao << endl;
    cout << "Divisão inteira: " << divisaoInteira << endl;
    cout << "Divisão real: " << divisaoReal << endl;

    // Letra B
    int maior = (num1 > num2) ? num1 : num2;
    cout << "\nO maior número é: " << maior << endl;

    return 0;
}
