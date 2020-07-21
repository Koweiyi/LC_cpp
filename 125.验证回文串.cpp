/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.97%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    89.6K
 * Total Submissions: 208.6K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char c : s)
            if(isalpha(c) || isdigit(c))
                temp += tolower(c);

        int i = 0, j = temp.size() - 1;
        while(i < j)
            if(temp[i++] != temp[j--])
                return false;

        return true;
    }
};
// @lc code=end

