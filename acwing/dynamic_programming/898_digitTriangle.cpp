#include <iostream>
#include <vector>

/*
给定一个如下图所示的数字三角形，从顶部出发，在每一结点可以选择移动至其左下方的结点或移动至其右下方的结点，一直走到底层，要求找出一条路径，使路径上的数字的和最大。

        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
输入格式
第一行包含整数 n，表示数字三角形的层数。

接下来 n 行，每行包含若干整数，其中第 i 行表示数字三角形第 i 层包含的整数。

输出格式
输出一个整数，表示最大的路径数字和。

数据范围
1≤n≤500,
−10000≤三角形中的整数≤10000
输入样例：
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出样例：
30
*/

int maxSum(const std::vector<std::vector<int>> &arr)
{
    int n = arr.size(), m = arr[n - 1].size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        dp[n - 1][i] = arr[n - 1][i];
        // cout << dp[n - 1][i] << endl;
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            dp[i][j] = std::max(dp[i + 1][j], dp[i + 1][j + 1]) + arr[i][j];
        }
    }
    return dp[0][0];
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a;
    int t = 1;
    std::vector<std::vector<int>> arr(a, std::vector<int>());
    while (t <= a)
    {
        for (int i = 0; i < t; i++)
        {
            int tmp;
            std::cin >> tmp;
            arr[t - 1].push_back(tmp);
        }
        t++;
    }

    std::cout << maxSum(arr) << std::endl;
    return 0;
}