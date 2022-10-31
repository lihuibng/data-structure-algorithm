#include <iostream>
#include <vector>

/*
给定一个正整数 n，求 1∼n 中每个数的欧拉函数之和。

输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示 1∼n 中每个数的欧拉函数之和。

数据范围
1≤n≤106
输入样例：
6
输出样例：
12
*/
std::vector<int> get_euler(int n)
{

    std::vector<int> euler(n + 1, 0);
    std::vector<bool> st(n + 1, false);
    std::vector<int> primes;
    euler[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes.push_back(i);
            euler[i] = i - 1;
        }
        for (int j = 0; j < primes.size() && primes[j] <= n / i; j++)
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                euler[t] = euler[i] * primes[j];
                break;
            }
            euler[t] = euler[i] * (primes[j] - 1);
        }
    }
    return euler;
}

int main(int argc, char *argv[])
{
    int b;
    std::cin >> b;
    long long res = 0;
    auto v = get_euler(b);
    for (auto &k : v)
        res += k;
    std::cout << res << std::endl;

    return 0;
}