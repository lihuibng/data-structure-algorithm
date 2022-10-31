#include <iostream>
#include <vector>
#include <queue>

/*
有 n 个人排队到 1 个水龙头处打水，第 i 个人装满水桶所需的时间是 ti，请问如何安排他们的打水顺序才能使所有人的等待时间之和最小？

输入格式
第一行包含整数 n。

第二行包含 n 个整数，其中第 i 个整数表示第 i 个人装满水桶所花费的时间 ti。

输出格式
输出一个整数，表示最小的等待时间之和。

数据范围
1≤n≤105,
1≤ti≤104
输入样例：
7
3 6 1 4 2 5 7
输出样例：
56
*/

long long waitingThrash(std::vector<int> costs)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto &k : costs)
        pq.push(k);
    long long cost = 0;
    while (!pq.empty())
    {
        int p = pq.top();
        pq.pop();
        cost += p * pq.size();
    }
    return cost;
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

    std::cout << waitingThrash(arr) << std::endl;
    return 0;
}