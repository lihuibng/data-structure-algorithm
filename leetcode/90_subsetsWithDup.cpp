#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。



示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：

输入：nums = [0]
输出：[[],[0]]


提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> cur;
    void dfs(bool flag, int index, vector<int> &nums)
    {
        if (index == nums.size())
        {
            res.push_back(cur);
            return;
        }
        dfs(false, index + 1, nums);
        if (!flag && index > 0 && nums[index - 1] == nums[index])
            return;
        cur.push_back(nums[index]);
        dfs(true, index + 1, nums);
        cur.pop_back();
    }
    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used)
    {
        res.push_back(cur);
        for (int i = startIndex; i < nums.size(); i++)
        {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 而我们要对同一树层使用过的元素进行跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
            {
                continue;
            }
            cur.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<bool> flags(nums.size(), false);
        backtracking(nums, 0, flags);
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr1 = {1, 4, 3, 2};

    auto res = s.subsetsWithDup(arr1);

    for (auto v : res)
    {
        for (auto &k : v)
            cout << k << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
