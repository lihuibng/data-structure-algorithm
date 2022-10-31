#include <iostream>
#include <vector>

/*
有 N 组物品和一个容量是 V 的背包。

每组物品有若干个，同一组内的物品最多只能选一个。
每件物品的体积是 vij，价值是 wij，其中 i 是组号，j 是组内编号。

求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。

输出最大价值。

输入格式
第一行有两个整数 N，V，用空格隔开，分别表示物品组数和背包容量。

接下来有 N 组数据：

每组数据第一行有一个整数 Si，表示第 i 个物品组的物品数量；
每组数据接下来有 Si 行，每行有两个整数 vij,wij，用空格隔开，分别表示第 i 个物品组的第 j 个物品的体积和价值；
输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤100
0<Si≤100
0<vij,wij≤100
输入样例
3 5
2
1 2
2 4
1
3 4
1
4 5
输出样例：
8
*/

int groupKnapsack(const std::vector<std::vector<std::pair<int, int>>> &wp, int n)
{
    std::vector<int> dp(n + 1, 0);
    for (int i = 0; i < wp.size(); i++)
    {
        for (int j = n; j >= 0; j--)
        {
            for (int k = 0; k < wp[i].size(); k++)
            {
                if (wp[i][k].first > j)
                    continue;
                dp[j] = std::max(dp[j], dp[j - wp[i][k].first] + wp[i][k].second);
            }
        }
    }

    return dp[n];
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    int t = a;
    std::vector<std::vector<std::pair<int, int>>> arr;
    while (t--)
    {
        int m;
        std::cin >> m;
        std::vector<std::pair<int, int>> tmp;
        while (m--)
        {
            int p, q;
            std::cin >> p >> q;
            tmp.push_back(std::make_pair(p, q));
        }
        arr.push_back(tmp);
    }

    std::cout << groupKnapsack(arr, b) << std::endl;
    return 0;
}