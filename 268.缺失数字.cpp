/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 *
 * https://leetcode-cn.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (54.75%)
 * Likes:    231
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 102.6K
 * Testcase Example:  '[3,0,1]'
 *
 * 给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
 * 
 * 示例 1:
 * 
 * 输入: [3,0,1]
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [9,6,4,2,3,5,7,0,1]
 * 输出: 8
 * 
 * 
 * 说明:
 * 你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        for(int i = 1 ; i < nums.size(); i ++ )
            nums[0] ^= nums[i];
        
        for(int i = 0 ; i <= nums.size() ; i ++ )
            nums[0] ^= i;
        
        return nums[0];
    }
};
// @lc code=end

