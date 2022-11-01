#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。



示例 1：

输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。
示例 2：

输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。
示例 3：

输入：digits = [0]
输出：[1]


提示：

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1, j = digits.size() - 1;
        vector<int> res;
        while (j >= 0)
        {
            int sum = carry + digits[j];
            carry = sum / 10;
            res.push_back(sum % 10);
            j--;
        }
        if (carry > 0)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3};

    auto res = s.plusOne(arr1);

    for (auto &k : res)
        cout << k << " ";
    cout << endl;

    return 0;
}