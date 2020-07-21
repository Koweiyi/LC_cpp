/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (33.20%)
 * Likes:    199
 * Dislikes: 0
 * Total Accepted:    92.9K
 * Total Submissions: 279.7K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {

        int ans = 0;
        int index = s.size() - 1;

        while(index >= 0 && s[index] == ' ')
            index --;
        while(index >= 0 && s[index] != ' '){
            ans ++;
            index --;
        }

        return ans;
    }
};
// @lc code=end

