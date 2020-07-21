/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 *
 * https://leetcode-cn.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (43.36%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    33.1K
 * Total Submissions: 76.2K
 * Testcase Example:  '16'
 *
 * 给定一个正整数 num，编写一个函数，如果 num 是一个完全平方数，则返回 True，否则返回 False。
 * 
 * 说明：不要使用任何内置的库函数，如  sqrt。
 * 
 * 示例 1：
 * 
 * 输入：16
 * 输出：True
 * 
 * 示例 2：
 * 
 * 输入：14
 * 输出：False
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long n = num;
        if(n < 4)
            return n == 1;
            long long l = 2;
            long long r = n / 2;
            while(l <= r){
                long long mid = (r - l) / 2 + l;
                if(mid * mid == n)
                    return true;
                else if(mid * mid > n)
                    r = mid - 1;
                else l = mid + 1;
            } 
            return false;
    }
};
// @lc code=end

