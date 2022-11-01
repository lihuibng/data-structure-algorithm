#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。





示例 1：

输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：

输入：digits = ""
输出：[]
示例 3：

输入：digits = "2"
输出：["a","b","c"]


提示：

0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
*/
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> mp{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> vec;
        string st = "";

        mapping(vec, st, 0, digits, mp);
        return vec;
    }

    void mapping(vector<string> &vec, string st, int i, const string &digits, unordered_map<char, string> &mp)
    {
        if (i == digits.size() && i > 0)
        {
            vec.push_back(st);
        }
        if (i < digits.size())
        {
            string tmp = mp[digits[i]];
            for (auto c : tmp)
            {
                st.push_back(c);
                mapping(vec, st, i + 1, digits, mp);
                st.pop_back();
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    string str = "23";

    auto res = s.letterCombinations(str);

    for (auto &k : res)
        cout << k << " ";
    cout << endl;

    return 0;
}