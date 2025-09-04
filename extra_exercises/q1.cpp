#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Letra A
    string nomeDoAluno = "Gustavo Xavier";

    int idade = 19;
    double altura = 1.82;
    bool aprovado = true;

    cout << "Nome do aluno: " << nomeDoAluno << endl;
    cout << "Idade: " << idade << " anos" << endl;
    cout << "ALtura: " << altura << " metros" << endl;
    cout << "Aprovado: " << (aprovado ? "sim" : "nao") << endl;


    // Letra B
    double pi = 3.14159;
    double raio = 5.0;
    double area = pi * raio * raio;

    cout << "A área do círculo é " << area << " metros quadrado" << endl;

    return 0;
}