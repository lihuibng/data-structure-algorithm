#include <iostream>
#include <vector>

/*
求把 N×M 的棋盘分割成若干个 1×2 的长方形，有多少种方案。

例如当 N=2，M=4 时，共有 5 种方案。当 N=2，M=3 时，共有 3 种方案。

如下图所示：

2411_1.jpg

输入格式
输入包含多组测试用例。

每组测试用例占一行，包含两个整数 N 和 M。

当输入用例 N=0，M=0 时，表示输入终止，且该用例无需处理。

输出格式
每个测试用例输出一个结果，每个结果占一行。

数据范围
1≤N,M≤11
输入样例：
1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0
输出样例：
1
0
1
2
3
5
144
51205
*/

std::vector<bool> pre(int n)
{
    std::vector<bool> st(1 << n, false);
    for (int i = 0; i < 1 << n; i++)
    {
        int cnt = 0;
        bool valid = true;
        for (int j = 0; j < n; j++)
        {
            if (i >> j & 1)
            {
                if (cnt & 1)
                {
                    valid = false;
                    break;
                }
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        if (cnt & 1)
            valid = false;
        st[i] = valid;
    }
    return st;
}

std::vector<std::vector<int>> getValid(int n)
{
    std::vector<std::vector<int>> state(1 << n, std::vector<int>());
    auto st = pre(n);
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < 1 << n; j++)
        {
            if ((i & j) == 0 && st[i | j] == true)
            {
                state[i].push_back(j);
            }
        }
    }
    return state;
}

long long conjecture(int n, int m)
{
    std::vector<std::vector<long long>> dp(m + 1, std::vector<long long>(1 << n, 0));
    auto state = getValid(n);
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < (1 << n); j++)
        {
            for (auto k : state[j])
            {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    return dp[m][0];
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    while (std::cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        std::cout << conjecture(a, b) << std::endl;
    }
    return 0;
}