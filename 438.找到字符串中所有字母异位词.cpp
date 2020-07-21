/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 *
 * https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (41.03%)
 * Likes:    216
 * Dislikes: 0
 * Total Accepted:    17.6K
 * Total Submissions: 42.8K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * 给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
 * 
 * 字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
 * 
 * 说明：
 * 
 * 
 * 字母异位词指字母相同，但排列不同的字符串。
 * 不考虑答案输出的顺序。
 * 
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * s: "cbaebabacd" p: "abc"
 * 
 * 输出:
 * [0, 6]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
 * 起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入:
 * s: "abab" p: "ab"
 * 
 * 输出:
 * [0, 1, 2]
 * 
 * 解释:
 * 起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
 * 起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
 * 
 * 
 */

#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> vec;
        if (s.size() < p.size())
            return vec;
        int alp[26] = {0};
        int als[26] = {0};
        for (int i = 0; i < p.size(); i++)
        {
            alp[p[i] - 'a']++;
            als[s[i] - 'a']++;
        }
        int l = 0, r = p.size() - 1;
        while (r < s.size())
        {
            bool anagrams = true;
            for (int i = 0; i < 26; i++)
            {
                if (als[i] != alp[i])
                {
                    anagrams = false;
                    continue;
                }
            }
            if (anagrams)
                vec.push_back(l);
            if (r == s.size() - 1)
                break;
            als[s[++r] - 'a']++;
            als[s[l++] - 'a']--;
        }
        return vec;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<int> vec = Solution().findAnagrams("cbaebabacd", "abc");

    return 0;
}
