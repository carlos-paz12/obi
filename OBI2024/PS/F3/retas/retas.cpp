#include <iostream>
#include <vector>

int main()
{
    int n{};
    double x1{}, x2{};
    int in{};
    std::cin >> n >> x1 >> x2;

    double a_s[n];
    double b_s[n];

    for (int i = 0; i < n; i++)
    {
        double a{}, b{};
        std::cin >> a >> b;

        a_s[i] = a;
        b_s[i] = b;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                continue;

            double x = (b_s[j] - b_s[i]) / (a_s[i] - a_s[j]);

            std::cout << x << std::endl;

            if (x >= x1 && x <= x2)
                in++;
        }
    }

    std::cout << in << '\n';

    return 0;
}
