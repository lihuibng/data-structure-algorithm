#include <iostream>
#include <vector>
#include <string>
#include <queue>

/*
给定一个 n×m 的二维整数数组，用来表示一个迷宫，数组中只包含 0 或 1，其中 0 表示可以走的路，1 表示不可通过的墙壁。

最初，有一个人位于左上角 (1,1) 处，已知该人每次可以向上、下、左、右任意一个方向移动一个位置。

请问，该人从左上角移动至右下角 (n,m) 处，至少需要移动多少次。

数据保证 (1,1) 处和 (n,m) 处的数字为 0，且一定至少存在一条通路。

输入格式
第一行包含两个整数 n 和 m。

接下来 n 行，每行包含 m 个整数（0 或 1），表示完整的二维数组迷宫。

输出格式
输出一个整数，表示从左上角移动至右下角的最少移动次数。

数据范围
1≤n,m≤100
输入样例：
5 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0
输出样例：
8
*/

int walkMaze(const std::vector<std::string> &res,
             std::vector<std::vector<int>> &dist,
             int m,
             int n)
{
    dist[0][0] = 0;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    std::queue<std::pair<int, int>> q;
    q.push(std::make_pair(0, 0));
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = t.first + dx[i];
            int ny = t.second + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && res[nx][ny] == '0' && dist[nx][ny] == INT_MAX)
            {
                q.push(std::make_pair(nx, ny));
                dist[nx][ny] = dist[t.first][t.second] + 1;
            }
        }
    }
    return dist[m - 1][n - 1];
}
int main(int argc, char *argv[])
{
    int a, b;
    std::cin >> a >> b;

    std::vector<std::string> arr(a, std::string(b, '0'));
    std::vector<std::vector<int>> dist(a, std::vector<int>(b, INT_MAX));
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            char c;
            std::cin >> c;
            arr[i][j] = c;
        }
    }

    std::cout << walkMaze(arr, dist, a, b) << std::endl;

    return 0;
}