#include <iostream>
#include <vector>

/*
给定两个正整数（不含前导 0），计算它们的和。

输入格式
共两行，每行包含一个整数。

输出格式
共一行，包含所求的和。

数据范围
1≤整数长度≤100000
输入样例：
12
23
输出样例：
35
*/


std::vector<int> add(const std::vector<int> &a, const std::vector<int> &b)
{
    std::vector<int> c;
    if (a.size() < b.size())
        return add(b, a);
    for (int i = 0, t = 0; i < a.size() || t > 0; i++)
    {
        if (i < a.size())
            t += a[i];
        if (i < b.size())
            t += b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    while (c.back() == 0)
        c.pop_back();
    return c;
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

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
    auto v = add(arr1, arr2);
    std::string res;
    while (v.size())
    {
        res += '0' + v.back();
        v.pop_back();
    }
    std::cout << res << std::endl;
    return 0;
}