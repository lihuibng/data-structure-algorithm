#include <iostream>
using namespace std;

/*
371. 两整数之和
给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。

示例 1：

输入：a = 1, b = 2
输出：3
示例 2：

输入：a = 2, b = 3
输出：5

提示：
-1000 <= a, b <= 1000
*/

class Solution
{
public:
    int getSum(int a, int b)
    {
        int sum = a, carry = 0;
        while (b)
        {
            sum = a ^ b;
            carry = ((unsigned)a & b) << 1;
            // if (carry == 0) return sum;
            a = sum;
            b = carry;
        }

        return sum;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    int a = 1, b = 2;
    cout << s.getSum(a, b) << endl;

    return 0;
}