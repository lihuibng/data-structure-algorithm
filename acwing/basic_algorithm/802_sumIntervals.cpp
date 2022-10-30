#include <iostream>
#include <vector>
#include <algorithm>

/*
假定有一个无限长的数轴，数轴上每个坐标上的数都是 0。

现在，我们首先进行 n 次操作，每次操作将某一位置 x 上的数加 c。

接下来，进行 m 次询问，每个询问包含两个整数 l 和 r，你需要求出在区间 [l,r] 之间的所有数的和。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含两个整数 x 和 c。

再接下来 m 行，每行包含两个整数 l 和 r。

输出格式
共 m 行，每行输出一个询问中所求的区间内数字和。

数据范围
−109≤x≤109,
1≤n,m≤105,
−109≤l≤r≤109,
−10000≤c≤10000
输入样例：
3 3
1 2
3 6
7 5
1 3
4 6
7 8
输出样例：
8
0
5
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

int find(std::vector<int> &alls, int k)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

std::vector<int> discretization(
    const std::vector<std::pair<int, int>> &add,
    const std::vector<std::pair<int, int>> &query,
    std::vector<int> &alls)
{

    std::sort(alls.begin(), alls.end());
    alls.erase(std::unique(alls.begin(), alls.end()), alls.end());
    std::vector<int> a(alls.size(), 0);
    std::vector<int> sum(alls.size() + 1, 0);
    std::vector<int> res;
    for (int i = 0; i < add.size(); i++)
    {
        int idx = find(alls, add[i].first);
        a[idx] += add[i].second;
    }
    for (int j = 0; j < a.size(); j++)
    {
        sum[j + 1] = sum[j] + a[j];
    }
    for (auto &k : query)
    {
        int l = find(alls, k.first);
        int r = find(alls, k.second);
        res.push_back(sum[r + 1] - sum[l]);
    }
    return res;
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::vector<std::pair<int, int>> add;
    std::vector<std::pair<int, int>> query;
    std::vector<int> alls;
    while (a--)
    {
        int m, n;
        std::cin >> m >> n;
        add.emplace_back(std::make_pair(m, n));
        alls.push_back(m);
    }
    while (b--)
    {
        int m, n;
        std::cin >> m >> n;
        query.emplace_back(std::make_pair(m, n));
        alls.push_back(m);
        alls.push_back(n);
    }
    auto v = discretization(add, query, alls);
    for (auto &k : v)
        std::cout << k << std::endl;
    return 0;
}