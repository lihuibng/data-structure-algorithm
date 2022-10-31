#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
剑指 Offer II 060. 出现频率最高的 k 个数字
给定一个整数数组 nums 和一个整数 k ，请返回其中出现频率前 k 高的元素。可以按 任意顺序 返回答案。



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


进阶：所设计算法的时间复杂度 必须 优于 O(n log n) ，其中 n 是数组大小。
*/
class Solution
{
public:
    int partition(int l, int r, vector<pair<int, int>> &vecs)
    {
        int p = l - 1;
        pair<int, int> &key = vecs[r];
        for (int i = l; i < r; i++)
        {
            if (vecs[i].second < key.second)
            {
                p++;
                swap(vecs[i], vecs[p]);
            }
        }
        p++;
        swap(vecs[r], vecs[p]);
        return p;
    }

    int quick_select(vector<pair<int, int>> &vecs, int l, int r, int k)
    {
        if (l <= r)
        {
            int p = partition(l, r, vecs);
            if (p < k)
                return quick_select(vecs, p + 1, r, k);
            else if (p == k)
                return p;
            else
            {
                return quick_select(vecs, l, p - 1, k);
            }
        }
        return -1;
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
            // cout << kv.first << " " << kv.second << endl;
        }
        int p = quick_select(values, 0, values.size() - 1, values.size() - k);
        vector<int> vecs;
        for (int i = p; i < values.size(); i++)
        {
            vecs.push_back(values[i].first);
        }

        return vecs;

        /*unordered_map<int, int> mp;
        for (auto& i : nums) {
            mp[i]++;
        }
       auto la = [&](pair<int, int>& a, pair<int, int>& b) -> bool {
                return a.second > b.second ;
           };
        priority_queue<pair<int, int>, vector<pair<int,int>>, decltype(la)> pq(la);
        for (auto& j : mp) {
            if (pq.size() == k) {
                if (pq.top().second < j.second) {
                    pq.pop();
                pq.push(j);
                }
            } else {
                pq.push(j);
            }
        }
        vector<int> vecs;
        while (!pq.empty()) {
            vecs.push_back(pq.top().first);
            pq.pop();
        }
        return vecs;
        */
    }
};

int main(int argc, char **argv)
{
    Solution s;
    vector<int> arr1 = {1, 1, 1, 2, 2, 3};
    int n = 2;
    auto res = s.topKFrequent(arr1, n);
    for (auto &k : res)
        cout << k << " ";
    cout << endl;

    return 0;
}