#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
49. 字母异位词分组
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。



示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]


提示：

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
*/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto &s : strs)
        {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            mp[tmp].emplace_back(s);
        }
        vector<vector<string>> vecs;
        for (auto &it : mp)
        {
            vecs.push_back(it.second);
        }
        return vecs;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    vector<string> arr1{"eat", "tea", "tan", "ate", "nat", "bat"};

    auto res = s.groupAnagrams(arr1);

    for (auto &k : res)
    {
        for (auto &s : k)
            cout << s << " ";
        cout << endl;
    }
    cout << endl;

    return 0;
}
