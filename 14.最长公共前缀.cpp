/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (36.66%)
 * Likes:    921
 * Dislikes: 0
 * Total Accepted:    213.1K
 * Total Submissions: 581.3K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";

        int len = strs[0].size();
        for(int i = 1 ; i < strs.size() ; i ++ )
            for(int j = 0 ; j < len && j < strs[i].size() ; j ++)
                if(strs[i][j] != strs[0][j])
                {
                    len = j;
                    break;
                }
        
        for(string str : strs)
            if(str.size() < len)
                len = str.size();
        return strs[0].substr(0, len);
    }
};
// @lc code=end

