#include <iostream>
#include <string>
using namespace std;

int main()
{

    // Letra A
    string firstName;
    cout << "Enter your first name: ";
    cin >> firstName;

    int age;
    cout << "Enter your age: ";
    cin >> age;

    cout << "Olá, " << firstName << "! Você tem " << age << " anos." << endl;

    cin.ignore();

    // Letra B
    string fullName;
    cout << "Enter your full name: ";
    getline(cin, fullName);

    cout << "Nome completo: " << fullName << endl;

    return 0;
}