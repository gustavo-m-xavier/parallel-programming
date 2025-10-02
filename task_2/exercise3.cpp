/*
Exercício 3 — Expressão Vetorial
Implemente a expressão: a[i] = x[i]^2 + y[i]^2 + z[i]^2 para vetores de tamanho 1.000.000.
a) Faça a versão sequencial.
b) Paralelize com #pragma omp parallel for schedule(static).
c) Mostre o tempo total de execução em cada versão.
*/

#include <iostream>
#include <omp.h>
#include <vector>

int main(){

    const int N = 1000000;
    std::vector<double> x(N, 1.0);
    std::vector<double> y(N, 2.0);
    std::vector<double> z(N, 3.0);
    std::vector<double> a(N, 0.0);

    double start_seq = omp_get_wtime();
    for(int i = 0; i < N; i++){
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    }
    double end_seq = omp_get_wtime();
    double time_seq = end_seq - start_seq;

    std::cout << "Tempo sequencial: " << time_seq << " segundos\n";

    double start_par = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for(int i = 0; i < N; i++){
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    }
    double end_par = omp_get_wtime();
    double time_par = end_par - start_par;

    std::cout << "Tempo paralelo: " << time_par << " segundos\n";

    return 0;
}