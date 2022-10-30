#include <iostream>
#include <vector>
#include <unordered_set>

/*
给定一个二分图，其中左半部包含 n1 个点（编号 1∼n1），右半部包含 n2 个点（编号 1∼n2），二分图共包含 m 条边。

数据保证任意一条边的两个端点都不可能在同一部分中。

请你求出二分图的最大匹配数。

二分图的匹配：给定一个二分图 G，在 G 的一个子图 M 中，M 的边集 {E} 中的任意两条边都不依附于同一个顶点，则称 M 是一个匹配。

二分图的最大匹配：所有匹配中包含边数最多的一组匹配被称为二分图的最大匹配，其边数即为最大匹配数。

输入格式
第一行包含三个整数 n1、 n2 和 m。

接下来 m 行，每行包含两个整数 u 和 v，表示左半部点集中的点 u 和右半部点集中的点 v 之间存在一条边。

输出格式
输出一个整数，表示二分图的最大匹配数。

数据范围
1≤n1,n2≤500,
1≤u≤n1,
1≤v≤n2,
1≤m≤105
输入样例：
2 2 4
1 1
1 2
2 1
2 2
输出样例：
2
*/

bool find(std::vector<std::unordered_set<int>> &graph, std::vector<bool> &st, std::vector<int> &match, int s)
{
    for (auto j : graph[s])
    {
        // cout << s << " " << j << endl;
        if (!st[j])
        {
            st[j] = true;
            if (match[j] == -1 || find(graph, st, match, match[j]))
            {
                match[j] = s;
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    int a, b, c;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b >> c;
    std::vector<std::unordered_set<int>> arr(a + b, std::unordered_set<int>());
    for (int i = 0; i < c; i++)
    {
        int e1, e2;
        std::cin >> e1 >> e2;
        // cout << e1 << " " << e2 << endl;
        arr[e1 - 1].insert(e2 - 1);
    }
    std::vector<int> match(arr.size(), -1);
    std::vector<bool> st(arr.size(), false);
    int res = 0;
    for (int i = 0; i < a; i++)
    {
        if (find(arr, st, match, i))
            res++;
    }
    std::cout << res << std::endl;
    return 0;
}