#include <iostream>
#include <vector>
#include <iomanip>

/*
给定一个浮点数 n，求它的三次方根。

输入格式
共一行，包含一个浮点数 n。

输出格式
共一行，包含一个浮点数，表示问题的解。

注意，结果保留 6 位小数。

数据范围
−10000≤n≤10000
输入样例：
1000.00
输出样例：
10.000000
*/

const double EPS = 1.0e-8;

double cubeRoot(double f)
{
    double l = -10000, r = 10000;
    while (r - l >= EPS)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= f)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main(int argc, char *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);

    double n;
    std::cin >> n;
    std::cout << std::fixed << std::setprecision(6) << cubeRoot(n) << std::endl;

    return 0;
}