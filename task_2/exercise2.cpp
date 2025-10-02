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
#include <cassert>  // para validar se o resultado paralelo == sequencial

int main(){

    const int N = 100;  
    std::vector<int> v(N, 1); // vetor com 100 posições, todas valendo 1

    // ---- Soma sequencial ----
    int soma_seq = 0;
    for(int i = 0; i < N; i++){
        soma_seq += v[i];
    }

    // ---- Soma paralela ----
    int soma_par = 0;

    // A diretiva "parallel for" divide as iterações do loop entre as threads
    // O "reduction(+:soma_par)" faz cada thread calcular sua própria soma parcial
    // e depois combina tudo na variável soma_par de forma correta.
    #pragma omp parallel for reduction(+:soma_par)
    for(int i = 0; i < N; i++){
        soma_par += v[i];
    }

    std::cout << "Soma sequencial: " << soma_seq << "\n";
    std::cout << "Soma paralela: " << soma_par << "\n";

    assert(soma_seq == soma_par);

    return 0;
}
