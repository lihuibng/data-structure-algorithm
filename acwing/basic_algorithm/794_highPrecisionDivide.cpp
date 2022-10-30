#include <iostream>
#include <vector>
#include <algorithm>

/*
给定两个非负整数（不含前导 0） A，B，请你计算 A/B 的商和余数。

输入格式
共两行，第一行包含整数 A，第二行包含整数 B。

输出格式
共两行，第一行输出所求的商，第二行输出所求余数。

数据范围
1≤A的长度≤100000,
1≤B≤10000,
B 一定不为 0
输入样例：
7
2
输出样例：
3
1
*/

std::vector<int> div(const std::vector<int> &a, int b, int &r)
{
    std::vector<int> c;
    for (int i = 0; i < a.size(); i++)
    {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    std::reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)
        c.pop_back();
    return c;
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    std::string a;
    int b;
    std::cin >> a >> b;
    std::vector<int> arr1;
    std::vector<int> arr2;
    for (int i = 0; i < a.size(); i++)
    {
        arr1.push_back(a[i] - '0');
    }
    int r = 0;
    auto v = div(arr1, b, r);
    std::string res = "";
    while (v.size())
    {
        res += v.back() + '0';
        v.pop_back();
    }
    std::cout << res << std::endl;
    std::cout << r << std::endl;
    return 0;
}
