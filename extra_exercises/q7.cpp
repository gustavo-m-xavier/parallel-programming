#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Letra A
    int numeros[5] = {1, 2, 3, 4, 5};
    int somaArray = 0;

    for (int i = 0; i < 5; i++) {
        somaArray += numeros[i];
    }

    cout << "Soma dos elementos do array: " << somaArray << endl;

    // Letra B
    vector<int> valores = {5, 10, 15};
    valores.push_back(20);
    valores.push_back(25);

    int somaVector = 0;
    for (int i = 0; i < valores.size(); i++) {
        somaVector += valores[i];
    }

    cout << "Tamanho do vector: " << valores.size() << endl;
    cout << "Soma dos elementos do vector: " << somaVector << endl;

    return 0;
}
