#include <iostream>
using namespace std;

int main() {
    // Letra A
    int x = 10;

    int* ptr = &x;
    *ptr = *ptr * 2; 

    int& ref = x;
    ref = ref * 3; 

    cout << "Valor final de x (dobrado e depois triplicado): " << x << endl;

    // Letra B
    int* p = new int(42); 

    cout << "Valor armazenado no ponteiro dinâmico: " << *p << endl;

    delete p; 
    p = nullptr;

    return 0;
}
