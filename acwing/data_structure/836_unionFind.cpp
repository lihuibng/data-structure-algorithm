#include <iostream>
#include <vector>

/*
一共有 n 个数，编号是 1∼n，最开始每个数各自在一个集合中。

现在要进行 m 个操作，操作共有两种：

M a b，将编号为 a 和 b 的两个数所在的集合合并，如果两个数已经在同一个集合中，则忽略这个操作；
Q a b，询问编号为 a 和 b 的两个数是否在同一个集合中；
输入格式
第一行输入整数 n 和 m。

接下来 m 行，每行包含一个操作指令，指令为 M a b 或 Q a b 中的一种。

输出格式
对于每个询问指令 Q a b，都要输出一个结果，如果 a 和 b 在同一集合内，则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤n,m≤105
输入样例：
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
输出样例：
Yes
No
Yes
*/

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
        int i, j;
        std::cin >> m >> i >> j;
        if (m == "M")
        {
            uf.merge(i - 1, j - 1);
        }
        else if (m == "Q")
        {
            int pi = uf.find(i - 1);
            int pj = uf.find(j - 1);
            if (pi == pj)
                std::cout << "Yes" << std::endl;
            else
                std::cout << "No" << std::endl;
        }
    }
    return 0;
}
