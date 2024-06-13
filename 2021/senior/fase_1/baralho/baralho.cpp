#include <iostream>

int MAX_QUANT_CARD = 13;
int MAX_SUM_CARD = 91;

bool has_duplicate(int size, int numbers[])
{
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if (numbers[i] == numbers[j])
                return true;
    return false;
}

void verify(int size, int sum, int numbers[])
{
    if (has_duplicate(size, numbers))
        std::cout << "erro";
    else if (size == MAX_QUANT_CARD && sum == MAX_SUM_CARD)
        std::cout << 0;
    else
        std::cout << MAX_QUANT_CARD - size;
    std::cout << std::endl;
}

int main()
{
    std::string input;
    std::cin >> input;

    int c_size = 0, e_size = 0, u_size = 0, p_size = 0;
    int c_sum = 0, e_sum = 0, u_sum = 0, p_sum = 0;
    int c[MAX_QUANT_CARD], e[MAX_QUANT_CARD], u[MAX_QUANT_CARD], p[MAX_QUANT_CARD];

    for (int i = 0; i < input.length(); i += 3)
    {
        std::string card = input.substr(i, 3);
        char suit = card.at(2);
        int number = std::stoi(card.substr(0, 2));
        switch (suit)
        {
        case 'C':
            c_sum += number;
            c[c_size++] = number;
            break;
        case 'E':
            e_sum += number;
            e[e_size++] = number;
            break;
        case 'U':
            u_sum += number;
            u[u_size++] = number;
            break;
        default:
            p_sum += number;
            p[p_size++] = number;
            break;
        }
    }

    verify(c_size, c_sum, c);
    verify(e_size, e_sum, e);
    verify(u_size, u_sum, u);
    verify(p_size, p_sum, p);

    return 0;
}