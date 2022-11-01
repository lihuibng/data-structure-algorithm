#include <iostream>
#include <vector>
using namespace std;

/*
34. 在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。



示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]


提示：

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

*/
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                int i = mid - 1, j = mid + 1;
                while (i >= 0 && nums[i] == target)
                    i--;
                while (j < nums.size() && nums[j] == target)
                    j++;
                return {++i, --j};
            }
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }
        return {-1, -1};
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr1 = {5, 7, 7, 8, 8, 10};
    int target = 8;

    auto res = s.searchRange(arr1, target);

    for (auto &k : res)
        cout << k << " ";
    cout << endl;

    return 0;
}