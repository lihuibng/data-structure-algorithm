#include <iostream>
#include <vector>

const int M = 1e9;

/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环，边权可能为负数。

求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

给定一张边带权的无向图 G=(V,E)，其中 V 表示图中点的集合，E 表示图中边的集合，n=|V|，m=|E|。

由 V 中的全部 n 个顶点和 E 中 n−1 条边构成的无向连通子图被称为 G 的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G 的最小生成树。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含三个整数 u,v,w，表示点 u 和点 v 之间存在一条权值为 w 的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500,
1≤m≤105,
图中涉及边的边权的绝对值均不超过 10000。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/

int prim(std::vector<std::vector<int>> &arr,
         std::vector<int> &visited,
         std::vector<int> &dist,
         int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0 && (t == -1 || dist[t] > dist[j]))
            {
                t = j;
            }
        }
        if (i && dist[t] == M)
            return M;
        if (i)
            res += dist[t];
        for (int j = 0; j < n; j++)
        {
            dist[j] = std::min(dist[j], arr[t][j]);
        }

        visited[t] = 1;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<std::vector<int>> arr(a, std::vector<int>(a, M));
    std::vector<int> visited(a, 0);
    std::vector<int> dist(a, M);
    for (int i = 0; i < b; i++)
    {
        int k, j, m;
        std::cin >> k >> j >> m;
        if (arr[k - 1][j - 1] != M)
        {
            arr[k - 1][j - 1] = std::min(arr[k - 1][j - 1], m);
            arr[j - 1][k - 1] = std::min(arr[j - 1][k - 1], m);
        }
        else
        {
            arr[k - 1][j - 1] = m;
            arr[j - 1][k - 1] = m;
        }
    }
    for (int i = 0; i < a; i++)
    {
        arr[i][i] = 0;
    }
    int ans = prim(arr, visited, dist, a);
    if (ans == M)
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << ans << std::endl;
    }
    return 0;
}