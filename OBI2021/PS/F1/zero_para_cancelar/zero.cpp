#include <iostream>
#include <stack>

int main()
{
    int n, sum = 0;
    std::cin >> n;
    std::stack<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x == 0)
        {
            if (!numbers.empty())
            {
                sum -= numbers.top();
                numbers.pop();
            }
        }
        else
        {
            sum += x;
            numbers.push(x);
        }
    }
    std::cout << sum << std::endl;
    return 0;
}