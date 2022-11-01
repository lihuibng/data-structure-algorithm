#include<iostream>
#include <vector>
using namespace std;

/*
238. 除自身以外数组的乘积
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。



示例 1:

输入: nums = [1,2,3,4]
输出: [24,12,8,6]
示例 2:

输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]


提示：

2 <= nums.length <= 105
-30 <= nums[i] <= 30
保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内


进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/


class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> pre(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        vector<int> res(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
            {
                pre[i] = nums[i] * pre[i - 1];
            }
            else
            {
                pre[i] = nums[i];
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            if (i != nums.size() - 1)
            {
                suffix[i] = nums[i] * suffix[i + 1];
            }
            else
            {
                suffix[i] = nums[i];
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                res[i] = suffix[1];
            }
            else if (i == nums.size() - 1)
            {
                res[i] = pre[i - 1];
            }
            else
            {
                res[i] = pre[i - 1] * suffix[i + 1];
            }
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4};

    auto res = s.productExceptSelf(arr1);

    for (auto &k : res)
        cout << k << " ";
    cout << endl;

    return 0;
}