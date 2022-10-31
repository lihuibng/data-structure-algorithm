#include <iostream>
#include <vector>
#include <queue>

/*
给定 N 个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。

输出最小组数。

输入格式
第一行包含整数 N，表示区间数。

接下来 N 行，每行包含两个整数 ai,bi，表示一个区间的两个端点。

输出格式
输出一个整数，表示最小组数。

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

int groupInterval(std::vector<std::vector<int>> points)
{
    std::sort(points.begin(), points.end(), [&](const std::vector<int> &a, const std::vector<int> &b) -> bool
              { return a[0] < b[0]; });
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < points.size(); i++)
    {
        if (!pq.empty() && pq.top() < points[i][0])
        {
            pq.pop();
        }
        pq.push(points[i][1]);
    }
    return pq.size();
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

    std::cout << groupInterval(arr) << std::endl;
    return 0;
}