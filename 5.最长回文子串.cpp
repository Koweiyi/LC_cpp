/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (28.65%)
 * Likes:    1788
 * Dislikes: 0
 * Total Accepted:    189.7K
 * Total Submissions: 662K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int max_index = 0, max_len = 0;
        for(int i = 0 ; i < s.size() ; i ++ )
        {
            int len = 1;
            int left = i - 1;
            while(left >= 0 && s[left] == s[left + 1]){
                left --;
                len ++;
            }
            int right = i + 1;
            while(right < s.size() && s[right] == s[right - 1]){
                right ++;
                len ++;
            }
            while(left >= 0  && right < s.size())
            {
                if(s[left] == s[right]){
                    left --;
                    right ++;
                    len += 2;
                }
                else 
                    break;
            }
            if(len > max_len){
                max_index = left + 1;
                max_len = len;
            }
        } 

        return s.substr(max_index, max_len);

        

    }
};
// @lc code=end

