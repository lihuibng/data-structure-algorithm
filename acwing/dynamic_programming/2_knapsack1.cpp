#include <iostream>
#include <vector>

/*
有 N 件物品和一个容量是 V 的背包。每件物品只能使用一次。

第 i 件物品的体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品数量和背包容积。

接下来有 N 行，每行两个整数 vi,wi，用空格隔开，分别表示第 i 件物品的体积和价值。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N,V≤1000
0<vi,wi≤1000
输入样例
4 5
1 2
2 4
3 4
4 5
输出样例：
8
*/

int knapsack(std::vector<std::vector<int>> arr, int amount, int v)
{
    std::vector<int> dp(v + 1, 0);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = v; j >= arr[i][0]; j--)
        {
            dp[j] = std::max(dp[j], dp[j - arr[i][0]] + arr[i][1]);
        }
    }
    return dp[v];
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a >> b;
    int vi, wi;
    std::vector<std::vector<int>> arr;
    for (int i = 0; i < a; i++)
    {
        std::cin >> vi >> wi;
        arr.push_back({vi, wi});
    }

    std::cout << knapsack(arr, a, b) << std::endl;
    return 0;
}