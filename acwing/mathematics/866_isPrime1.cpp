#include <iostream>

/*
给定 n 个正整数 ai，判定每个数是否是质数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 ai。

输出格式
共 n 行，其中第 i 行输出第 i 个正整数 ai 是否为质数，是则输出 Yes，否则输出 No。

数据范围
1≤n≤100,
1≤ai≤231−1
输入样例：
2
2
6
输出样例：
Yes
No
*/

bool isPrime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
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
        std::cout << (isPrime(i) ? "Yes" : "No") << std::endl;
    }

    return 0;
}