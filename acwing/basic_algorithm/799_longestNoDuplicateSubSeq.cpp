#include <iostream>
#include <vector>
#include <unordered_set>

/*
给定一个长度为 n 的整数序列，请找出最长的不包含重复的数的连续区间，输出它的长度。

输入格式
第一行包含整数 n。

第二行包含 n 个整数（均在 0∼105 范围内），表示整数序列。

输出格式
共一行，包含一个整数，表示最长的不包含重复的数的连续区间的长度。

数据范围
1≤n≤105
输入样例：
5
1 2 2 3 5
输出样例：
3
*/

int longestNoDuplicateSubSeq(const std::vector<int> &c)
{
    std::unordered_set<int> ms;
    int j = -1;
    int maxLen = 0;
    for (int i = 0; i < c.size(); i++)
    {
        while (ms.count(c[i]))
        {
            ms.erase(c[++j]);
        }
        ms.insert(c[i]);
        maxLen = std::max(maxLen, (int)ms.size());
    }
    return maxLen;
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a;
    std::cin >> a;
    std::vector<int> arr;
    while (a--)
    {
        int k;
        std::cin >> k;
        arr.push_back(k);
    }
    std::cout << longestNoDuplicateSubSeq(arr) << std::endl;
    return 0;
}
