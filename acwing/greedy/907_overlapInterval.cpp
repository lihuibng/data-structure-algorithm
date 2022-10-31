#include <iostream>
#include <vector>
#include <algorithm>

/*
给定 N 个闭区间 [ai,bi] 以及一个线段区间 [s,t]，请你选择尽量少的区间，将指定线段区间完全覆盖。

输出最少区间数，如果无法完全覆盖则输出 −1。

输入格式
第一行包含两个整数 s 和 t，表示给定线段区间的两个端点。

第二行包含整数 N，表示给定区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示所需最少区间数。

如果无解，则输出 −1。

数据范围
1≤N≤105,
−109≤ai≤bi≤109,
−109≤s≤t≤109
输入样例：
1 5
3
-1 3
2 4
3 5
输出样例：
2
*/

int maxOverlap(std::vector<std::vector<int>> points, int s, int e)
{
    std::sort(points.begin(), points.end(), [&](const std::vector<int> &a, const std::vector<int> &b) -> bool
              { return a[0] < b[0]; });
    int cnt = 0;
    int st = s;
    for (int i = 0; i < points.size(); i++)
    {
        int ed = INT_MIN;
        int j = i;
        while (j < points.size() && points[j][0] <= st)
        {
            if (points[j][1] >= ed)
            {
                ed = points[j][1];
            }
            j++;
        }
        if (ed < st)
        {
            return -1;
        }
        cnt++;
        if (ed >= e)
        {
            return cnt;
        }
        st = ed;
        i = j - 1;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int s, e;
    std::cin >> s >> e;
    std::cin >> a;
    std::vector<std::vector<int>> arr;
    while (a--)
    {
        int st, ed;
        std::cin >> st >> ed;
        arr.push_back({st, ed});
    }

    std::cout << maxOverlap(arr, s, e) << std::endl;
    return 0;
}