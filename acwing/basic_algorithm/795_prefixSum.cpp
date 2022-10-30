#include <iostream>
#include <vector>

/*
输入一个长度为 n 的整数序列。

接下来再输入 m 个询问，每个询问输入一对 l,r。

对于每个询问，输出原序列中从第 l 个数到第 r 个数的和。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个整数，表示整数数列。

接下来 m 行，每行包含两个整数 l 和 r，表示一个询问的区间范围。

输出格式
共 m 行，每行输出一个询问的结果。

数据范围
1≤l≤r≤n,
1≤n,m≤100000,
−1000≤数列中元素的值≤1000
输入样例：
5 3
2 1 3 6 4
1 2
1 3
2 4
输出样例：
3
6
10
*/

int prefixsum(const std::vector<int> &c, int l, int r)
{
    if (l > 0)
    {
        return c[r] - c[l - 1];
    }
    else
    {
        return c[r];
    }
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::vector<int> arr;
    while (a--)
    {
        int k;
        std::cin >> k;
        arr.push_back(k);
    }
    std::vector<int> c(arr.size(), 0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
        {
            c[i] = arr[i];
        }
        else
        {
            c[i] = arr[i] + c[i - 1];
        }
    }
    while (b--)
    {
        int m, n;
        std::cin >> m >> n;
        std::cout << prefixsum(c, m - 1, n - 1) << std::endl;
    }
    return 0;
}