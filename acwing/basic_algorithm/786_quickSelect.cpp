#include <iostream>
#include <vector>

/*
给定一个长度为 n 的整数数列，以及一个整数 k，请用快速选择算法求出数列从小到大排序后的第 k 个数。

输入格式
第一行包含两个整数 n 和 k。

第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整数数列。

输出格式
输出一个整数，表示数列的第 k 小数。

数据范围
1≤n≤100000,
1≤k≤n
输入样例：
5 3
2 4 1 5 3
输出样例：
3
*/

int quickSelect(std::vector<int> &arr, int l, int r, int k)
{
    if (l >= r)
        return arr[k];
    int i = l - 1, j = r + 1;
    int key = arr[l + r >> 1];
    while (i < j)
    {
        do
            i++;
        while (arr[i] < key);
        do
            j--;
        while (arr[j] > key);
        if (i < j)
            std::swap(arr[i], arr[j]);
    }

    if (j >= k)
        return quickSelect(arr, l, j, k);
    else
        return quickSelect(arr, j + 1, r, k);
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << quickSelect(arr, 0, arr.size() - 1, k - 1) << std::endl;
    return 0;
}