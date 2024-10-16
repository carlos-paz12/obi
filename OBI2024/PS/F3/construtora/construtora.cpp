#include <iostream>
#include <vector>
#include <list>

bool igual(std::vector<int> arr, int n)
{
  for (int i = 1; i < n; i++)
    if (arr[i] != arr[i - 1])
      return false;
  return true;
}

int menor(std::vector<int> arr, int n)
{
  int min = arr[0];
  for (int i = 1; i < n; i++)
  {
    min = std::min(min, arr[i]);
  }
  return min;
}

int seq(std::vector<int> &arr, int n, int s)
{
  int vezes{0};
  bool apareceu = false;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == s)
    {
      arr[i]++;
      if (!apareceu)
      {
        vezes++;
        apareceu = true;
      }
    }
    else
    {
      apareceu = false;
    }
  }
  return vezes;
}

int main(int argc, char *argv[])
{
  int n{}, f{}, m{101};
  bool e = false;
  std::cin >> n;

  std::vector<int> heights;

  for (int i = 0; i < n; i++)
  {
    int a{};
    std::cin >> a;
    heights.push_back(a);
    m = std::min(m, a);
  }

  e = igual(heights, n);
  if (e)
  {
    f = 0;
  }
  else
  {
    while (!e)
    {
      f += seq(heights, n, m);
      m = menor(heights, n);
      e = igual(heights, n);
    }
  }

  std::cout << f << '\n';

  return 0;
}
