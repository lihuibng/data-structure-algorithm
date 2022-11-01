#include <iostream>
using namespace std;

/*
367. 有效的完全平方数
给定一个 正整数 num ，编写一个函数，如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

进阶：不要 使用任何内置的库函数，如  sqrt 。



示例 1：

输入：num = 16
输出：true
示例 2：

输入：num = 14
输出：false


提示：

1 <= num <= 2^31 - 1
*/
class Solution
{
public:
    int binSearch(int num)
    {
        long s = 0, e = num;
        while (s <= e)
        {
            long mid = s + (e - s) / 2;
            // long pro = mid * mid;
            if (num / mid == mid)
                return mid;
            else if (num / mid > mid)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return s;
    }
    bool isPerfectSquare(int num)
    {
        if (num == 1 || num == 4)
            return true;
        int i = binSearch(num);
        return num / i == i && num % i == 0;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int b = 4;

    auto res = s.isPerfectSquare(b);

    cout << res << " ";
    cout << endl;

    return 0;
}