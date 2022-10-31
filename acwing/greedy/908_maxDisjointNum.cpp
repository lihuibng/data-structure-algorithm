#include <iostream>
#include <vector>

/*
给定 N 个闭区间 [ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）。

输出可选取区间的最大数量。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示可选取区间的最大数量。

数据范围
1≤N≤105,
−109≤ai≤bi≤109
输入样例：
3
-1 1
2 4
3 5
输出样例：
2
*/

int maxDisjointNum(std::vector<std::vector<int>> points)
{
    std::sort(points.begin(), points.end(), [&](const std::vector<int> &a, const std::vector<int> &b) -> bool
              { return a[0] < b[0]; });
    int cnt = 1;
    int st = points[0][0], ed = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i][0] <= ed)
        {
            ed = std::min(ed, points[i][1]);
        }
        else
        {
            st = points[i][0];
            ed = points[i][1];
            cnt++;
        }
    }
    return cnt;
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> a;
    std::vector<std::vector<int>> arr;
    while (a--)
    {
        int st, ed;
        std::cin >> st >> ed;
        arr.push_back({st, ed});
    }

    std::cout << maxDisjointNum(arr) << std::endl;
    return 0;
}