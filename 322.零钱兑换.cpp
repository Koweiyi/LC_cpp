/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (38.69%)
 * Likes:    505
 * Dislikes: 0
 * Total Accepted:    67.2K
 * Total Submissions: 173.6K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 * 
 * 示例 1:
 * 
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3 
 * 解释: 11 = 5 + 5 + 1
 * 
 * 示例 2:
 * 
 * 输入: coins = [2], amount = 3
 * 输出: -1
 * 
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:
    int max_amount;
    vector<int> memo;
    int tryChange(const vector<int>& coins, int amount){
        if(amount == 0)
            return 0;

        if(memo[amount] != -1)
            return memo[amount];

        int res = max_amount;
        for(int coin : coins)
            if(amount - coin >= 0)
                res = min(res, 1 + tryChange(coins, amount - coin));
        memo[amount] = res;
        return res;

    
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        memo = vector<int>(amount + 1, amount + 1);
        memo[0] = 0;
        for(int i = 1 ; i <= amount ; i ++)
            for(int coin : coins)
                if(i - coin >= 0)
                    memo[i] = min(memo[i], 1 + memo[i - coin]);
        
        return memo.back() == amount + 1 ? -1 : memo.back();
    }
};
// @lc code=end

