/*
Exercício 4 — Medindo tempo por thread
a) Medir tempo total de execução.
b) Medir tempo gasto por cada thread.
c) Mostrar quantas threads foram utilizadas.
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

    double start_total = omp_get_wtime(); // tempo total começa aqui

    // Região paralela: várias threads vão entrar aqui
    #pragma omp parallel 
    {
        int tid = omp_get_thread_num();   // id da thread
        int tot = omp_get_num_threads();  // número total de threads

        double start_thread = omp_get_wtime(); // tempo inicial da thread

        // Distribui as iterações entre as threads
        #pragma omp for schedule(static)
        for(int i = 0; i < N; i++){
            a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
        }

        double end_thread = omp_get_wtime();
        double time_thread = end_thread - start_thread;

        // "critical" garante que só uma thread por vez imprime no console
        #pragma omp critical
        {
            std::cout << "Thread " << tid << " de " << tot 
                      << " levou " << time_thread << " segundos\n";
        }
    }

    double end_total = omp_get_wtime();
    double time_total = end_total - start_total;

    std::cout << "Tempo total: " << time_total << " segundos\n";

    return 0;
}
