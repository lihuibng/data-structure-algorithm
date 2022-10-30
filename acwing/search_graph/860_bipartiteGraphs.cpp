#include <iostream>
#include <vector>

/*
给定一个 n 个点 m 条边的无向图，图中可能存在重边和自环。

请你判断这个图是否是二分图。

输入格式
第一行包含两个整数 n 和 m。

接下来 m 行，每行包含两个整数 u 和 v，表示点 u 和点 v 之间存在一条边。

输出格式
如果给定图是二分图，则输出 Yes，否则输出 No。

数据范围
1≤n,m≤105
输入样例：
4 4
1 3
1 4
2 3
2 4
输出样例：
Yes
*/

bool bipartiteGraph(std::vector<std::vector<int>> &graph, std::vector<int> &color, int s, int c)
{
    color[s] = c;
    for (auto &i : graph[s])
    {
        if (color[i] == 0)
        {
            if (!bipartiteGraph(graph, color, i, 3 - c))
                return false;
        }
        else if (color[i] == c)
            return false;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<std::vector<int>> arr(a, std::vector<int>());

    for (int i = 0; i < b; i++)
    {
        int e1, e2;
        std::cin >> e1 >> e2;
        // cout << e1 << e2 << endl;
        arr[e1 - 1].push_back(e2 - 1);
        arr[e2 - 1].push_back(e1 - 1);
    }
    std::vector<int> color(arr.size(), 0);
    bool flag = true;
    for (int i = 0; i < arr.size(); i++)
    {
        if (color[i] == 0)
        {
            flag = bipartiteGraph(arr, color, i, 1);
            if (!flag)
                break;
        }
    }
    if (flag)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}