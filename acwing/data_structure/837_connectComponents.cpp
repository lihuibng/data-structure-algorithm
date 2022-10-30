#include <iostream>
#include <vector>

/*
给定一个包含 n 个点（编号为 1∼n）的无向图，初始时图中没有边。

现在要进行 m 个操作，操作共有三种：

C a b，在点 a 和点 b 之间连一条边，a 和 b 可能相等；
Q1 a b，询问点 a 和点 b 是否在同一个连通块中，a 和 b 可能相等；
Q2 a，询问点 a 所在连通块中点的数量；
输入格式
第一行输入整数 n 和 m。

接下来 m 行，每行包含一个操作指令，指令为 C a b，Q1 a b 或 Q2 a 中的一种。

输出格式
对于每个询问指令 Q1 a b，如果 a 和 b 在同一个连通块中，则输出 Yes，否则输出 No。

对于每个询问指令 Q2 a，输出一个整数表示点 a 所在连通块中点的数量

每个结果占一行。

数据范围
1≤n,m≤105
输入样例：
5 5
C 1 2
Q1 1 2
Q2 1
C 2 5
Q2 5
输出样例：
Yes
2
3
*/

struct UnionFind
{
    std::vector<int> nodes;
    std::vector<int> cnt;
    UnionFind(int n)
    {
        nodes.resize(n);
        cnt.resize(n);
        for (int i = 0; i < n; i++)
        {
            nodes[i] = i;
            cnt[i] = 1;
        }
    }

    int find(int x)
    {
        if (x != nodes[x])
        {
            nodes[x] = find(nodes[x]);
        }
        return nodes[x];
    }

    void merge(int a, int b)
    {
        int pa = find(a), pb = find(b);
        nodes[pb] = pa;
        cnt[pa] += cnt[pb];
    }

    int getNodes(int a)
    {
        return cnt[a];
    }

    bool connected(int a, int b)
    {
        int pa = find(a - 1);
        int pb = find(b - 1);
        if (pa == pb)
            return true;
        return false;
    }
};

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    UnionFind uf(a);
    while (b--)
    {
        std::string m;

        std::cin >> m;
        if (m == "C")
        {
            int i, j;
            std::cin >> i >> j;
            if (!uf.connected(i - 1, j - 1))
            {
                uf.merge(i - 1, j - 1);
            }
        }
        else if (m == "Q1")
        {
            int i, j;
            std::cin >> i >> j;
            if (uf.connected(i - 1, j - 1))
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        }
        else if (m == "Q2")
        {
            int i;
            std::cin >> i;
            std::cout << uf.getNodes(i - 1) << std::endl;
        }
    }
    return 0;
}