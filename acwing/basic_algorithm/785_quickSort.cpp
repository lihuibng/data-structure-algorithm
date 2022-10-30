#include <iostream>
#include <vector>

/*
给定你一个长度为 n 的整数数列。

请你使用快速排序对这个数列按照从小到大进行排序。

并将排好序的数列按顺序输出。

输入格式
输入共两行，第一行包含整数 n。

第二行包含 n 个整数（所有整数均在 1∼109 范围内），表示整个数列。

输出格式
输出共一行，包含 n 个整数，表示排好序的数列。

数据范围
1≤n≤100000
输入样例：
5
3 1 2 4 5
输出样例：
1 2 3 4 5
*/

void quickSort(std::vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
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
    quickSort(arr, l, j);
    quickSort(arr, j + 1, r);
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    quickSort(arr, 0, arr.size() - 1);

    for (auto &k : arr)
        std::cout << k << " ";
    std::cout << std::endl;
    return 0;
}