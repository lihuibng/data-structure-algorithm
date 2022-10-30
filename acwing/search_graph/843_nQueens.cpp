#include <iostream>
#include <vector>

/*
n−皇后问题是指将 n 个皇后放在 n×n 的国际象棋棋盘上，使得皇后不能相互攻击到，即任意两个皇后都不能处于同一行、同一列或同一斜线上。

1_597ec77c49-8-queens.png

现在给定整数 n，请你输出所有的满足条件的棋子摆法。

输入格式
共一行，包含整数 n。

输出格式
每个解决方案占 n 行，每行输出一个长度为 n 的字符串，用来表示完整的棋盘状态。

其中 . 表示某一个位置的方格状态为空，Q 表示某一个位置的方格上摆着皇后。

每个方案输出完成后，输出一个空行。

注意：行末不能有多余空格。

输出方案的顺序任意，只要不重复且没有遗漏即可。

数据范围
1≤n≤9
输入样例：
4
输出样例：
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

*/

void nQueens(std::vector<std::string> &arr, std::vector<bool> &col, std::vector<bool> &dg, std::vector<bool> &udg, int idx)
{
    if (idx == arr.size())
    {
        for (auto &v : arr)
        {
            std::cout << v << std::endl;
        }
        std::cout << std::endl;
        return;
    }
    else
    {
        for (int y = 0; y < arr.size(); y++)
        {
            if (!col[y] && !dg[idx + y] && !udg[arr.size() - idx + y])
            {
                arr[idx][y] = 'Q';
                col[y] = dg[idx + y] = udg[arr.size() - idx + y] = true;
                nQueens(arr, col, dg, udg, idx + 1);
                col[y] = dg[idx + y] = udg[arr.size() - idx + y] = false;
                arr[idx][y] = '.';
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a;
    std::vector<std::string> arr(a, std::string(a, '.'));

    std::vector<bool> col(a, false), dg(a, false), udg(a, false);
    nQueens(arr, col, dg, udg, 0);

    return 0;
}