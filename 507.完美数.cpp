/*
 * @lc app=leetcode.cn id=507 lang=cpp
 *
 * [507] 完美数
 *
 * https://leetcode-cn.com/problems/perfect-number/description/
 *
 * algorithms
 * Easy (38.18%)
 * Likes:    63
 * Dislikes: 0
 * Total Accepted:    14.5K
 * Total Submissions: 38K
 * Testcase Example:  '28'
 *
 * 对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
 * 
 * 给定一个 整数 n， 如果他是完美数，返回 True，否则返回 False
 * 
 * 
 * 
 * 示例：
 * 
 * 输入: 28
 * 输出: True
 * 解释: 28 = 1 + 2 + 4 + 7 + 14
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 输入的数字 n 不会超过 100,000,000. (1e8)
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool checkPerfectNumber(int num) {

        if(num == 1)
            return false;

        int sum = 1;

        for(int i = 2 ; i <= sqrt(num) ; i ++)
            if(num % i == 0)
                sum += i + num / i;
        
        return sum == num;
        
    }
};
// @lc code=end

