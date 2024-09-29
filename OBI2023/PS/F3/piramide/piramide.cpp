#include <iostream>

/**
 * OBI2023
 * Nível Senior
 * Fase 3
 * Questão: Pirâmide
 */
int main(int argc, char const *argv[])
{
    int max{}, sum{};

    /**
     * Lendo entrada
     */
    for (int i = 0; i < 6; i++)
    {
        int a{};
        std::cin >> a;

        max = std::max(max, a); // Identificar maior elemento
        sum += a; // Somatório de todos os elementos
    }

    sum -= max; // Subtrair o maior elemento do somatário

    char res = 'N';
    /**
     * Para pirâmide ficar equilibrada, o maior valor sempre será
     * o do topo. Nisso, todos os demais valores devem ser distribuidos
     * nas demais fileiras de modo que cada fileira tenha um valor igual
     * ao máximo.
     */
    if (sum / 2 == max)
        res = 'S';

    std::cout << res << '\n';

    return 0;
}