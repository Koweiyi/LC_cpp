/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.89%)
 * Likes:    623
 * Dislikes: 0
 * Total Accepted:    91.8K
 * Total Submissions: 173.3K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{

private:
    const string digistMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};
    vector<string> res;
    void solve(string digits, int index, string s)
    {
        if (index == digits.size())
        {
            res.push_back(s);
            return;
        }
        char c = digits[index];
        for (int i = 0; i < digistMap[c - '0'].size(); i++)
            solve(digits, index + 1, s + digistMap[c - '0'][i]);

        return;
    }

public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if (digits == "")
            return res;
        solve(digits, 0, "");
        return res;
    }
};
// @lc code=end
