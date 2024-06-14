#include <iostream>

int MAX = 101;

int main()
{
    int msg_r[MAX] = {0}, msg_e[MAX] = {0}, msg_pending[MAX] = {0};
    int n, x, timer = 1;
    bool was_event = 0;
    char c;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> c >> x;
        if (c == 'T')
        {
            timer += x;
            was_event = 0;
        }
        else if (c == 'R')
        {
            timer += was_event;
            was_event = 1;
            msg_r[x] = timer;
            msg_pending[x] = 1;
        }
        else
        {
            timer += was_event;
            was_event = 1;
            msg_e[x] += timer - msg_r[x];
            msg_pending[x] = 0;
        }
    }

    for (int i = 1; i <= 100; i++)
    {
        if (msg_r[i] != 0)
        {
            std::cout << i << " ";
            std::cout << (msg_pending[i] != 0 ? "-1" : std::to_string(msg_e[i])) << std::endl;
        }
    }

    return 0;
}