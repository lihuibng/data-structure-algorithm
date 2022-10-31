#include <iostream>

/*
给定 n 堆石子，两位玩家轮流操作，每次操作可以从任意一堆石子中拿走任意数量的石子（可以拿完，但不能不拿），最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 n。

第二行包含 n 个数字，其中第 i 个数字表示第 i 堆石子的数量。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n≤105,
1≤每堆石子数≤109
输入样例：
2
2 3
输出样例：
Yes
*/

int main(int argc, char *argv[])
{
    int b;
    std::cin >> b;
    int xo = 0;
    while (b--)
    {
        int c;
        std::cin >> c;
        xo ^= c;
    }
    if (xo == 0)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;

    return 0;
}