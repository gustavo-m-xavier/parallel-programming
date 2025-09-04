#include <iostream>
#include <string>
using namespace std;

struct Aluno {
    string nome;
    int idade;
};

class ContaBancaria {
private:
    double saldo;

public:
    ContaBancaria() {
        saldo = 0.0;
    }

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
            cout << "Depósito de R$" << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Valor inválido para depósito." << endl;
        }
    }

    void sacar(double valor) {
        if (valor > 0 && valor <= saldo) {
            saldo -= valor;
            cout << "Saque de R$" << valor << " realizado com sucesso." << endl;
        } else {
            cout << "Saque inválido ou saldo insuficiente." << endl;
        }
    }

    void imprimir() const {
        cout << "Saldo atual: R$" << saldo << endl;
    }
};

int main() {
    // Letra A
    Aluno aluno;

    cout << "Digite o nome do aluno: ";
    getline(cin, aluno.nome);

    cout << "Digite a idade do aluno: ";
    cin >> aluno.idade;

    cout << "\nDados do aluno:" << endl;
    cout << "Nome: " << aluno.nome << endl;
    cout << "Idade: " << aluno.idade << " anos" << endl;

    // Letra B
    ContaBancaria conta;

    conta.depositar(100.0);
    conta.sacar(30.0);
    conta.imprimir();

    return 0;
}
