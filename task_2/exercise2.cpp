/*
Exercício 2 — Paralelizando um for simples
a) Crie um vetor v de tamanho 100 e inicialize todos os elementos com o valor 1.
b) Escreva um loop sequencial que soma todos os elementos.
c) Refaça o loop com #pragma omp parallel for reduction(+:soma).
d) Compare os resultados e explique por que a diretiva reduction é necessária.
*/

#include <iostream>
#include <omp.h>
#include <vector>
#include <cassert>

int main(){

    const int N = 100;
    std::vector<int> v(N, 1);

    int soma_seq = 0;
    for(int i = 0; i < N; i++){
        soma_seq += v[i];
    }

    int soma_par = 0;

    #pragma omp parallel for reduction(+:soma_par)
    for(int i = 0; i < N; i++){
        soma_par += v[i];
    }

    std::cout << "Soma sequencial: " << soma_seq << "\n";
    std::cout << "Soma paralela: " << soma_par << "\n";

    assert(soma_seq == soma_par);

    return 0;
}