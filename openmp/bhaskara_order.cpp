#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <omp.h>

int main() {
    int n;
    std::cout << "Digite a quantidade de equações: ";
    std::cin >> n;

    std::srand(std::time(nullptr));

    std::vector<double> a(n), b(n), c(n);
    std::vector<double> b2(n), quatro_ac(n), delta(n), raiz_delta(n), x1(n), x2(n);
    std::vector<std::vector<double>> tempos(n, std::vector<double>(7, 0.0));

    for (int i = 0; i < n; ++i) {
        a[i] = (std::rand() % 9 + 1);     
        b[i] = (std::rand() % 21 - 10);   
        c[i] = (std::rand() % 21 - 10);   
    }

    double inicio_total = omp_get_wtime(); 

    #pragma omp parallel for ordered
    for (int i = 0; i < n; ++i) {
        for (int etapa = 0; etapa < 7; ++etapa) {
            double inicio_etapa = omp_get_wtime();

            #pragma omp ordered
            {
                switch (etapa) {
                    case 0:
                        b2[i] = b[i] * b[i];
                        break;
                    case 1:
                        quatro_ac[i] = 4 * a[i] * c[i];
                        break;
                    case 2:
                        delta[i] = b2[i] - quatro_ac[i];
                        break;
                    case 3:
                        raiz_delta[i] = (delta[i] >= 0) ? sqrt(delta[i]) : -1;
                        break;
                    case 4:
                        if (delta[i] >= 0)
                            x1[i] = (-b[i] + raiz_delta[i]) / (2 * a[i]);
                        break;
                    case 5:
                        if (delta[i] >= 0)
                            x2[i] = (-b[i] - raiz_delta[i]) / (2 * a[i]);
                        break;
                    case 6:
                        #pragma omp critical
                        {
                            std::cout << "\nEquação " << i + 1 << ": "
                                      << a[i] << "x² + " << b[i] << "x + " << c[i] << " = 0\n";
                            std::cout << "Delta = " << delta[i] << "\n";
                            if (delta[i] >= 0) {
                                std::cout << "Raiz de delta = " << raiz_delta[i] << "\n";
                                std::cout << "x1 = " << x1[i] << ", x2 = " << x2[i] << "\n";
                            } else {
                                std::cout << "Raízes complexas (delta < 0)\n";
                            }

                            std::cout << "Tempos por etapa (em segundos):\n";
                            for (int t = 0; t < 6; ++t) {
                                std::cout << "  Etapa " << t << ": " << tempos[i][t] << "s\n";
                            }
                        }
                        break;
                }
            }

            double fim_etapa = omp_get_wtime();
            tempos[i][etapa] = fim_etapa - inicio_etapa;
        }
    }

    double fim_total = omp_get_wtime();  

    std::cout << "\nTempo total de execução: " << (fim_total - inicio_total) << " segundos\n";

    return 0;
}
