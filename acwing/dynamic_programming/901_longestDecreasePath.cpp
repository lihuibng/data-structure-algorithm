#include <iostream>
#include <vector>

/*
给定一个 R 行 C 列的矩阵，表示一个矩形网格滑雪场。

矩阵中第 i 行第 j 列的点表示滑雪场的第 i 行第 j 列区域的高度。

一个人从滑雪场中的某个区域内出发，每次可以向上下左右任意一个方向滑动一个单位距离。

当然，一个人能够滑动到某相邻区域的前提是该区域的高度低于自己目前所在区域的高度。

下面给出一个矩阵作为例子：

 1  2  3  4 5

16 17 18 19 6

15 24 25 20 7

14 23 22 21 8

13 12 11 10 9
在给定矩阵中，一条可行的滑行轨迹为 24−17−2−1。

在给定矩阵中，最长的滑行轨迹为 25−24−23−…−3−2−1，沿途共经过 25 个区域。

现在给定你一个二维矩阵表示滑雪场各区域的高度，请你找出在该滑雪场中能够完成的最长滑雪轨迹，并输出其长度(可经过最大区域数)。

输入格式
第一行包含两个整数 R 和 C。

接下来 R 行，每行包含 C 个整数，表示完整的二维矩阵。

输出格式
输出一个整数，表示可完成的最长滑雪长度。

数据范围
1≤R,C≤300,
0≤矩阵中整数≤10000
输入样例：
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
输出样例：
25
*/

int dfs(const std::vector<std::vector<int>> &arr, std::vector<std::vector<int>> &dp, int x, int y)
{
    int n = arr.size();
    int m = arr[0].size();
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    if (dp[x][y] != -1)
        return dp[x][y];
    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && arr[nx][ny] < arr[x][y])
        {
            dp[x][y] = std::max(dp[x][y], dfs(arr, dp, nx, ny) + 1);
        }
    }
    return dp[x][y];
}

int longestDecreasePath(const std::vector<std::vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int res = 0;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = std::max(res, dfs(arr, dp, i, j));
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a >> b;
    std::vector<std::vector<int>> arr(a, std::vector<int>(b, 0));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    std::cout << longestDecreasePath(arr) << std::endl;
    return 0;
}