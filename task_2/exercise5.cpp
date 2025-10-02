/*
Exercício 5 — Escalonamento
Use novamente o cálculo de a[i] = x[i]^2 + y[i]^2 + z[i]^2, mas:
a) Execute com schedule(static) e schedule(dynamic, 1000).
b) Compare os tempos em diferentes quantidades de threads (2, 4, 8).
c) Explique em quais situações static e dynamic são mais adequados.
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

    for(int num_threads : {2, 4, 8}) {
        std::cout << "Número de threads: " << num_threads << "\n";

        double start_static = omp_get_wtime();
        #pragma omp parallel for schedule(static) num_threads(num_threads)
        for(int i = 0; i < N; i++){
            a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
        }
        double end_static = omp_get_wtime();
        double time_static = end_static - start_static;

        std::cout << "Tempo com schedule(static): " << time_static << " segundos\n";

        double start_dynamic = omp_get_wtime();
        #pragma omp parallel for schedule(dynamic, 1000) num_threads(num_threads)
        for(int i = 0; i < N; i++){
            a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
        }
        double end_dynamic = omp_get_wtime();
        double time_dynamic = end_dynamic - start_dynamic;

        std::cout << "Tempo com schedule(dynamic, 1000): " << time_dynamic << " segundos\n";
    }

    return 0;
}