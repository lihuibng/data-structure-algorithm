#include <iostream>
#include <vector>
#include <queue>

/*
在一个果园里，达达已经将所有的果子打了下来，而且按果子的不同种类分成了不同的堆。

达达决定把所有的果子合成一堆。

每一次合并，达达可以把两堆果子合并到一起，消耗的体力等于两堆果子的重量之和。

可以看出，所有的果子经过 n−1 次合并之后，就只剩下一堆了。

达达在合并果子时总共消耗的体力等于每次合并所耗体力之和。

因为还要花大力气把这些果子搬回家，所以达达在合并果子时要尽可能地节省体力。

假定每个果子重量都为 1，并且已知果子的种类数和每种果子的数目，你的任务是设计出合并的次序方案，使达达耗费的体力最少，并输出这个最小的体力耗费值。

例如有 3 种果子，数目依次为 1，2，9。

可以先将 1、2 堆合并，新堆数目为 3，耗费体力为 3。

接着，将新堆与原先的第三堆合并，又得到新的堆，数目为 12，耗费体力为 12。

所以达达总共耗费体力=3+12=15。

可以证明 15 为最小的体力耗费值。

输入格式
输入包括两行，第一行是一个整数 n，表示果子的种类数。

第二行包含 n 个整数，用空格分隔，第 i 个整数 ai 是第 i 种果子的数目。

输出格式
输出包括一行，这一行只包含一个整数，也就是最小的体力耗费值。

输入数据保证这个值小于 231。

数据范围
1≤n≤10000,
1≤ai≤20000
输入样例：
3
1 2 9
输出样例：
15
*/

int combineFruit(std::vector<int> costs)
{
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (auto &k : costs)
        pq.push(k);
    int cost = 0;
    while (!pq.empty())
    {
        int first = pq.top();
        pq.pop();
        if (!pq.empty())
        {
            int second = pq.top();
            pq.pop();
            cost += first + second;
            pq.push(first + second);
        }
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

    std::cout << combineFruit(arr) << std::endl;
    return 0;
}