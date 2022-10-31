#include <iostream>
#include <vector>

/*
给定一个长度为 N 的数列，求数值严格单调递增的子序列的长度最长是多少。

输入格式
第一行包含整数 N。

第二行包含 N 个整数，表示完整序列。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N≤1000，
−109≤数列中的数≤109
输入样例：
7
3 1 2 1 8 5 6
输出样例：
4
*/

int longestIncreaseSeq(const std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> dp(n);
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        maxLen = std::max(maxLen, dp[i]);
    }
    return maxLen;
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

    std::cout << longestIncreaseSeq(arr) << std::endl;
    return 0;
}