/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (54.99%)
 * Likes:    339
 * Dislikes: 0
 * Total Accepted:    45K
 * Total Submissions: 81.9K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 * 示例 1:
 * 
 * 输入: n = 12
 * 输出: 3 
 * 解释: 12 = 4 + 4 + 4.
 * 
 * 示例 2:
 * 
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> memo(n + 1, n + 1);
        memo[0] = 0;
        memo[1] = 1;
        for(int i = 2; i <= n ; i ++)
            for(int j = 1 ; j * j <= i ; j ++)
                memo[i] = min(memo[i], 1 + memo[i - j * j]);
        
        return memo[n];
    }
};
// @lc code=end

