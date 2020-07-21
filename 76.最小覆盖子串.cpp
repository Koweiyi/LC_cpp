/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.49%)
 * Likes:    348
 * Dislikes: 0
 * Total Accepted:    24.7K
 * Total Submissions: 69.5K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string minWindow(string s, string t)
    {

        unordered_map<char, int> record;
        for (auto c : t)
            record[c]++;
        int left = 0, maxlength = s.size() + 1, start = left, cnt = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (--record[s[i]] >= 0)
                cnt++;
            while (cnt == t.size())
            {
                if (maxlength > i - left + 1)
                {
                    maxlength = i - left + 1;
                    start = left;
                }
                if (++record[s[left++]] > 0)
                    cnt--;
            }
        }
        return maxlength == s.size() + 1 ? "" : s.substr(start, maxlength);
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    string s = "ABECODEBANC";
    string t = "ABC";
    string str = Solution().minWindow(s, t);
    cout << str;
    return 0;
}
