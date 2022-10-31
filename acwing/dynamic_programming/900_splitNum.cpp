#include <iostream>
#include <vector>

const int M = 1e9 + 7;
/*
一个正整数 n 可以表示成若干个正整数之和，形如：n=n1+n2+…+nk，其中 n1≥n2≥…≥nk,k≥1。

我们将这样的一种表示称为正整数 n 的一种划分。

现在给定一个正整数 n，请你求出 n 共有多少种不同的划分方法。

输入格式
共一行，包含一个整数 n。

输出格式
共一行，包含一个整数，表示总划分数量。

由于答案可能很大，输出结果请对 109+7 取模。

数据范围
1≤n≤1000
输入样例:
5
输出样例：
7
*/

int splitNum(int n)
{
    std::vector<int> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            dp[j] = (dp[j] + dp[j - i]) % M;
        }
    }
    return dp[n];
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a;

    std::cout << splitNum(a) << std::endl;
    return 0;
}