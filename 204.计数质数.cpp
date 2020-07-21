/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (32.89%)
 * Likes:    313
 * Dislikes: 0
 * Total Accepted:    49.2K
 * Total Submissions: 149.3K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 * 
 * 示例:
 * 
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {

        int res = 0;

        vector<bool> isPrime(n + 1, true);
        for(int i = 2 ; i < n ; i ++ )
            if(isPrime[i])
            {
                res ++;
                for(int j = 2 ; j * i < n ; j ++)
                    isPrime[i * j] = false;
            }

        return res;

    }
};
// @lc code=end

