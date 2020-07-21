/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 *
 * https://leetcode-cn.com/problems/longest-harmonious-subsequence/description/
 *
 * algorithms
 * Easy (47.12%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    11.5K
 * Total Submissions: 24.4K
 * Testcase Example:  '[1,3,2,2,5,2,3,7]'
 *
 * 和谐数组是指一个数组里元素的最大值和最小值之间的差别正好是1。
 * 
 * 现在，给定一个整数数组，你需要在所有可能的子序列中找到最长的和谐子序列的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,3,2,2,5,2,3,7]
 * 输出: 5
 * 原因: 最长的和谐数组是：[3,2,2,2,3].
 * 
 * 
 * 说明: 输入的数组长度最大不超过20,000.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> record;
        int res = INT_MIN;

        for(int num : nums)
            record[num] ++;
        unordered_map<int, int> copy(record.begin(), record.end());
        for(auto r : record){
            if(copy[r.first - 1])
                res = max(res, r.second + copy[r.first - 1]);
            if(copy[r.first + 1])
                res = max(res, r.second + copy[r.first + 1]);
        }

        return res == INT_MIN ? 0 : res;
    }
};
// @lc code=end

