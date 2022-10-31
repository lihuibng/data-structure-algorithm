#include <iostream>
#include <vector>
#include <queue>
#include <set>

/*
给定一个 n 个点 m 条边的有向图，点的编号是 1 到 n，图中可能存在重边和自环。

请输出任意一个该有向图的拓扑序列，如果拓扑序列不存在，则输出 −1。

若一个由图中所有点构成的序列 A 满足：对于图中的每条边 (x,y)，x 在 A 中都出现在 y 之前，则称 A 是该图的一个拓扑序列。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 x 和 y，表示存在一条从点 x 到点 y 的有向边 (x,y)。

输出格式
共一行，如果存在拓扑序列，则输出任意一个合法的拓扑序列即可。

否则输出 −1。

数据范围
1≤n,m≤105
输入样例：
3 3
1 2
2 3
1 3
输出样例：
1 2 3
*/

bool topsort(const std::vector<std::set<int>> &arr,
             std::vector<int> &visited,
             std::vector<int> &indegrees,
             std::vector<int> &path,
             std::vector<int> &starts,
             int num)
{
    std::queue<int> q;
    for (auto &k : starts)
    {
        q.push(k);
        visited[k] = true;
    }
    int cnt = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        cnt++;
        path.push_back(t);
        for (auto &k : arr[t])
        {
            if (!visited[k] && --indegrees[k] == 0)
            {
                q.push(k);
                visited[k] = true;
            }
        }
    }
    return cnt == num;
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
    std::vector<int> indegrees(a, 0);
    std::vector<int> starts;
    std::vector<int> path;
    for (int i = 0; i < b; i++)
    {
        int k, j;
        std::cin >> k >> j;
        arr[k - 1].insert(j - 1);
    }
    for (auto &v : arr)
    {
        for (auto &k : v)
        {
            indegrees[k]++;
        }
    }
    for (int j = 0; j < a; j++)
    {
        if (indegrees[j] == 0)
            starts.push_back(j);
    }
    if (starts.size() == 0)
    {
        std::cout << -1 << std::endl;
    }
    else
    {
        bool ret = topsort(arr, visited, indegrees, path, starts, a);
        if (ret)
        {
            for (auto &k : path)
            {
                std::cout << k + 1 << " ";
            }
            std::cout << std::endl;
        }
        else
        {
            std::cout << -1 << std::endl;
        }
    }

    return 0;
}