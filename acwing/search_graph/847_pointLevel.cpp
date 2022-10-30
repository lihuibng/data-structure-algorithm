#include <iostream>
#include <vector>
#include <queue>
#include <set>

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环。

所有边的长度都是 1，点的编号为 1∼n。

请你求出 1 号点到 n 号点的最短距离，如果从 1 号点无法走到 n 号点，输出 −1。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 a 和 b，表示存在一条从 a 走到 b 的长度为 1 的边。

输出格式
输出一个整数，表示 1 号点到 n 号点的最短距离。

数据范围
1≤n,m≤105
输入样例：
4 5
1 2
2 3
3 4
1 3
1 4
输出样例：
1
*/

int pointLevel(const std::vector<std::set<int>> &arr, std::vector<int> &visited, std::vector<int> &dist, int root, int end)
{
    std::queue<int> q;
    q.push(root);
    dist[root] = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (auto &k : arr[t])
        {
            if (!visited[k])
            {
                if (dist[k] > dist[t] + 1)
                {
                    dist[k] = dist[t] + 1;
                    q.push(k);
                }
            }
        }
    }
    return dist[end];
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<std::set<int>> arr(a, std::set<int>());
    std::vector<int> visited(a, 0);
    std::vector<int> dist(a, INT_MAX);
    for (int i = 0; i < b; i++)
    {
        int k, j;
        std::cin >> k >> j;
        if (k >= 1)
            arr[k - 1].insert(j - 1);
    }
    int ans = pointLevel(arr, visited, dist, 0, a - 1);
    std::cout << (ans == INT_MAX ? -1 : ans) << std::endl;
    return 0;
}