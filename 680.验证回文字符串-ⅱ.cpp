/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 *
 * https://leetcode-cn.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (36.05%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    16.1K
 * Total Submissions: 44.8K
 * Testcase Example:  '"aba"'
 *
 * 给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
 * 
 * 示例 1:
 * 
 * 
 * 输入: "aba"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: "abca"
 * 输出: True
 * 解释: 你可以删除c字符。
 * 
 * 
 * 注意:
 * 
 * 
 * 字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {

private:
    bool isPalindrome(string s){
        int i = 0, j = s.size() - 1;
        while(i <= j)
            if(s[i ++] != s[j --])
                return false;
        return true;
    }

public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while(l <= r){
            if(s[l] != s[r])
                return isPalindrome(s.substr(l, r - l)) ||isPalindrome(s.substr(l + 1, r - l));
            l ++;
            r --;
        }
        return true;
    }
};
// @lc code=end

