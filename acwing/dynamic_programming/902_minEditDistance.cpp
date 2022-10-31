#include <iostream>
#include <string>
#include <vector>

/*
902. 最短编辑距离
   题目
   提交记录
   讨论
   题解
   视频讲解

给定两个字符串 A 和 B，现在要将 A 经过若干操作变为 B，可进行的操作有：

删除–将字符串 A 中的某个字符删除。
插入–在字符串 A 的某个位置插入某个字符。
替换–将字符串 A 中的某个字符替换为另一个字符。
现在请你求出，将 A 变为 B 至少需要进行多少次操作。

输入格式
第一行包含整数 n，表示字符串 A 的长度。

第二行包含一个长度为 n 的字符串 A。

第三行包含整数 m，表示字符串 B 的长度。

第四行包含一个长度为 m 的字符串 B。

字符串中均只包含大小写字母。

输出格式
输出一个整数，表示最少操作次数。

数据范围
1≤n,m≤1000
输入样例：
10
AGTCTGACGC
11
AGTAAGTAGGC
输出样例：
4
*/
int minEditDistance(const std::string &arr1, const std::string &arr2)
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
    std::string astr, bstr;
    std::cin >> a >> astr;
    std::cin >> b >> bstr;

    std::cout << minEditDistance(astr, bstr) << std::endl;
    return 0;
}