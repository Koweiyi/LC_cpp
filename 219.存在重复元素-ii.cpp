/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (38.90%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 119.1K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给定一个整数数组和一个整数 k，判断数组中是否存在两个不同的索引 i 和 j，使得 nums [i] = nums [j]，并且 i 和 j 的差的
 * 绝对值 至多为 k。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: nums = [1,2,3,1], k = 3
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入: nums = [1,0,1,1], k = 1
 * 输出: true
 * 
 * 示例 3:
 * 
 * 输入: nums = [1,2,3,1,2,3], k = 2
 * 输出: false
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> record;
        for(int i = 0 ; i <= k ; i ++){
            if(i < nums.size())
                record.insert(nums[i]);
            else {
                if(record.size() < nums.size())
                    return true;    
                else 
                    return false;
            } 
        }
        if(record.size() < k + 1)
            return true;
        
        for(int i = k ; i < nums.size() - 1; i ++){
            record.erase(nums[i - k]);
            record.insert(nums[i + 1]);
            if(record.size() < k + 1)
                return true;
        }

        return false;
    }
};
// @lc code=end

