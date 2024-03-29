/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (61.59%)
 * Likes:    159
 * Dislikes: 0
 * Total Accepted:    39.9K
 * Total Submissions: 64.8K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 * 
 * 示例：
 * 
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 * 
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 * 
 * 说明:
 * 
 * 
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class NumArray {


public:
    vector<int> res;
    NumArray(vector<int>& nums) {
        res = vector<int>(nums.begin(), nums.end());
        for(int i = 1 ; i < res.size() ; i ++)
            res[i] += res[i - 1];
    }
    
    int sumRange(int i, int j) {
        if(i == 0)
            return res[j];
        return res[j] - res[i - 1];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

