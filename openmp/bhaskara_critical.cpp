#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int repetitions;

    std::cout << "Digite a quantidade de equações que deseja calcular:\n";
    std::cin >> repetitions;

    int success_count = 0;
    // #pragma omp parallel num_threads(1)
    // #pragma omp atomic
    std::ofstream log("tempos_critical.txt");

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    #pragma omp parallel for
    for (int i = 0; i < repetitions; ++i) {
        double start = omp_get_wtime();

        double a = ((std::rand() % 19) + 1) - 9.5;
        double b = (std::rand() % 21) - 10;
        double c = (std::rand() % 21) - 10;

        double delta = 0, raiz_delta = 0, x1 = 0, x2 = 0;

        #pragma omp parallel sections
        {
            #pragma omp section
            {
                #pragma omp critical
                delta = b * b - 4 * a * c;
            }

            #pragma omp section
            {
                #pragma omp critical
                if (delta >= 0)
                    raiz_delta = sqrt(delta);
            }

            #pragma omp section
            {
                #pragma omp critical
                if (delta >= 0)
                    x1 = (-b + raiz_delta) / (2 * a);
            }

            #pragma omp section
            {
                #pragma omp critical
                if (delta >= 0)
                    x2 = (-b - raiz_delta) / (2 * a);
            }
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
                log << "Thread " << omp_get_thread_num()
                    << " levou " << duration << " segundos.\n";
            } else {
                std::cout << "Thread " << omp_get_thread_num()
                          << " encontrou delta negativo em " << duration << " segundos.\n";
                log << "Thread " << omp_get_thread_num()
                    << " encontrou delta negativo em " << duration << " segundos.\n";
            }
        }
    }

    log.close();

    std::cout << "Total de equações com raízes reais: " << success_count << "\n";
    std::cout << "Tempos salvos em 'tempos_critical.txt'\n";
    return 0;
}
