#include <iostream>

int main()
{
    int c = 0;
    for (int i = 0; i < 6; i++)
    {
        char input;
        std::cin >> input;
        c += (input == 'V' ? 1 : 0);
    }
    
    switch (c)
    {
    case 6:
    case 5:
        std::cout << 1 << std::endl;
        break;
    case 4:
    case 3:
        std::cout << 2 << std::endl;
        break;
    case 2:
    case 1:
        std::cout << 3 << std::endl;
        break;
    default:
        std::cout << -1 << std::endl;
        break;
    }

    return 0;
}