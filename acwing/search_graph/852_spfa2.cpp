#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你判断图中是否存在负权回路。

输入格式
第一行包含整数 n 和 m。

接下来 m 行每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

输出格式
如果图中存在负权回路，则输出 Yes，否则输出 No。

数据范围
1≤n≤2000,
1≤m≤10000,
图中涉及边长绝对值均不超过 10000。

输入样例：
3 3
1 2 -1
2 3 4
3 1 -4
输出样例：
Yes
*/
bool spfa(std::vector<std::unordered_map<int, int>> &arr,
          std::vector<int> &visited,
          std::vector<int> &dist,
          std::vector<int> &cnt,
          std::vector<int> &starts)
{
    dist[0] = 0;
    std::queue<int> q;
    for (int i = 0; i < starts.size(); i++)
    {
        q.push(starts[i]);
        visited[starts[i]] = true;
    }
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
                cnt[k.first] = cnt[t] + 1;
                if (cnt[k.first] >= dist.size())
                    return true;
                if (!visited[k.first])
                {
                    q.push(k.first);
                    visited[k.first] = true;
                }
            }
        }
    }

    return false;
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<std::unordered_map<int, int>> arr(a, std::unordered_map<int, int>());
    std::vector<int> dist(a, 0x3f3f3f3f);
    std::vector<int> visited(a, 0);
    std::vector<int> cnt(a, 0);
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
    std::vector<int> starts(a, 0);
    for (int i = 0; i < a; i++)
    {
        starts[i] = i;
    }
    bool existed = spfa(arr, visited, dist, cnt, starts);
    if (existed)
    {
        std::cout << "Yes" << std::endl;
    }
    else
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}