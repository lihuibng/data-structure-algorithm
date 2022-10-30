#include <iostream>
#include <vector>

/*
给定一个长度为 n 的整数序列 a1,a2,…,an 以及一个长度为 m 的整数序列 b1,b2,…,bm。

请你判断 a 序列是否为 b 序列的子序列。

子序列指序列的一部分项按原有次序排列而得的序列，例如序列 {a1,a3,a5} 是序列 {a1,a2,a3,a4,a5} 的一个子序列。

输入格式
第一行包含两个整数 n,m。

第二行包含 n 个整数，表示 a1,a2,…,an。

第三行包含 m 个整数，表示 b1,b2,…,bm。

输出格式
如果 a 序列是 b 序列的子序列，输出一行 Yes。

否则，输出 No。

数据范围
1≤n≤m≤105,
−109≤ai,bi≤109
输入样例：
3 5
1 3 5
1 2 3 4 5
输出样例：
Yes
*/


bool subSeqCheck(const std::vector<int> &c1, const std::vector<int> &c2)
{
    int i = 0, j = 0;
    while (j < c2.size())
    {
        if (i < c1.size() && c1[i] == c2[j])
        {
            i++;
        }
        j++;
    }

    return i == c1.size();
}

int main(int argc, char *argv[])
{
    // std::ios_base::sync_with_stdio(false);
    // std::cin.tie(0);
    // std::cout.tie(0);

    int a, b;
    std::cin >> a >> b;
    std::vector<int> arr1;
    std::vector<int> arr2;
    while (a--)
    {
        int k;
        std::cin >> k;
        arr1.push_back(k);
    }
    while (b--)
    {
        int k;
        std::cin >> k;
        arr2.push_back(k);
    }
    auto v = subSeqCheck(arr1, arr2);

    if (v)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;
    return 0;
}