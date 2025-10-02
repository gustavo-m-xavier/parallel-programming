/*
Exercício 5 — Escalonamento
a) Cálculo de a[i] = x² + y² + z² com schedule(static) e schedule(dynamic, 1000).
b) Comparar com 2, 4 e 8 threads.
c) Explicar diferenças:
   - static → divide as iterações de forma fixa entre as threads (bom quando todas as iterações custam igual).
   - dynamic → as threads pegam blocos de iterações conforme terminam (bom quando as iterações têm custos variáveis).
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

    // Testa para diferentes quantidades de threads
    for(int num_threads : {2, 4, 8}) {
        std::cout << "Número de threads: " << num_threads << "\n";

        // ---- Escalonamento estático ----
        double start_static = omp_get_wtime();
        #pragma omp parallel for schedule(static) num_threads(num_threads)
        for(int i = 0; i < N; i++){
            a[i] = x[i]*x[i] + y[i]*y[i] + z[i]*z[i];
        }
        double end_static = omp_get_wtime();
        double time_static = end_static - start_static;

        std::cout << "Tempo com schedule(static): " << time_static << " segundos\n";

        // ---- Escalonamento dinâmico ----
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
