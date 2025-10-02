/*
Exercício 3 — Expressão Vetorial
Implementar: a[i] = x[i]^2 + y[i]^2 + z[i]^2
a) Versão sequencial.
b) Paralelizar com #pragma omp parallel for schedule(static).
c) Mostrar tempo de execução.
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

    // ---- Versão sequencial ----
    double start_seq = omp_get_wtime(); // marca tempo inicial
    for(int i = 0; i < N; i++){
        // cálculo direto: a[i] = x² + y² + z²
        a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
    }
    double end_seq = omp_get_wtime(); // tempo final
    double time_seq = end_seq - start_seq;

    std::cout << "Tempo sequencial: " << time_seq << " segundos\n";

    // ---- Versão paralela ----
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
