/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 *
 * https://leetcode-cn.com/problems/maximum-average-subarray-i/description/
 *
 * algorithms
 * Easy (38.55%)
 * Likes:    91
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 38.5K
 * Testcase Example:  '[1,12,-5,-6,50,3]\n4'
 *
 * 给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
 * 
 * 示例 1:
 * 
 * 输入: [1,12,-5,-6,50,3], k = 4
 * 输出: 12.75
 * 解释: 最大平均数 (12-5-6+50)/4 = 51/4 = 12.75
 * 
 * 
 * 
 * 
 * 注意:
 * 
 * 
 * 1 <= k <= n <= 30,000。
 * 所给数据范围 [-10,000，10,000]。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std; 
// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        double sum, res = LONG_MIN;

        int l = 0, r = k;
        for(int i = 0 ; i < k ; i ++)
            sum += nums[i];
        res = max(res, sum / k);
        while(r < nums.size()){
            sum -= nums[r - k];
            sum += nums[r];
            res = max(res, sum / k);
            r ++;
        }
        return res;
    }
};
// @lc code=end

