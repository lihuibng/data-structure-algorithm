#include <iostream>
#include <vector>
#include <deque>

/*
给定一个大小为 n≤106 的数组。

有一个大小为 k 的滑动窗口，它从数组的最左边移动到最右边。

你只能在窗口中看到 k 个数字。

每次滑动窗口向右移动一个位置。

以下是一个例子：

该数组为 [1 3 -1 -3 5 3 6 7]，k 为 3。

窗口位置	最小值	最大值
[1 3 -1] -3 5 3 6 7	-1	3
1 [3 -1 -3] 5 3 6 7	-3	3
1 3 [-1 -3 5] 3 6 7	-3	5
1 3 -1 [-3 5 3] 6 7	-3	5
1 3 -1 -3 [5 3 6] 7	3	6
1 3 -1 -3 5 [3 6 7]	3	7
你的任务是确定滑动窗口位于每个位置时，窗口中的最大值和最小值。

输入格式
输入包含两行。

第一行包含两个整数 n 和 k，分别代表数组长度和滑动窗口的长度。

第二行有 n 个整数，代表数组的具体数值。

同行数据之间用空格隔开。

输出格式
输出包含两个。

第一行输出，从左至右，每个位置滑动窗口中的最小值。

第二行输出，从左至右，每个位置滑动窗口中的最大值。

输入样例：
8 3
1 3 -1 -3 5 3 6 7
输出样例：
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/
#include <iostream>
#include <vector>
#include <stack>

std::vector<int> minSlidingWindow(const std::vector<int> &arr, int k)
{
    std::deque<int> dq;
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!dq.empty() && arr[dq.back()] >= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        while (i - k >= dq.front())
            dq.pop_front();
        if (i >= k - 1)
        {
            res.push_back(arr[dq.front()]);
        }
    }
    return res;
}

std::vector<int> maxSlidingWindow(const std::vector<int> &arr, int k)
{
    std::deque<int> dq;
    std::vector<int> res;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        while (i - k >= dq.front())
            dq.pop_front();
        if (i >= k - 1)
        {
            res.push_back(arr[dq.front()]);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    int m, n;
    std::cin >> m >> n;
    std::vector<int> arr;
    while (m--)
    {
        int a;
        std::cin >> a;
        arr.push_back(a);
    }

    auto v1 = minSlidingWindow(arr, n);
    auto v2 = maxSlidingWindow(arr, n);
    for (auto &k : v1)
        std::cout << k << " ";
    std::cout << std::endl;
    for (auto &k : v2)
        std::cout << k << " ";
    std::cout << std::endl;
    return 0;
}
