#include <iostream>
#include <vector>
const int M = 1e9;

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，边权可能为负数。

再给定 k 个询问，每个询问包含两个整数 x 和 y，表示查询从点 x 到点 y 的最短距离，如果路径不存在，则输出 impossible。

数据保证图中不存在负权回路。

输入格式
第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

接下来 k 行，每行包含两个整数 x,y，表示询问点 x 到点 y 的最短距离。

输出格式
共 k 行，每行输出一个整数，表示询问的结果，若询问两点间不存在路径，则输出 impossible。

数据范围
1≤n≤200,
1≤k≤n2
1≤m≤20000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3 2
1 2 1
2 3 2
1 3 1
2 1
1 3
输出样例：
impossible
1
*/

void floyd(std::vector<std::vector<int>> &arr, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = std::min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int a, b, c;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b >> c;
    std::vector<std::vector<int>> arr(a, std::vector<int>(a, M));
    for (int i = 0; i < b; i++)
    {
        int k, j, m;
        std::cin >> k >> j >> m;
        // cout << k << " " << j << " " << m << endl;
        if (arr[k - 1][j - 1] != M)
        {
            arr[k - 1][j - 1] = std::min(arr[k - 1][j - 1], m);
        }
        else
        {
            arr[k - 1][j - 1] = m;
        }
    }
    for (int i = 0; i < a; i++)
    {
        arr[i][i] = 0;
    }
    floyd(arr, a);
    while (c--)
    {
        int i, j;
        std::cin >> i >> j;
        int t = arr[i - 1][j - 1];
        if (t > M / 2)
            std::cout << "impossible" << std::endl;
        else
            std::cout << t << std::endl;
    }

    return 0;
}