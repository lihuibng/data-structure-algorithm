#include <iostream>
#include <vector>
#include <map>

const int M = 1e9 + 7;

/*
给定 n 个正整数 ai，请你输出这些数的乘积的约数个数，答案对 109+7 取模。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出一个整数，表示所给正整数的乘积的约数个数，答案需对 109+7 取模。

数据范围
1≤n≤100,
1≤ai≤2×109
输入样例：
3
2
6
8
输出样例：
12
*/

long long numOfDivisors(std::vector<int> &arr)
{
    std::map<int, int> res;
    for (auto &m : arr)
    {
        for (int i = 2; i <= m / i; i++)
        {
            while (m % i == 0)
            {
                res[i]++;
                m /= i;
            }
        }
        if (m > 1)
            res[m]++;
    }

    long long p = 1;
    for (auto &k : res)
        p = p * (k.second + 1) % M;
    return p;
}

int main(int argc, char *argv[])
{
    int a = 0;
    std::cin >> a;
    std::vector<int> arr;
    while (a--)
    {
        int b;
        std::cin >> b;
        arr.push_back(b);
    }
    std::cout << numOfDivisors(arr) << std::endl;
    return 0;
}