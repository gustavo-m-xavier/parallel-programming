#include <iostream>
using namespace std;

int soma(int a);
int soma(int a, int b, int c);

int main()
{
    int number = soma(9);
    int resultado2 = soma(3, 4, 5); 

    cout << "Resultado do número + 1: " << number << endl;
    cout << "Resultado da soma de 3 números: " << resultado2 << endl;

    return 0;
}

int soma(int a){
    return a + 1;
}

int soma(int a, int b, int c) {
    return a + b + c;
}