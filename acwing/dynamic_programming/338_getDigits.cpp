#include <iostream>
#include <vector>

/*
给定两个整数 a 和 b，求 a 和 b 之间的所有数字中 0∼9 的出现次数。

例如，a=1024，b=1032，则 a 和 b 之间共有 9 个数如下：

1024 1025 1026 1027 1028 1029 1030 1031 1032

其中 0 出现 10 次，1 出现 10 次，2 出现 7 次，3 出现 3 次等等…

输入格式
输入包含多组测试数据。

每组测试数据占一行，包含两个整数 a 和 b。

当读入一行为 0 0 时，表示输入终止，且该行不作处理。

输出格式
每组数据输出一个结果，每个结果占一行。

每个结果包含十个用空格隔开的数字，第一个数字表示 0 出现的次数，第二个数字表示 1 出现的次数，以此类推。

数据范围
0<a,b<100000000
输入样例：
1 10
44 497
346 542
1199 1748
1496 1403
1004 503
1714 190
1317 854
1976 494
1001 1960
0 0
输出样例：
1 2 1 1 1 1 1 1 1 1
85 185 185 185 190 96 96 96 95 93
40 40 40 93 136 82 40 40 40 40
115 666 215 215 214 205 205 154 105 106
16 113 19 20 114 20 20 19 19 16
107 105 100 101 101 197 200 200 200 200
413 1133 503 503 503 502 502 417 402 412
196 512 186 104 87 93 97 97 142 196
398 1375 398 398 405 499 499 495 488 471
294 1256 296 296 296 296 287 286 286 247
*/

int getDigit(int n)
{
    int res = 0;
    while (n)
    {
        res++;
        n /= 10;
    }
    return res;
}

int countNum(int n, int k)
{
    int d = getDigit(n);
    int res = 0;
    for (int i = 1; i <= d; i++)
    {
        long long p = pow(10, i - 1);
        long long l = n / p / 10;
        long long r = n % p;
        long long cur = n / p % 10;
        if (k)
            res += l * p;
        if (k == 0 && l)
            res += (l - 1) * p;
        if (cur > k && (k || l))
            res += p;
        if (cur == k && (k || l))
            res += r + 1;
    }
    return res;
}

int main(int argc, char *argv[])
{
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    while (std::cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        if (a > b)
            std::swap(a, b);
        for (int i = 0; i <= 9; ++i)
        {
            std::cout << countNum(b, i) - countNum(a - 1, i) << ' ';
        }
        std::cout << std::endl;
    }
    return 0;
}