#include <iostream>
#include <vector>
#include <string>

/*
给定一个字符串 S，以及一个模式串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模式串 P 在字符串 S 中多次作为子串出现。

求出模式串 P 在字符串 S 中所有出现的位置的起始下标。

输入格式
第一行输入整数 N，表示字符串 P 的长度。

第二行输入字符串 P。

第三行输入整数 M，表示字符串 S 的长度。

第四行输入字符串 S。

输出格式
共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。

数据范围
1≤N≤105
1≤M≤106
输入样例：
3
aba
5
ababa
输出样例：
0 2
*/

std::vector<int> kmp(const std::string &s, const std::string &b)
{
    std::vector<int> next(b.size() + 1, 0);
    std::vector<int> res;
    for (int i = 2, j = 0; i < b.size(); i++)
    {
        while (j > 0 && b[i] != b[j + 1])
            j = next[j];
        if (b[i] == b[j + 1])
            j++;
        next[i] = j;
    }
    for (int i = 1, j = 0; i < s.size(); i++)
    {
        while (j > 0 && s[i] != b[j + 1])
            j = next[j];
        if (s[i] == b[j + 1])
            j++;
        if (j == b.size() - 1)
        {
            res.push_back(i - (b.size() - 1));
            j = next[j];
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    int m, n;
    std::string a, b;

    std::cin >> m >> a >> n >> b;
    auto v = kmp(" " + b, " " + a);

    for (auto &k : v)
        std::cout << k << " ";
    std::cout << std::endl;
    return 0;
}