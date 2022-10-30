#include <iostream>
#include <vector>

/*
给定一个整数 n，将数字 1∼n 排成一排，将会有很多种排列方法。

现在，请你按照字典序将所有的排列方法输出。

输入格式
共一行，包含一个整数 n。

输出格式
按字典序输出所有排列方案，每个方案占一行。

数据范围
1≤n≤7
输入样例：
3
输出样例：
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

void perm(
    std::vector<std::vector<int>> &res,
    std::vector<int> &cur,
    std::vector<int> &st,
    std::vector<int> &arr,
    int idx)
{
    if (idx == arr.size())
    {
        res.push_back(cur);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!st[i])
        {
            cur.push_back(arr[i]);
            st[i] = true;
            perm(res, cur, st, arr, idx + 1);
            st[i] = false;
            cur.pop_back();
        }
    }
}
int main(int argc, char *argv[])
{
    int a;
    std::cin >> a;
    std::vector<int> arr(a);
    for (int i = 0; i < a; i++)
    {
        arr[i] = i + 1;
    }
    std::vector<std::vector<int>> res;
    std::vector<int> cur, vs(a, false);
    perm(res, cur, vs, arr, 0);
    for (auto &v : res)
    {
        for (auto &k : v)
        {
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}