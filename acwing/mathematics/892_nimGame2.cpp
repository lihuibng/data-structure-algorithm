#include <iostream>

/*
现在，有一个 n 级台阶的楼梯，每级台阶上都有若干个石子，其中第 i 级台阶上有 ai 个石子(i≥1)。

两位玩家轮流操作，每次操作可以从任意一级台阶上拿若干个石子放到下一级台阶中（不能不拿）。

已经拿到地面上的石子不能再拿，最后无法进行操作的人视为失败。

问如果两人都采用最优策略，先手是否必胜。

输入格式
第一行包含整数 n。

第二行包含 n 个整数，其中第 i 个整数表示第 i 级台阶上的石子数 ai。

输出格式
如果先手方必胜，则输出 Yes。

否则，输出 No。

数据范围
1≤n≤105,
1≤ai≤109
输入样例：
3
2 1 3
输出样例：
Yes
*/

int main(int argc, char *argv[])
{
    int b;
    std::cin >> b;
    int xo = 0;
    int cnt = 1;
    while (b--)
    {
        int c;
        std::cin >> c;
        if (cnt % 2)
            xo ^= c;
        cnt++;
    }
    if (xo == 0)
        std::cout << "No" << std::endl;
    else
        std::cout << "Yes" << std::endl;

    return 0;
}