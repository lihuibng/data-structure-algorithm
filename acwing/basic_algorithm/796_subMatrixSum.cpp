#include <iostream>
#include <vector>

/*
输入一个 n 行 m 列的整数矩阵，再输入 q 个询问，每个询问包含四个整数 x1,y1,x2,y2，表示一个子矩阵的左上角坐标和右下角坐标。

对于每个询问输出子矩阵中所有数的和。

输入格式
第一行包含三个整数 n，m，q。

接下来 n 行，每行包含 m 个整数，表示整数矩阵。

接下来 q 行，每行包含四个整数 x1,y1,x2,y2，表示一组询问。

输出格式
共 q 行，每行输出一个询问的结果。

数据范围
1≤n,m≤1000,
1≤q≤200000,
1≤x1≤x2≤n,
1≤y1≤y2≤m,
−1000≤矩阵内元素的值≤1000
输入样例：
3 4 3
1 7 2 4
3 6 2 8
2 1 2 3
1 1 2 2
2 1 3 4
1 3 3 4
输出样例：
17
27
21
*/

int prefixsum(const std::vector<std::vector<int>> &c, int x1, int y1, int x2, int y2)
{

    return c[x2][y2] - c[x1 - 1][y2] - c[x2][y1 - 1] + c[x1 - 1][y1 - 1];
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
            c[i + 1][j + 1] = c[i + 1][j] + c[i][j + 1] - c[i][j] + arr[i][j];
        }
    }
    while (k--)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        std::cout << prefixsum(c, x1, y1, x2, y2) << std::endl;
    }
    return 0;
}
