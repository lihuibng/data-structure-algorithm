#include <iostream>
#include <vector>

/*
给定 n 个正整数 ai，对于每个整数 ai，请你按照从小到大的顺序输出它的所有约数。

输入格式
第一行包含整数 n。

接下来 n 行，每行包含一个整数 ai。

输出格式
输出共 n 行，其中第 i 行输出第 i 个整数 ai 的所有约数。

数据范围
1≤n≤100,
2≤ai≤2×109
输入样例：
2
6
8
输出样例：
1 2 3 6
1 2 4 8
*/

std::vector<int> getDivisors(int m)
{
    std::vector<int> res;
    for (int i = 1; i <= m / i; i++)
    {
        if (m % i == 0)
        {
            res.push_back(i);
            if (i != m / i)
                res.push_back(m / i);
        }
    }
    std::sort(res.begin(), res.end());
    return res;
}

int main(int argc, char *argv[])
{
    int a = 0;
    std::cin >> a;
    while (a--)
    {
        int b;
        std::cin >> b;
        auto v = getDivisors(b);
        for (auto &k : v)
            std::cout << k << " ";
        std::cout << std::endl;
    }
    return 0;
}