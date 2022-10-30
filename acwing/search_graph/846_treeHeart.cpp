#include <iostream>
#include <vector>
#include <set>

/*
给定一颗树，树中包含 n 个结点（编号 1∼n）和 n−1 条无向边。

请你找到树的重心，并输出将重心删除后，剩余各个连通块中点数的最大值。

重心定义：重心是指树中的一个结点，如果将这个点删除后，剩余各个连通块中点数的最大值最小，那么这个节点被称为树的重心。

输入格式
第一行包含整数 n，表示树的结点数。

接下来 n−1 行，每行包含两个整数 a 和 b，表示点 a 和点 b 之间存在一条边。

输出格式
输出一个整数 m，表示将重心删除后，剩余各个连通块中点数的最大值。

数据范围
1≤n≤105
输入样例
9
1 2
1 7
1 4
2 8
2 5
4 3
3 9
4 6
输出样例：
4
*/

int treeHeart(const std::vector<std::set<int>> &arr, std::vector<int> &visited, int root, int &ans, int total)
{
    visited[root] = 1;
    int sum = 1, res = 0;
    for (auto k : arr[root])
    {
        if (visited[k] == 0)
        {
            int s = treeHeart(arr, visited, k, ans, total);
            res = std::max(res, s);
            sum += s;
        }
    }
    res = std::max(total - sum, res);
    ans = std::min(ans, res);
    return sum;
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a;
    std::vector<std::set<int>> arr(a, std::set<int>());
    std::vector<int> visited(a, 0);
    for (int i = 0; i < a - 1; i++)
    {
        int k, j;
        std::cin >> k >> j;
        arr[k - 1].insert(j - 1);
        arr[j - 1].insert(k - 1);
    }
    int ans = a;
    treeHeart(arr, visited, 0, ans, a);
    std::cout << ans << std::endl;
    return 0;
}