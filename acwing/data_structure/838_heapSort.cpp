#include <iostream>
#include <vector>

/*
输入一个长度为 n 的整数数列，从小到大输出前 m 小的数。

输入格式
第一行包含整数 n 和 m。

第二行包含 n 个整数，表示整数数列。

输出格式
共一行，包含 m 个整数，表示整数数列中前 m 小的数。

数据范围
1≤m≤n≤105，
1≤数列中元素≤109
输入样例：
5 3
4 5 1 3 2
输出样例：
1 2 3
*/


void down(std::vector<int> &arr, int u, int size)
{
    int t = u;
    if (2 * u < size && arr[t] > arr[2 * u])
    {
        t = 2 * u;
    }
    if (2 * u + 1 < size && arr[t] > arr[2 * u + 1])
    {
        t = 2 * u + 1;
    }
    if (t != u)
    {
        std::swap(arr[t], arr[u]);
        down(arr, t, size);
    }
}

std::vector<int> heapsort(std::vector<int> &arr, int m)
{
    for (int i = arr.size() / 2; i > 0; i--)
    {
        down(arr, i, arr.size());
    }
    std::vector<int> res;
    while (m--)
    {
        std::swap(arr[1], arr[arr.size() - 1]);
        res.push_back(arr[arr.size() - 1]);
        arr.pop_back();
        down(arr, 1, arr.size());
    }
    return res;
}
int main(int argc, char *argv[])
{
    int a, b;
    std::cin >> a >> b;
    std::vector<int> arr;
    arr.push_back(-1);
    while (a--)
    {
        int c;
        std::cin >> c;
        arr.push_back(c);
    }
    auto v = heapsort(arr, b);
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}