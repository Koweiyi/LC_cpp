/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 *
 * https://leetcode-cn.com/problems/degree-of-an-array/description/
 *
 * algorithms
 * Easy (53.30%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    16.8K
 * Total Submissions: 31.6K
 * Testcase Example:  '[1,2,2,3,1]'
 *
 * 给定一个非空且只包含非负数的整数数组 nums, 数组的度的定义是指数组里任一元素出现频数的最大值。
 * 
 * 你的任务是找到与 nums 拥有相同大小的度的最短连续子数组，返回其长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1, 2, 2, 3, 1]
 * 输出: 2
 * 解释: 
 * 输入数组的度是2，因为元素1和2的出现频数最大，均为2.
 * 连续子数组里面拥有相同度的有如下所示:
 * [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
 * 最短连续子数组[2, 2]的长度为2，所以返回2.
 * 
 * 
 * 示例 2:
 * 
 * 
 * 输入: [1,2,2,3,1,4,2]
 * 输出: 6
 * 
 * 
 * 注意:
 * 
 * 
 * nums.length 在1到50,000区间范围内。
 * nums[i] 是一个在0到49,999范围内的整数。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> record1;
        unordered_map<int, pair<int, int>> record2;

        int res = INT_MAX;
        int maxdu = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i ++){
            record1[nums[i]] ++;
            maxdu = max(maxdu, record1[nums[i]]);
            if(record1[nums[i]] == 1)
                record2[nums[i]].first = i;
            record2[nums[i]].second = i;
        }

        for(auto r : record1){
            if(r.second == maxdu)
                res = min(res, record2[r.first].second - record2[r.first].first + 1);
        }
        return res;
    }
};
// @lc code=end

