#include <iostream>
#include <vector>

/*
输入一个 n 行 m 列的整数矩阵，再输入 q 个操作，每个操作包含五个整数 x1,y1,x2,y2,c，其中 (x1,y1) 和 (x2,y2) 表示一个子矩阵的左上角坐标和右下角坐标。

每个操作都要将选中的子矩阵中的每个元素的值加上 c。

请你将进行完所有操作后的矩阵输出。

输入格式
第一行包含整数 n,m,q。

接下来 n 行，每行包含 m 个整数，表示整数矩阵。

接下来 q 行，每行包含 5 个整数 x1,y1,x2,y2,c，表示一个操作。

输出格式
共 n 行，每行 m 个整数，表示所有操作进行完毕后的最终矩阵。

数据范围
1≤n,m≤1000,
1≤q≤100000,
1≤x1≤x2≤n,
1≤y1≤y2≤m,
−1000≤c≤1000,
−1000≤矩阵内元素的值≤1000
输入样例：
3 4 3
1 2 2 1
3 2 2 1
1 1 1 1
1 1 2 2 1
1 3 2 3 2
3 1 3 4 1
输出样例：
2 3 4 1
4 3 4 1
2 2 2 2
*/

void diff(std::vector<std::vector<int>> &c, int x1, int y1, int x2, int y2, int val)
{
    c[x1][y1] += val;
    if (y2 + 1 < c[0].size())
        c[x1][y2 + 1] -= val;
    if (x2 + 1 < c.size())
        c[x2 + 1][y1] -= val;
    if (x2 + 1 < c.size() && y2 + 1 < c[0].size())
        c[x2 + 1][y2 + 1] += val;
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a, b, k;
    std::cin >> a >> b >> k;
    std::vector<std::vector<int>> arr(a, std::vector<int>(b, 0));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            std::cin >> arr[i][j];
        }
    }
    std::vector<std::vector<int>> c(a + 1, std::vector<int>(b + 1, 0));
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            diff(c, i + 1, j + 1, i + 1, j + 1, arr[i][j]);
        }
    }
    while (k--)
    {
        int x1, y1, x2, y2, v;
        std::cin >> x1 >> y1 >> x2 >> y2 >> v;
        diff(c, x1, y1, x2, y2, v);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            c[i + 1][j + 1] += c[i][j + 1] + c[i + 1][j] - c[i][j]; //二维前缀和
            std::cout << c[i + 1][j + 1] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}