#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int repetitions;

    std::cout << "Digite a quantidade de equações que deseja calcular:\n";
    std::cin >> repetitions;

    int success_count = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    double total_start = omp_get_wtime();

    #pragma omp parallel for reduction(+:success_count)
    for (int i = 0; i < repetitions; ++i) {
        double start = omp_get_wtime();

        double a = ((std::rand() % 19) + 1) - 9.5;
        double b = (std::rand() % 21) - 10;
        double c = (std::rand() % 21) - 10;

        double delta = 0, raiz_delta = 0, x1 = 0, x2 = 0;

        // Cálculo paralelo com seções aninhadas (mantive sua estrutura)
        #pragma omp parallel shared(a, b, c, delta, raiz_delta, x1, x2)
        {
            #pragma omp single
            {
                delta = b * b - 4 * a * c;
            }

            #pragma omp barrier  // garante que delta foi calculado

            #pragma omp single
            {
                if (delta >= 0)
                    raiz_delta = sqrt(delta);
            }

            #pragma omp barrier  // garante que raiz_delta foi calculada

            #pragma omp single
            {
            if (delta >= 0)
                x1 = (-b + raiz_delta) / (2 * a);
            }
            #pragma omp barrier

            #pragma omp single
            {
                if (delta >= 0)
                 x2 = (-b - raiz_delta) / (2 * a);
            }
            #pragma omp barrier

        }

        double end = omp_get_wtime();
        double duration = end - start;

        #pragma omp critical
        {
            if (delta >= 0) {
                success_count++;
                std::cout << "Thread " << omp_get_thread_num()
                          << " encontrou raízes: x1 = " << x1 << ", x2 = " << x2
                          << " em " << duration << " segundos.\n";
            } else {
                std::cout << "Thread " << omp_get_thread_num()
                          << " encontrou delta negativo em " << duration << " segundos.\n";
            }
        }
    }

    double total_end = omp_get_wtime();
    double total_time = total_end - total_start;

    std::cout << "\nTotal de equações com raízes reais: " << success_count << "\n";
    std::cout << "Tempo total de execução: " << total_time << " segundos.\n";

    return 0;
}
