#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

/**
 * OBI2023
 * Nível Senior
 * Fase 3
 * Questão: Oficina Mecânica
 */
int main(int argc, char const *argv[])
{
    /**
     * n: Número de carros
     * m: Número de mecânicos
     */
    int n{}, m{};
    std::cin >> n >> m;

    /**
     * t: Array que armazena o tempo base de conserto de cada carro
     */
    int t[n];
    for (int i = 0; i < n; i++)
    {
        int x{};
        std::cin >> x;

        t[i] = x;
    }

    /**
     * f: Array que armazena o fator de trabalho de cada mecânico
     */
    int f[m];
    for (int j = 0; j < m; j++)
    {
        int y{};
        std::cin >> y;

        f[j] = y;
    }

    /**
     * Ordena os tempos de conserto dos carros em ordem crescente (ASC).
     */
    std::sort(t, t + n);
    /**
     * Ordena os fatores de trabalho dos mecânicos em ordem decrescente (DESC).
     * Isso garante que os mecânicos mais eficientes atendam primeiro.
     */
    std::sort(f, f + m, std::greater<int>());

    /**
     * pqueue: Fila de prioridade para gerenciar o tempo em que cada mecânico está livre.
     * Utiliza uma min-heap para sempre acessar o mecânico disponível mais rapidamente.
     */
    std::priority_queue<int, std::vector<int>, std::greater<int>> pqueue;

    /**
     * Inicializa a fila com todos os mecânicos livres (tempo 0).
     * Cada mecânico começa sem tempo de espera.
     */
    for (int k = 0; k < m; k++)
        pqueue.push(0);

    /**
     * twt: Tempo de espera total acumulado (total_wait_time).
     */
    int twt{};

    /**
     * Processa cada carro, atribuindo a um mecânico disponível.
     */
    for (int i = 0; i < n; i++)
    {
        /**
         * Recupera o tempo do mecânico mais livre (menor tempo na fila).
         */
        int ct = pqueue.top();

        /**
         * Adiciona o tempo de espera do carro atual ao total.
         * Esse tempo é o tempo que o carro teve que esperar até ser atendido.
         */
        twt += ct;

        /**
         * Atualiza o tempo do mecânico após consertar o carro atual.
         */
        // Remove o mecânico que foi utilizado.
        pqueue.pop();
        // Calcula o novo tempo do mecânico: tempo atual + (tempo do carro * fator do mecânico).
        //
        // f[i % m] permite que, se houver mais carros do que mecânicos,
        // os fatores dos mecânicos sejam reutilizados ciclicamente.
        pqueue.push(ct + (t[i] * f[i % m]));
    }

    std::cout << twt << std::endl;

    return 0;
}
