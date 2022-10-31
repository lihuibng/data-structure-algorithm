#include <iostream>

/*
给定 n 组 ai,bi,pi，对于每组数据，求出 abiimodpi 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含三个整数 ai,bi,pi。

输出格式
对于每组数据，输出一个结果，表示 abiimodpi 的值。

每个结果占一行。

数据范围
1≤n≤100000,
1≤ai,bi,pi≤2×109
输入样例：
2
3 2 5
4 3 9
输出样例：
4
1
*/
int quickPower(int a, int n, int m)
{
    if (n == 1)
        return a % m;
    long long t = quickPower(a, n / 2, m) % m;
    if (n % 2 == 1)
    {
        return (a * t % m) * t % m;
    }
    return t * t % m;
}
int main(int argc, char *argv[])
{
    int a;
    std::cin >> a;
    while (a--)
    {
        int b, c, d;
        std::cin >> b >> c >> d;
        std::cout << quickPower(b, c, d) << std::endl;
    }
    return 0;
}