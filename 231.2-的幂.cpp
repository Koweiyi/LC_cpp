/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 *
 * https://leetcode-cn.com/problems/power-of-two/description/
 *
 * algorithms
 * Easy (48.09%)
 * Likes:    197
 * Dislikes: 0
 * Total Accepted:    61.1K
 * Total Submissions: 126.9K
 * Testcase Example:  '1'
 *
 * 给定一个整数，编写一个函数来判断它是否是 2 的幂次方。
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: true
 * 解释: 2^0 = 1
 * 
 * 示例 2:
 * 
 * 输入: 16
 * 输出: true
 * 解释: 2^4 = 16
 * 
 * 示例 3:
 * 
 * 输入: 218
 * 输出: false
 * 
 */
#include<bits/stdc++.h>
using namespace std;    
// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0)
            return false;
        long x = n;
        return (x & (x - 1)) == 0;
    }
};
// @lc code=end

