#include <iostream>
#include <vector>

/*
给定 n 对正整数 ai,bi，请你求出每对数的最大公约数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数对 ai,bi。

输出格式
输出共 n 行，每行输出一个整数对的最大公约数。

数据范围
1≤n≤105,
1≤ai,bi≤2×109
输入样例：
2
3 6
4 6
输出样例：
3
2
*/
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    int a = 0;
    std::cin >> a;
    std::vector<int> arr;
    while (a--)
    {
        int b, c;
        std::cin >> b >> c;
        std::cout << gcd(b, c) << std::endl;
    }

    return 0;
}