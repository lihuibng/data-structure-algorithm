#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 impossible。

数据保证不存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 impossible。

数据范围
1≤n,m≤105,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 5
2 3 -3
1 3 4
输出样例：
2
*/

std::string spfa(std::vector<std::map<int, int>> &arr,
                 std::vector<int> &visited,
                 std::vector<int> &dist,
                 int start)
{
    dist[start] = 0;
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        visited[t] = false;
        for (auto &k : arr[t])
        {
            if (k.second + dist[t] < dist[k.first])
            {
                dist[k.first] = k.second + dist[t];

                if (!visited[k.first])
                {
                    q.push(k.first);
                    visited[k.first] = true;
                }
            }
        }
    }

    if (dist[dist.size() - 1] == 0x3f3f3f3f)
        return "impossible";
    return std::to_string(dist[dist.size() - 1]);
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<std::map<int, int>> arr(a, std::map<int, int>());
    std::vector<int> dist(a, 0x3f3f3f3f);
    std::vector<int> visited(a, 0);
    for (int i = 0; i < b; i++)
    {
        int k, j, m;
        std::cin >> k >> j >> m;
        if (arr[k - 1].count(j - 1))
        {
            arr[k - 1][j - 1] = std::min(arr[k - 1][j - 1], m);
        }
        else
        {
            arr[k - 1][j - 1] = m;
        }
    }
    std::string ans = spfa(arr, visited, dist, 0);
    std::cout << ans << std::endl;

    return 0;
}