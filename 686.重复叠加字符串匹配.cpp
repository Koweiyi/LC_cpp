/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 *
 * https://leetcode-cn.com/problems/repeated-string-match/description/
 *
 * algorithms
 * Easy (33.94%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    10K
 * Total Submissions: 29.5K
 * Testcase Example:  '"abcd"\n"cdabcdab"'
 *
 * 给定两个字符串 A 和 B, 寻找重复叠加字符串A的最小次数，使得字符串B成为叠加后的字符串A的子串，如果不存在则返回 -1。
 * 
 * 举个例子，A = "abcd"，B = "cdabcdab"。
 * 
 * 答案为 3， 因为 A 重复叠加三遍后为 “abcdabcdabcd”，此时 B 是其子串；A 重复叠加两遍后为"abcdabcd"，B
 * 并不是其子串。
 * 
 * 注意:
 * 
 * A 与 B 字符串的长度在1和10000区间范围内。
 * 
 */

#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int i = 1 ;
        string s = A;
        while(A.find(B) == string::npos){
            A += s;
            i ++;
            if(A.size() > B.size() + s.size())
                break;
        }
        return A.find(B) == -1 ? -1 : i;
    }
};
// @lc code=end

