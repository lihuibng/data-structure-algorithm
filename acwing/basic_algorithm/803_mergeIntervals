#include <iostream>
#include <vector>
#include <algorithm>

/*
给定 n 个区间 [li,ri]，要求合并所有有交集的区间。

注意如果在端点处相交，也算有交集。

输出合并完成后的区间个数。

例如：[1,3] 和 [2,6] 可以合并为一个区间 [1,6]。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含两个整数 l 和 r。

输出格式
共一行，包含一个整数，表示合并区间完成后的区间个数。

数据范围
1≤n≤100000,
−109≤li≤ri≤109
输入样例：
5
1 2
2 4
5 6
7 8
7 9
输出样例：
3
*/

int mergeIntervals(std::vector<std::pair<int, int>> &add)
{
    std::sort(add.begin(), add.end(),
              [&](const std::pair<int, int> &a, const std::pair<int, int> &b) -> bool
              {
                  return a.first < b.first || (a.first == b.first && a.second > b.second);
              });
    std::vector<std::pair<int, int>> res;
    int st = add[0].first, ed = add[0].second;
    for (int i = 1; i < add.size(); i++)
    {
        if (add[i].first <= ed)
        {
            ed = std::max(ed, add[i].second);
        }
        else
        {
            res.push_back(std::make_pair(st, ed));
            st = add[i].first;
            ed = add[i].second;
        }
    }
    res.push_back(std::make_pair(st, ed));
    return res.size();
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a;
    std::cin >> a;
    std::vector<std::pair<int, int>> add;
    while (a--)
    {
        int m, n;
        std::cin >> m >> n;
        add.emplace_back(std::make_pair(m, n));
    }
    auto v = mergeIntervals(add);
    std::cout << v << std::endl;

    return 0;
}