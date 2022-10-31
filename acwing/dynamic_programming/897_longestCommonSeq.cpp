#include <iostream>
#include <vector>

/*
给定两个长度分别为 N 和 M 的字符串 A 和 B，求既是 A 的子序列又是 B 的子序列的字符串长度最长是多少。

输入格式
第一行包含两个整数 N 和 M。

第二行包含一个长度为 N 的字符串，表示字符串 A。

第三行包含一个长度为 M 的字符串，表示字符串 B。

字符串均由小写字母构成。

输出格式
输出一个整数，表示最大长度。

数据范围
1≤N,M≤1000
输入样例：
4 5
acbd
abedc
输出样例：
3
*/

// dp[i][j]
int longestCommonSeq(const std::string &arr1, const std::string &arr2)
{
    int n = arr1.size(), m = arr2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr1[i - 1] == arr2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[n][m];
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    std::string astr, bstr;
    std::cin >> astr >> bstr;

    std::cout << longestCommonSeq(astr, bstr) << std::endl;
    return 0;
}