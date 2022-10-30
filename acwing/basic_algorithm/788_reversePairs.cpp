#include <iostream>
#include <vector>

/*
给定一个长度为 n 的整数数列，请你计算数列中的逆序对的数量。

逆序对的定义如下：对于数列的第 i 个和第 j 个元素，如果满足 i<j 且 a[i]>a[j]，则其为一个逆序对；否则不是。

输入格式
第一行包含整数 n，表示数列的长度。

第二行包含 n 个整数，表示整个数列。

输出格式
输出一个整数，表示逆序对的个数。

数据范围
1≤n≤100000，
数列中的元素的取值范围 [1,109]。

输入样例：
6
2 3 4 5 6 1
输出样例：
5
*/

void reversePairs(std::vector<int> &arr, int l, int r, long &res)
{
    if (l >= r)
        return;
    int mid = l + r >> 1;
    reversePairs(arr, l, mid, res);
    reversePairs(arr, mid + 1, r, res);
    std::vector<int> tmp(r - l + 1);
    int i = l, j = mid + 1, k = 0;

    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            tmp[k++] = arr[j++];
            res += mid - i + 1;
        }
    }

    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (i = l, k = 0; i <= r; i++, k++)
        arr[i] = tmp[k];
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
    long res = 0;
    reversePairs(arr, 0, arr.size() - 1, res);

    std::cout << res << std::endl;
    return 0;
}