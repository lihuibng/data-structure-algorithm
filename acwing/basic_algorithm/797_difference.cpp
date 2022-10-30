#include <iostream>
#include <vector>

/*
输入一个长度为 n 的整数序列。

接下来输入 m 个操作，每个操作包含三个整数 l,r,c，表示将序列中 [l,r] 之间的每个数加上 c。

请你输出进行完所有操作后的序列。

输入格式
第一行包含两个整数 n 和 m。

第二行包含 n 个整数，表示整数序列。

接下来 m 行，每行包含三个整数 l，r，c，表示一个操作。

输出格式
共一行，包含 n 个整数，表示最终序列。

数据范围
1≤n,m≤100000,
1≤l≤r≤n,
−1000≤c≤1000,
−1000≤整数序列中元素的值≤1000
输入样例：
6 3
1 2 2 1 2 1
1 3 1
3 5 1
1 6 1
输出样例：
3 4 5 3 4 2
*/

void diff(std::vector<int> &c, int l, int r, int val)
{
    c[l] += val;
    if (r < c.size())
        c[r + 1] -= val;
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::vector<int> arr(a, 0);
    for (int i = 0; i < a; i++)
    {
        std::cin >> arr[i];
    }
    std::vector<int> c(a + 1, 0);
    for (int i = 0; i < a; i++)
    {
        if (i == 0)
            c[i + 1] = arr[i];
        else
        {
            c[i + 1] = arr[i] - arr[i - 1];
        }
    }
    while (b--)
    {
        int l, r, v;
        std::cin >> l >> r >> v;
        diff(c, l, r, v);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            arr[i] = c[i + 1];
        else
            arr[i] = c[i + 1] + arr[i - 1];
    }
    for (auto k : arr)
        std::cout << k << " ";
    std::cout << std::endl;
    return 0;
}