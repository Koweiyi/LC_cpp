/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 *
 * https://leetcode-cn.com/problems/base-7/description/
 *
 * algorithms
 * Easy (49.07%)
 * Likes:    43
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 25.2K
 * Testcase Example:  '100'
 *
 * 给定一个整数，将其转化为7进制，并以字符串形式输出。
 * 
 * 示例 1:
 * 
 * 
 * 输入: 100
 * 输出: "202"
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: -7
 * 输出: "-10"
 * 
 * 
 * 注意: 输入范围是 [-1e7, 1e7] 。
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0)
            return "0";
        string res = "";
        int n = abs(num);
        while(n){
            int a = n % 7;
            n /= 7;
            res += to_string(a);
        }
        reverse(res.begin(), res.end());
        if(num < 0)
            res = "-" + res;
        return res;
    }
};
// @lc code=end

