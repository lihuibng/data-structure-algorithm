#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

/*
给定 n 堆石子，两位玩家轮流操作，每次操作可以取走其中的一堆石子，然后放入两堆规模更小的石子（新堆规模可以为 0，且两个新堆的石子总数可以大于取走的那堆石子数），最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 n。

第二行包含 n 个整数，其中第 i 个整数表示第 i 堆石子的数量 ai。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n,ai≤100
输入样例：
2
2 3
输出样例：
Yes
*/

int sg(std::unordered_map<int, int> &sgs, int x)
{
    if (sgs.count(x))
        return sgs[x];
    std::unordered_set<int> ms;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j <= i; j++)
            ms.insert(sg(sgs, i) ^ sg(sgs, j));
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
    int b;
    int xo = 0;
    std::cin >> b;
    std::unordered_map<int, int> mp;
    while (b--)
    {
        int c;
        std::cin >> c;
        xo ^= sg(mp, c);
    }
    if (xo == 0)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;

    return 0;
}