#include <iostream>
using namespace std;

int main() {
    // Letra A
    cout << "a) Números ímpares de 1 a 20:" << endl;
    for (int i = 1; i <= 20; i++) {
        if (i % 2 != 0) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Letra B
    cout << "\nb) Contador regressivo de 10 até 0:" << endl;
    int contador = 10;
    while (contador >= 0) {
        cout << contador << " ";
        contador--;
    }
    cout << endl;

    // Letra C
    int opcao;
    do {
        cout << "\nMenu:" << endl;
        cout << "1 - Opção 1" << endl;
        cout << "2 - Opção 2" << endl;
        cout << "0 - Sair" << endl;
        cout << "Digite sua opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Você escolheu a Opção 1." << endl;
                break;
            case 2:
                cout << "Você escolheu a Opção 2." << endl;
                break;
            case 0:
                cout << "Encerrando o programa..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
