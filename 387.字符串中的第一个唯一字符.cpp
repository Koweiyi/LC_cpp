/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 *
 * https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (43.97%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    67.5K
 * Total Submissions: 153.3K
 * Testcase Example:  '"leetcode"'
 *
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
 * 
 * 案例:
 * 
 * 
 * s = "leetcode"
 * 返回 0.
 * 
 * s = "loveleetcode",
 * 返回 2.
 * 
 * 
 * 
 * 
 * 注意事项：您可以假定该字符串只包含小写字母。
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char, int> record;
        for(char c : s)
            record[c] ++;
        
        for(int i = 0 ; i < s.size() ; i ++)
            if(record[s[i]] == 1)
                return i;
        
        return -1;
    }
};
// @lc code=end

