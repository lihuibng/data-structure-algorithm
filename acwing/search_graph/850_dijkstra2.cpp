#include <iostream>
#include <vector>
#include <map>
#include <queue>

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环，所有边权均为非负值。

请你求出 1 号点到 n 号点的最短距离，如果无法从 1 号点走到 n 号点，则输出 −1。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

如果路径不存在，则输出 −1。

数据范围
1≤n,m≤1.5×105,
图中涉及边长均不小于 0，且不超过 10000。
数据保证：如果最短路存在，则最短路的长度不超过 109。

输入样例：
3 3
1 2 2
2 3 1
1 3 4
输出样例：
3
*/

int dijkstra2(std::vector<std::map<int, int>> &arr,
              std::vector<int> &visited,
              std::vector<int> &dist,
              int start,
              int end)
{
    dist[start] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    pq.push({0, start});
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int p = t.second, dis = t.first;
        if (visited[p])
            continue;
        visited[p] = true;
        for (auto &k : arr[p])
        {
            if (dist[k.first] > dis + k.second)
            {
                dist[k.first] = dis + k.second;
                pq.push({dist[k.first], k.first});
                // visited[k.first] = true;
            }
        }
    }
    if (dist[end] == INT_MAX)
        return -1;
    return dist[end];
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<std::map<int, int>> arr(a, std::map<int, int>());
    std::vector<int> visited(a, 0);
    std::vector<int> dist(a, INT_MAX);
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
    int ans = dijkstra2(arr, visited, dist, 0, a - 1);
    std::cout << ans << std::endl;
    return 0;
}