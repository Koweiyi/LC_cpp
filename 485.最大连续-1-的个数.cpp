/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 *
 * https://leetcode-cn.com/problems/max-consecutive-ones/description/
 *
 * algorithms
 * Easy (56.47%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    39.3K
 * Total Submissions: 69.6K
 * Testcase Example:  '[1,0,1,1,0,1]'
 *
 * 给定一个二进制数组， 计算其中最大连续1的个数。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,1,0,1,1,1]
 * 输出: 3
 * 解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
 * 
 * 
 * 注意：
 * 
 * 
 * 输入的数组只包含 0 和1。
 * 输入数组的长度是正整数，且不超过 10,000。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0;
        int begin = 0;
        int len = nums.size();
        while(begin < len){
            while(begin < len && nums[begin] != 1)
                begin ++;
            int end = begin;
            while(end < len && nums[end] == 1)
                end ++;
            
            res = max(res, end - begin);
            begin = end;
        }

        return res;

    }
};
// @lc code=end

