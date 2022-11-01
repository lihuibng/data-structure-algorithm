#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。



示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]


提示：

1 <= nums.length <= 105
k 的取值范围是 [1, 数组中不相同的元素的个数]
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的


进阶：你所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
*/

class Solution
{
public:
    int partition(int l, int r, vector<pair<int, int>> &nums)
    {
        auto key = nums[r];
        int p = l - 1;
        for (int i = l; i < r; i++)
        {
            if (nums[i].second <= key.second)
            {
                p++;
                if (p != i)
                    swap(nums[p], nums[i]);
            }
        }
        swap(nums[p + 1], nums[r]);
        return p + 1;
    }

    int quickSelect(int l, int r, vector<pair<int, int>> &nums, int k)
    {
        int i = partition(l, r, nums);
        if (i == k)
            return i;
        if (i < k)
            return quickSelect(i + 1, r, nums, k);
        else
            return quickSelect(l, i - 1, nums, k);
    }

    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> occurrences;
        for (auto &v : nums)
        {
            occurrences[v]++;
        }

        vector<pair<int, int>> values;
        for (auto &kv : occurrences)
        {
            values.push_back(kv);
        }
        int i = quickSelect(0, values.size() - 1, values, values.size() - k);
        vector<int> res;
        for (; i < values.size(); i++)
        {
            res.push_back(values[i].first);
        }
        return res;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<int> arr1 = {1, 1, 1, 2, 2, 3};
    int k = 2;
    auto res = s.topKFrequent(arr1, k);

    for (auto &k : res)
        cout << k << " ";
    cout << endl;

    return 0;
}