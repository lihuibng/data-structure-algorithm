#include <iostream>

/*
给定 n 对正整数 ai,bi，对于每对数，求出一组 xi,yi，使其满足 ai×xi+bi×yi=gcd(ai,bi)。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 ai,bi。

输出格式
输出共 n 行，对于每组 ai,bi，求出一组满足条件的 xi,yi，每组结果占一行。

本题答案不唯一，输出任意满足条件的 xi,yi 均可。

数据范围
1≤n≤105,
1≤ai,bi≤2×109
输入样例：
2
4 6
8 18
输出样例：
-1 1
-2 1
*/

int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int main(int argc, char *argv[])
{
    int a;
    std::cin >> a;
    while (a--)
    {
        int b, c;
        std::cin >> b >> c;
        int x, y;
        exgcd(b, c, x, y);
        std::cout << x << " " << y << std::endl;
    }
    return 0;
}