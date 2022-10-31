#include <iostream>
#include <vector>

/*
给定一张 n 个点的带权无向图，点从 0∼n−1 标号，求起点 0 到终点 n−1 的最短 Hamilton 路径。

Hamilton 路径的定义是从 0 到 n−1 不重不漏地经过每个点恰好一次。

输入格式
第一行输入整数 n。

接下来 n 行每行 n 个整数，其中第 i 行第 j 个整数表示点 i 到 j 的距离（记为 a[i,j]）。

对于任意的 x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x] 并且 a[x,y]+a[y,z]≥a[x,z]。

输出格式
输出一个整数，表示最短 Hamilton 路径的长度。

数据范围
1≤n≤20
0≤a[i,j]≤107
输入样例：
5
0 2 4 5 1
2 0 6 5 3
4 6 0 8 3
5 5 8 0 5
1 3 3 5 0
输出样例：
18
*/

long long getHamilton(std::vector<std::vector<int>> &arr)
{
    int n = arr.size();
    std::vector<std::vector<long long>> dp(1 << n, std::vector<long long>(n, INT_MAX));
    dp[1][0] = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j & 1) == 0)
            {
                continue;
            }
            for (int k = 0; k < n; k++)
            {
                if ((i - (1 << j) >> k & 1) == 0)
                {
                    continue;
                }
                dp[i][j] = std::min(dp[i][j], dp[i - (1 << j)][k] + arr[k][j]);
            }
        }
    }
    return dp[(1 << n) - 1][n - 1];
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a;
    int i = 0;
    std::vector<std::vector<int>> arr(a, std::vector<int>(a, 0));
    while (i < a * a)
    {
        std::cin >> arr[i / a][i % a];
        i++;
    }
    std::cout << getHamilton(arr) << std::endl;
    return 0;
}