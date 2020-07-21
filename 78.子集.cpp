/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (76.82%)
 * Likes:    497
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 93.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

vector<vector<int>> res;

void generateSubsets(vector<int> nums, int index, int k, vector<int> s){

    if(s.size() == k){
        res.push_back(s);
        return;
    }

    for(int i = index ; i < nums.size() - (k - s.size()) + 1 ; i ++ ){
        s.push_back(nums[i]);
        generateSubsets(nums, i + 1, k, s);
        s.pop_back();
    }

    return;
}

 
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        for(int i = 0 ; i <= nums.size(); i ++ )
        {
            vector<int> s;
            generateSubsets(nums, 0, i, s);
        }

        return res;
    }
};
// @lc code=end

