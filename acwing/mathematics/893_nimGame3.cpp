#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/*
给定 n 堆石子以及一个由 k 个不同正整数构成的数字集合 S。

现在有两位玩家轮流操作，每次操作可以从任意一堆石子中拿取石子，每次拿取的石子数量必须包含于集合 S，最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 k，表示数字集合 S 中数字的个数。

第二行包含 k 个整数，其中第 i 个整数表示数字集合 S 中的第 i 个数 si。

第三行包含整数 n。

第四行包含 n 个整数，其中第 i 个整数表示第 i 堆石子的数量 hi。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n,k≤100,
1≤si,hi≤10000
输入样例：
2
2 5
3
2 4 7
输出样例：
Yes
*/

int sg(const std::vector<int> &fetch, std::unordered_map<int, int> &sgs, int x)
{
    if (sgs.count(x))
        return sgs[x];
    std::unordered_set<int> ms;
    for (int i = 0; i < fetch.size(); i++)
    {
        if (x >= fetch[i])
            ms.insert(sg(fetch, sgs, x - fetch[i]));
    }
    for (int i = 0;; i++)
    {
        if (!ms.count(i))
            return sgs[x] = i;
    }
    return -1;
}
int main(int argc, char *argv[])
{
    int a, b;
    std::cin >> a;
    std::vector<int> fetch;
    while (a--)
    {
        int c;
        std::cin >> c;
        fetch.push_back(c);
    }
    int xo = 0;
    std::cin >> b;
    std::unordered_map<int, int> mp;
    while (b--)
    {
        int c;
        std::cin >> c;
        xo ^= sg(fetch, mp, c);
    }
    if (xo == 0)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;

    return 0;
}