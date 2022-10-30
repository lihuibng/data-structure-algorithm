#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

/*
在一个 3×3 的网格中，1∼8 这 8 个数字和一个 x 恰好不重不漏地分布在这 3×3 的网格中。

例如：

1 2 3
x 4 6
7 5 8
在游戏过程中，可以把 x 与其上、下、左、右四个方向之一的数字交换（如果存在）。

我们的目的是通过交换，使得网格变为如下排列（称为正确排列）：

1 2 3
4 5 6
7 8 x
例如，示例中图形就可以通过让 x 先后与右、下、右三个方向的数字交换成功得到正确排列。

交换过程如下：

1 2 3   1 2 3   1 2 3   1 2 3
x 4 6   4 x 6   4 5 6   4 5 6
7 5 8   7 5 8   7 x 8   7 8 x
现在，给你一个初始网格，请你求出得到正确排列至少需要进行多少次交换。

输入格式
输入占一行，将 3×3 的初始网格描绘出来。

例如，如果初始网格如下所示：

1 2 3
x 4 6
7 5 8
则输入为：1 2 3 x 4 6 7 5 8

输出格式
输出占一行，包含一个整数，表示最少交换次数。

如果不存在解决方案，则输出 −1。

输入样例：
2 3 4 1 5 x 7 6 8
输出样例
19
*/

std::vector<std::string> nextStr(const std::string &s, int pos)
{
    std::string t = s;
    int r = pos / 3, c = pos % 3;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    std::vector<std::string> res;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dx[i], nc = c + dy[i];
        if (nr >= 0 && nr < 3 && nc >= 0 && nc < 3)
        {
            std::swap(t[nr * 3 + nc], t[r * 3 + c]);
            res.push_back(t);
            std::swap(t[nr * 3 + nc], t[r * 3 + c]);
        }
    }
    return res;
}

int bfs(std::unordered_map<std::string, int> &mp,
        const std::string &start,
        const std::string &end)
{
    std::queue<std::string> q;
    q.push(start);
    if (start == end)
        return 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        auto strs = nextStr(t, t.find('x'));
        for (auto &str : strs)
        {
            if (mp.count(str))
                continue;
            if (str == end)
            {
                return mp[t] + 1;
            }
            else
            {
                mp[str] = mp[t] + 1;
                q.push(str);
            }
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::vector<char> arr;
    for (int i = 0; i < 9; i++)
    {
        char c;
        std::cin >> c;
        arr.push_back(c);
    }
    std::unordered_map<std::string, int> mp;
    std::string start(arr.begin(), arr.end());
    std::string end("12345678x");
    std::cout << bfs(mp, start, end) << std::endl;
    return 0;
}