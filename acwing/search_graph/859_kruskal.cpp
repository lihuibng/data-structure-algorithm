#include <iostream>
#include <vector>
#include <algorithm>

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
1≤n≤105,
1≤m≤2∗105,
图中涉及边的边权的绝对值均不超过 1000。

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

struct Edge
{
    int from;
    int to;
    int weight;

    bool operator<(const Edge &e)
    {
        return weight < e.weight;
    }
};
bool cmp(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

struct UnionFind
{
    std::vector<int> nodes;
    UnionFind(int n)
    {
        nodes.resize(n);
        for (int i = 0; i < n; i++)
        {
            nodes[i] = i;
        }
    }

    int find(int x)
    {

        if (x != nodes[x])
            nodes[x] = find(nodes[x]);
        return nodes[x];
    }

    void merge(int a, int b)
    {
        int pa = find(a), pb = find(b);
        nodes[pb] = pa;
    }
};

int kruskal(std::vector<Edge> &arr, int n)
{
    int res = 0, cnt = 0;
    std::sort(arr.begin(), arr.end(), cmp);
    UnionFind uf(n);
    for (int i = 0; i < arr.size(); i++)
    {
        int a = uf.find(arr[i].from);
        int b = uf.find(arr[i].to);
        int w = arr[i].weight;
        if (a != b)
        {
            uf.merge(a, b);
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1)
        return -1;
    else
        return res;
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::vector<Edge> arr(b);
    for (int i = 0; i < b; i++)
    {
        int j, k, m;
        std::cin >> j >> k >> m;
        arr.push_back({j - 1, k - 1, m});
    }

    int ans = kruskal(arr, a);
    if (ans == -1)
    {
        std::cout << "impossible" << std::endl;
    }
    else
    {
        std::cout << ans << std::endl;
    }
    return 0;
}