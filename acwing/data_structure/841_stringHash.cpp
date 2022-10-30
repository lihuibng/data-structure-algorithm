#include <iostream>
#include <vector>
/*
给定一个长度为 n 的字符串，再给定 m 个询问，每个询问包含四个整数 l1,r1,l2,r2，请你判断 [l1,r1] 和 [l2,r2] 这两个区间所包含的字符串子串是否完全相同。

字符串中只包含大小写英文字母和数字。

输入格式
第一行包含整数 n 和 m，表示字符串长度和询问次数。

第二行包含一个长度为 n 的字符串，字符串中只包含大小写英文字母和数字。

接下来 m 行，每行包含四个整数 l1,r1,l2,r2，表示一次询问所涉及的两个区间。

注意，字符串的位置从 1 开始编号。

输出格式
对于每个询问输出一个结果，如果两个字符串子串完全相同则输出 Yes，否则输出 No。

每个结果占一行。

数据范围
1≤n,m≤105
输入样例：
8 3
aabbaabb
1 3 5 7
1 3 6 8
1 2 1 2
输出样例：
Yes
No
Yes
*/

const int M = 131;
const unsigned long long Q = ULLONG_MAX;

struct StringHash
{
    std::vector<unsigned long long> p;
    std::vector<unsigned long long> h;

    StringHash(std::string str)
    {
        p.resize(str.size() + 1);
        h.resize(str.size() + 1);
        hash(str);
    }

    StringHash(int n)
    {
        p.resize(n + 1);
        h.resize(n + 1);
    }

    void hash(std::string str)
    {
        p[0] = 1;
        h[0] = 0;
        for (int i = 0; i < str.size(); i++)
        {
            p[i + 1] = p[i] * M;
            h[i + 1] = (h[i] * M + str[i]) % Q;
        }
    }

    unsigned long long get(int r)
    {
        return h[r];
    }

    unsigned long long query(int l, int r)
    {
        return h[r] - h[l - 1] * p[r - l + 1];
    }
};

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    std::cin >> a >> b;
    StringHash sh(a);
    std::string str;
    std::cin >> str;
    sh.hash(str);
    while (b--)
    {
        int l1, r1, l2, r2;
        std::cin >> l1 >> r1 >> l2 >> r2;
        if (sh.query(l1, r1) == sh.query(l2, r2))
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    return 0;
}