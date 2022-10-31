#include <iostream>
#include <vector>

const int M = 1e9 + 7;

/*
给定 n 组询问，每组询问给定两个整数 a，b，请你输出 Cbamod(109+7) 的值。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一组 a 和 b。

输出格式
共 n 行，每行输出一个询问的解。

数据范围
1≤n≤10000,
1≤b≤a≤2000
输入样例：
3
3 1
5 3
2 2
输出样例：
3
10
1
*/

std::vector<std::vector<int>> getCombinationNumber()
{

    std::vector<std::vector<int>> comb(2010, std::vector<int>(2010, 0));
    for (int i = 0; i <= 2000; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
                comb[i][j] = 1;
            else
            {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % M;
            }
        }
    }
    return comb;
}

int main(int argc, char *argv[])
{
    int b;
    std::cin >> b;
    auto v = getCombinationNumber();
    while (b--)
    {
        int a, c;
        std::cin >> a >> c;
        std::cout << v[a][c] << std::endl;
    }

    return 0;
}