/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 *
 * https://leetcode-cn.com/problems/find-the-difference/description/
 *
 * algorithms
 * Easy (61.88%)
 * Likes:    125
 * Dislikes: 0
 * Total Accepted:    28K
 * Total Submissions: 45.2K
 * Testcase Example:  '"abcd"\n"abcde"'
 *
 * 给定两个字符串 s 和 t，它们只包含小写字母。
 * 
 * 字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
 * 
 * 请找出在 t 中被添加的字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入：
 * s = "abcd"
 * t = "abcde"
 * 
 * 输出：
 * e
 * 
 * 解释：
 * 'e' 是那个被添加的字母。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> record;
        for(int i = 0 ; i < s.size() ; i ++)
            record[s[i]] --;
        for(int i = 0 ; i < t.size() ; i ++)
            record[t[i]] ++;
        
        for(unordered_map<char, int>::iterator it = record.begin() ; it != record.end() ; it ++)
            if(it->second == 1)
                return it->first;
        
        return -1;
    }
};
// @lc code=end

