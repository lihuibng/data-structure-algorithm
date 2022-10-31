#include <iostream>
#include <vector>

/*
给定 n 个正整数 ai，请你求出每个数的欧拉函数。

欧拉函数的定义
1∼N 中与 N 互质的数的个数被称为欧拉函数，记为 ϕ(N)。
若在算数基本定理中，N=pa11pa22…pamm，则：
ϕ(N) = N×p1−1p1×p2−1p2×…×pm−1pm
输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个正整数 ai。

输出格式
输出共 n 行，每行输出一个正整数 ai 的欧拉函数。

数据范围
1≤n≤100,
1≤ai≤2×109
输入样例：
3
3
6
8
输出样例：
2
2
4
*/
int getEuler(int n)
{
    int res = n;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        res = res / n * (n - 1);

    return res;
}

int main(int argc, char *argv[])
{
    int a = 0;
    std::cin >> a;
    while (a--)
    {
        int b;
        std::cin >> b;
        std::cout << getEuler(b) << std::endl;
    }

    return 0;
}