#include <iostream>

/*
给定 n 组 ai,pi，其中 pi 是质数，求 ai 模 pi 的乘法逆元，若逆元不存在则输出 impossible。

注意：请返回在 0∼p−1 之间的逆元。

乘法逆元的定义
若整数 b，m 互质，并且对于任意的整数 a，如果满足 b|a，则存在一个整数 x，使得 a/b≡a×x(modm)，则称 x 为 b 的模 m 乘法逆元，记为 b−1(modm)。
b 存在乘法逆元的充要条件是 b 与模数 m 互质。当模数 m 为质数时，bm−2 即为 b 的乘法逆元。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个数组 ai,pi，数据保证 pi 是质数。

输出格式
输出共 n 行，每组数据输出一个结果，每个结果占一行。

若 ai 模 pi 的乘法逆元存在，则输出一个整数，表示逆元，否则输出 impossible。

数据范围
1≤n≤105,
1≤ai,pi≤2∗109
输入样例：
3
4 3
8 5
6 3
输出样例：
1
2
impossible
*/

long long getInverseElement(int a, int n, int m)
{
    long long res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % m;
        a = a * (long long)a % m;
        n >>= 1;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int a;
    std::cin >> a;
    while (a--)
    {
        int b, c;
        std::cin >> b >> c;
        if (b % c != 0)
        {
            std::cout << getInverseElement(b, c - 2, c) << std::endl;
        }
        else
        {
            std::cout << "impossible" << std::endl;
        }
    }
    return 0;
}