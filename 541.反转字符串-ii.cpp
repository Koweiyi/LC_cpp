/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 *
 * https://leetcode-cn.com/problems/reverse-string-ii/description/
 *
 * algorithms
 * Easy (53.46%)
 * Likes:    73
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 29.6K
 * Testcase Example:  '"abcdefg"\n2'
 *
 * 给定一个字符串 s 和一个整数 k，你需要对从字符串开头算起的每隔 2k 个字符的前 k 个字符进行反转。
 * 
 * 
 * 如果剩余字符少于 k 个，则将剩余字符全部反转。
 * 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
 * 
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: s = "abcdefg", k = 2
 * 输出: "bacdfeg"
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 该字符串只包含小写英文字母。
 * 给定字符串的长度和 k 在 [1, 10000] 范围内。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<string> resStr;
public:
    string reverseStr(string s, int k) {

        if(k == 1)
            return s;

        while(s.size() >= 2 * k){
            string str = s.substr(0, k);
            reverse(str.begin(), str.end());
            str += s.substr(k, k);
            resStr.push_back(str);
            s = s.substr(2 * k, s.size() - 2 * k);
        }
        if(s.size() < k){
            reverse(s.begin(), s.end());
            resStr.push_back(s);
        }
        else {
            string str = s.substr(0, k);
            reverse(str.begin(), str.end());
            str += s.substr(k, s.size() - k);
            resStr.push_back(str);
        }

        string res = "";
        for(int i = 0 ; i < resStr.size() ; i ++)
            res += resStr[i];
        return res;
    }
};
// @lc code=end

