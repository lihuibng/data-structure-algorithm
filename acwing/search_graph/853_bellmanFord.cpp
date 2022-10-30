#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/*
给定一个 n 个点 m 条边的有向图，图中可能存在重边和自环， 边权可能为负数。

请你求出从 1 号点到 n 号点的最多经过 k 条边的最短距离，如果无法从 1 号点走到 n 号点，输出 impossible。

注意：图中可能 存在负权回路 。

输入格式
第一行包含三个整数 n,m,k。

接下来 m 行，每行包含三个整数 x,y,z，表示存在一条从点 x 到点 y 的有向边，边长为 z。

点的编号为 1∼n。

输出格式
输出一个整数，表示从 1 号点到 n 号点的最多经过 k 条边的最短距离。

如果不存在满足条件的路径，则输出 impossible。

数据范围
1≤n,k≤500,
1≤m≤10000,
1≤x,y≤n，
任意边长的绝对值不超过 10000。

输入样例：
3 3 1
1 2 1
2 3 1
1 3 3
输出样例：
3
*/

std::string bf(std::vector<std::vector<int>> &arr,
               std::vector<int> &dist,
               int k)
{
    dist[0] = 0;
    for (int i = 0; i < k; i++)
    {
        std::vector<int> backup(dist.begin(), dist.end());
        for (int j = 0; j < arr.size(); j++)
        {
            dist[arr[j][1]] = std::min(dist[arr[j][1]], backup[arr[j][0]] + arr[j][2]);
        }
    }

    if (dist[dist.size() - 1] > 0x3f3f3f3f / 2)
        return "impossible";
    return std::to_string(dist[dist.size() - 1]);
}

int main(int argc, char *argv[])
{
    int a, b, c;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b >> c;
    std::vector<std::vector<int>> arr;
    std::vector<int> dist(a, 0x3f3f3f3f);
    for (int i = 0; i < b; i++)
    {
        int k, j, m;
        std::cin >> k >> j >> m;
        arr.push_back({k - 1, j - 1, m});
    }
    std::sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    std::string ans = bf(arr, dist, c);
    std::cout << ans << std::endl;

    return 0;
}