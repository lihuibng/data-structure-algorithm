#include <iostream>
#include <vector>

/*
设有 N 堆石子排成一排，其编号为 1，2，3，…，N。

每堆石子有一定的质量，可以用一个整数来描述，现在要将这 N 堆石子合并成为一堆。

每次只能合并相邻的两堆，合并的代价为这两堆石子的质量之和，合并后与这两堆石子相邻的石子将和新堆相邻，合并时由于选择的顺序不同，合并的总代价也不相同。

例如有 4 堆石子分别为 1 3 5 2， 我们可以先合并 1、2 堆，代价为 4，得到 4 5 2， 又合并 1，2 堆，代价为 9，得到 9 2 ，再合并得到 11，总代价为 4+9+11=24；

如果第二步是先合并 2，3 堆，则代价为 7，得到 4 7，最后一次合并代价为 11，总代价为 4+7+11=22。

问题是：找出一种合理的方法，使总的代价最小，输出最小代价。

输入格式
第一行一个数 N 表示石子的堆数 N。

第二行 N 个数，表示每堆石子的质量(均不超过 1000)。

输出格式
输出一个整数，表示最小代价。

数据范围
1≤N≤300
输入样例：
4
1 3 5 2
输出样例：
22
难度：简单
时/空限制：1s / 64MB
总通过数：35829
总尝试数：49350
来源：《算法竞赛进阶指南》, 模板题
算法标签
*/

int mergeStones(const std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> presum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            presum[i] = arr[i];
        else
            presum[i] = presum[i - 1] + arr[i];
    }

    std::vector<std::vector<int>> dp(n, std::vector<int>(n, INT_MAX));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (len == 1)
            {
                dp[i][j] = 0;
                continue;
            }
            for (int k = i; k < j; k++)
            {
                // cout << k  << " " << i << " " << j << " "<< n << endl;
                dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k + 1][j] + (presum[j] - presum[i - 1]));
            }
        }
    }

    return dp[0][n - 1];
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a;
    int t = 1;
    std::vector<int> arr;
    while (t <= a)
    {
        int m;
        std::cin >> m;
        arr.push_back(m);
        t++;
    }

    std::cout << mergeStones(arr) << std::endl;
    return 0;
}