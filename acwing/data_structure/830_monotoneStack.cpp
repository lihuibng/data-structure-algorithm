#include <iostream>
#include <vector>
#include <stack>

/*
给定一个长度为 N 的整数数列，输出每个数左边第一个比它小的数，如果不存在则输出 −1。

输入格式
第一行包含整数 N，表示数列长度。

第二行包含 N 个整数，表示整数数列。

输出格式
共一行，包含 N 个整数，其中第 i 个数表示第 i 个数的左边第一个比它小的数，如果不存在则输出 −1。

数据范围
1≤N≤105
1≤数列中元素≤109
输入样例：
5
3 4 2 7 5
输出样例：
-1 3 -1 2 2
*/


std::vector<int> monotoneStack(const std::vector<int> &arr)
{
    std::stack<int> st;
    std::vector<int> res(arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
            res[i] = -1;
        else
            res[i] = arr[st.top()];
        st.push(i);
    }
    return res;
}

int main(int argc, char *argv[])
{
    int m;
    std::cin >> m;
    std::vector<int> arr;
    while (m--)
    {
        int a;
        std::cin >> a;
        arr.push_back(a);
    }

    auto v = monotoneStack(arr);
    for (auto &k : v)
        std::cout << k << " ";
    std::cout << std::endl;
    return 0;
}