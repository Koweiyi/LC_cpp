/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (55.19%)
 * Likes:    172
 * Dislikes: 0
 * Total Accepted:    20.4K
 * Total Submissions: 36.9K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 * 
 * 示例 1:
 * 
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {

        vector<int> memo(n + 1, 1);

        for(int i = 2 ; i <= n ; i ++)
            for(int j = 1 ; j < i ; j ++)
                memo[i] = max(memo[i], max(j * (i - j), j * memo[i - j]));

        return memo[n];
    }
};
// @lc code=end

