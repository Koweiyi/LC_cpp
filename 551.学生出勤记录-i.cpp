/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 *
 * https://leetcode-cn.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (51.34%)
 * Likes:    41
 * Dislikes: 0
 * Total Accepted:    15K
 * Total Submissions: 29.2K
 * Testcase Example:  '"PPALLP"'
 *
 * 给定一个字符串来代表一个学生的出勤记录，这个记录仅包含以下三个字符：
 * 
 * 
 * 'A' : Absent，缺勤
 * 'L' : Late，迟到
 * 'P' : Present，到场
 * 
 * 
 * 如果一个学生的出勤记录中不超过一个'A'(缺勤)并且不超过两个连续的'L'(迟到),那么这个学生会被奖赏。
 * 
 * 你需要根据这个学生的出勤记录判断他是否会被奖赏。
 * 
 * 示例 1:
 * 
 * 输入: "PPALLP"
 * 输出: True
 * 
 * 
 * 示例 2:
 * 
 * 输入: "PPALLL"
 * 输出: False
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {

        int abcent = 0;
        bool late = false;
        for(int i = 0 ; i < s.size() ; i ++){
            if(s[i] == 'A')
                abcent ++;
            else if(s[i] == 'L'){
                int ed = i + 1;
                while(ed < s.size() && s[ed] == 'L')
                    ed ++;
                if(ed - i > 2)
                    late = true;
                i = ed - 1;
            }
        }
        
        if(abcent < 2 && !late)
            return true;
        else return false; 
    }
};
// @lc code=end

