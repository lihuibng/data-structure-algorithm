#include <iostream>
#include <vector>

/*
给定一个正整数 n，请你求出 1∼n 中质数的个数。

输入格式
共一行，包含整数 n。

输出格式
共一行，包含一个整数，表示 1∼n 中质数的个数。

数据范围
1≤n≤106
输入样例：
8
输出样例：
4
*/

std::vector<int> getPrimes1(int n)
{
    std::vector<int> primes;
    std::vector<bool> st(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes.push_back(i);
        for (int j = i; j <= n; j += i)
        {
            st[j] = true;
        }
    }
    return primes;
}

std::vector<int> getPrimes2(int n)
{
    std::vector<int> primes;
    std::vector<bool> st(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes.push_back(i);
            for (int j = i; j <= n; j += i)
                st[j] = true;
        }
    }
    return primes;
}

std::vector<int> getPrimes(int n)
{
    std::vector<int> primes;
    std::vector<bool> st(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
    return primes;
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a;

    std::cout << getPrimes2(a).size() << std::endl;
    return 0;
}