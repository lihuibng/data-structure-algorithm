#include <iostream>
#include <vector>

/*
给定两个非负整数（不含前导 0） A 和 B，请你计算 A×B 的值。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共一行，包含 A×B 的值。

数据范围
1≤A的长度≤100000,
0≤B≤10000
输入样例：
2
3
输出样例：
6
*/

std::vector<int> mul(const std::vector<int> &a, const std::vector<int> &b)
{
    std::vector<int> c(a.size() + b.size() + 10, 0);
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            c[i + j] += a[i] * b[j];
        }
    }
    int t = 0;
    for (int i = 0; i < c.size(); i++)
    {
        t += c[i];
        c[i] = t % 10;
        t /= 10;
    }
    while (c.size() > 0 && c.back() == 0)
        c.pop_back();
    return c;
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
    auto v = mul(arr1, arr2);
    std::string res = "";
    while (v.size())
    {
        res += v.back() + '0';
        v.pop_back();
    }
    if (res.empty())
    {
        std::cout << "0" << std::endl;
    }
    else
    {
        std::cout << res << std::endl;
    }
    return 0;
}