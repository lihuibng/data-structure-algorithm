#include <iostream>
#include <vector>

/*
给定两个正整数（不含前导 0），计算它们的差，计算结果可能为负数。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的差。

数据范围
1≤整数长度≤105
输入样例：
32
11
输出样例：
21
*/

std::vector<int> sub(const std::vector<int> &a, const std::vector<int> &b)
{
    std::vector<int> c;
    for (int i = 0, t = 0; i < a.size(); i++)
    {
        t = a[i] - t;
        if (i < b.size())
            t -= b[i];
        c.push_back((t + 10) % 10);
        if (t < 0)
            t = 1;
        else
            t = 0;
    }
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();

    return c;
}

bool comp(const std::vector<int> &a, const std::vector<int> &b)
{
    if (a.size() != b.size())
        return a.size() > b.size();
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }
    return true;
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    std::string a;
    std::string b;
    std::cin >> a >> b;
    std::vector<int> arr1;
    std::vector<int> arr2;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        arr1.push_back(a[i] - '0');
    }

    for (int i = b.size() - 1; i >= 0; i--)
    {
        arr2.push_back(b[i] - '0');
    }
    int flag = -1;
    if (comp(arr1, arr2))
        flag = 1;
    std::vector<int> v;
    if (flag == 1)
    {
        v = sub(arr1, arr2);
    }
    else if (flag == -1)
    {
        v = sub(arr2, arr1);
    }
    std::string res = flag == -1 ? "-" : "";
    while (v.size())
    {
        res += v.back() + '0';
        v.pop_back();
    }
    std::cout << res << std::endl;
    return 0;
}