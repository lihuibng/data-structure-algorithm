#include <iostream>
#include <string>
#include <vector>

/*
给定 n 个长度不超过 10 的字符串以及 m 次询问，每次询问给出一个字符串和一个操作次数上限。

对于每次询问，请你求出给定的 n 个字符串中有多少个字符串可以在上限操作次数内经过操作变成询问给出的字符串。

每个对字符串进行的单个字符的插入、删除或替换算作一次操作。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含一个字符串，表示给定的字符串。

再接下来 m 行，每行包含一个字符串和一个整数，表示一次询问。

字符串中只包含小写字母，且长度均不超过 10。

输出格式
输出共 m 行，每行输出一个整数作为结果，表示一次询问中满足条件的字符串个数。

数据范围
1≤n,m≤1000,

输入样例：
3 2
abc
acd
bcd
ab 1
acbd 2
输出样例：
1
3
*/

// dp[i][j]
int editDistance(const std::string &arr1, const std::string &arr2)
{
    int n = arr1.size(), m = arr2.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
            dp[i][j] = std::min(dp[i][j], dp[i - 1][j - 1] + (arr1[i - 1] != arr2[j - 1]));
        }
    }
    return dp[n][m];
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::string astr, bstr;
    std::vector<std::string> strs;
    while (a--)
    {
        std::cin >> astr;
        strs.push_back(astr);
    }
    while (b--)
    {
        int m, cnt = 0;
        std::cin >> bstr >> m;
        for (int i = 0; i < strs.size(); i++)
        {
            int t = editDistance(strs[i], bstr);
            if (t <= m)
                cnt++;
        }
        std::cout << cnt << std::endl;
    }
    return 0;
}