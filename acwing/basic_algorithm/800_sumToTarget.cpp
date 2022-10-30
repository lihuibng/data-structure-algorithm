#include <iostream>
#include <vector>

/*
给定两个升序排序的有序数组 A 和 B，以及一个目标值 x。

数组下标从 0 开始。

请你求出满足 A[i]+B[j]=x 的数对 (i,j)。

数据保证有唯一解。

输入格式
第一行包含三个整数 n,m,x，分别表示 A 的长度，B 的长度以及目标值 x。

第二行包含 n 个整数，表示数组 A。

第三行包含 m 个整数，表示数组 B。

输出格式
共一行，包含两个整数 i 和 j。

数据范围
数组长度不超过 105。
同一数组内元素各不相同。
1≤数组元素≤109
输入样例：
4 5 6
1 2 4 7
3 4 6 8 9
输出样例：
1 1
*/


std::vector<int> sumToTarget(const std::vector<int> &c1, const std::vector<int> &c2, int k)
{
    for (int i = 0, j = c2.size() - 1; i < c1.size(); i++)
    {
        while (j >= 0 && c1[i] + c2[j] > k)
            j--;
        if (j >= 0 && c1[i] + c2[j] == k)
            return {i, j};
    }
    return {};
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a, b, c;
    std::cin >> a >> b >> c;
    std::vector<int> arr1;
    std::vector<int> arr2;
    while (a--)
    {
        int k;
        std::cin >> k;
        arr1.push_back(k);
    }
    while (b--)
    {
        int k;
        std::cin >> k;
        arr2.push_back(k);
    }
    auto v = sumToTarget(arr1, arr2, c);
    for (auto &k : v)
        std::cout << k << " ";
    std::cout << std::endl;
    return 0;
}