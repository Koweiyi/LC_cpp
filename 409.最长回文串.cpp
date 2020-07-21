/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (54.90%)
 * Likes:    158
 * Dislikes: 0
 * Total Accepted:    43.6K
 * Total Submissions: 79.4K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 * 
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 * 
 * 注意:
 * 假设字符串的长度不会超过 1010。
 * 
 * 示例 1: 
 * 
 * 
 * 输入:
 * "abccccdd"
 * 
 * 输出:
 * 7
 * 
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> record;
        for(char c : s)
            record[c] ++;
        
        int res = 0;
        bool has_one = false; 
        for(unordered_map<char,int>::iterator it = record.begin(); it != record.end() ; ++it){
            if(!has_one && it->second % 2)
                has_one = true;
            res += (it->second / 2) * 2;
        }
        if(has_one)
            res ++;
        return res;
    }
};
// @lc code=end

