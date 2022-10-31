#include <iostream>
#include <vector>

/*
有 N 种物品和一个容量是 V 的背包。

第 i 种物品最多有 si 件，每件体积是 vi，价值是 wi。

求解将哪些物品装入背包，可使物品体积总和不超过背包容量，且价值总和最大。
输出最大价值。

输入格式
第一行两个整数，N，V，用空格隔开，分别表示物品种数和背包容积。

接下来有 N 行，每行三个整数 vi,wi,si，用空格隔开，分别表示第 i 种物品的体积、价值和数量。

输出格式
输出一个整数，表示最大价值。

数据范围
0<N≤1000
0<V≤2000
0<vi,wi,si≤2000
提示：
本题考查多重背包的二进制优化方法。

输入样例
4 5
1 2 3
2 4 1
3 4 3
4 5 2
输出样例：
10
*/

int multiKnapsack(std::vector<std::vector<int>> arr, int amount, int v)
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
    int vi, wi, si;
    std::vector<std::vector<int>> arr;
    for (int i = 0; i < a; i++)
    {
        std::cin >> vi >> wi >> si;
        int cnt = 0;
        while (si > (1 << cnt))
        {
            int x = 1 << cnt;
            arr.push_back({vi * x, wi * x});
            si -= x;
            cnt++;
        }
        if (si > 0)
            arr.push_back({vi * si, wi * si});
    }

    std::cout << multiKnapsack(arr, a, b) << std::endl;
    return 0;
}