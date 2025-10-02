/*
Exercício 1 — “Hello World” Paralelo
a) Crie uma região paralela com #pragma omp parallel.
b) Cada thread deve imprimir uma mensagem indicando seu número (omp_get_thread_num()) e o total de threads (omp_get_num_threads()).
c) Configure o programa para rodar com 4 threads.
*/

#include <iostream>   
#include <sstream>    
#include <omp.h>      // biblioteca do OpenMP, necessária para paralelismo

int main(){

    // Criando uma região paralela com exatamente 4 threads
    // Cada thread que entrar nessa região vai executar o bloco abaixo
    #pragma omp parallel num_threads(4)
    {
        // "tid" guarda o identificador (número) da thread atual (0, 1, 2, ...)
        int tid = omp_get_thread_num();

        // "tot" guarda o número total de threads ativas nessa região paralela
        int tot = omp_get_num_threads();

        // "oss" é um fluxo de string (como cout, mas grava em string ao invés de tela)
        std::ostringstream oss;

        oss << "Hello, World! This is thread " << tid
            << " of " << tot << "\n";

        // A diretiva "critical" garante que apenas UMA thread por vez
        // vai acessar o cout. Isso evita que as mensagens saiam embaralhadas.
        #pragma omp critical 
            std::cout << oss.str();
    }

}
