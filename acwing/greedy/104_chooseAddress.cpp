#include <iostream>
#include <vector>
#include <algorithm>

/*
在一条数轴上有 N 家商店，它们的坐标分别为 A1∼AN。

现在需要在数轴上建立一家货仓，每天清晨，从货仓到每家商店都要运送一车商品。

为了提高效率，求把货仓建在何处，可以使得货仓到每家商店的距离之和最小。

输入格式
第一行输入整数 N。

第二行 N 个整数 A1∼AN。

输出格式
输出一个整数，表示距离之和的最小值。

数据范围
1≤N≤100000,
0≤Ai≤40000
输入样例：
4
6 2 9 1
输出样例：
12
*/

long long minDistance(std::vector<int> distances)
{
    std::sort(distances.begin(), distances.end());
    int n = distances.size();
    long long sum = 0, mid = 0;
    if (n % 2 == 1)
    {
        mid = distances[n / 2];
    }
    else
    {
        mid = (distances[n / 2 - 1] + distances[n / 2]) / 2;
    }
    for (auto &k : distances)
        sum += abs(k - mid);
    return sum;
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a;
    std::vector<int> arr;
    while (a--)
    {
        int st;
        std::cin >> st;
        arr.push_back(st);
    }

    std::cout << minDistance(arr) << std::endl;
    return 0;
}