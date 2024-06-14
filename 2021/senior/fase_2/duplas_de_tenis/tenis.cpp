#include <iostream>

int main()
{
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;

    int bigger = std::max(std::max(a, b), std::max(c, d));
    int smaller = std::min(std::min(a, b), std::min(c, d));
    int diff = ((bigger + smaller) - ((a + b + c + d) - (bigger + smaller)));

    std::cout << diff << std::endl;

    return 0;
}