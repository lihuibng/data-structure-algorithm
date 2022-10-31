#include <iostream>
#include <vector>

/*
给定 n 个正整数 ai，将每个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 ai。

输出格式
对于每个正整数 ai，按照从小到大的顺序输出其分解质因数后，每个质因数的底数和指数，每个底数和指数占一行。

每个正整数的质因数全部输出完毕后，输出一个空行。

数据范围
1≤n≤100,
2≤ai≤2×109
输入样例：
2
6
8
输出样例：
2 1
3 1

2 3
*/

std::vector<std::vector<int>> prime(int n)
{
    std::vector<std::vector<int>> arr;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            arr.push_back({i, cnt});
        }
    }
    if (n > 1)
        arr.push_back({n, 1});
    return arr;
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a;
    while (a--)
    {
        int i = 0;
        std::cin >> i;
        auto arr = prime(i);
        for (auto v : arr)
        {
            for (auto k : v)
            {
                std::cout << k << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}