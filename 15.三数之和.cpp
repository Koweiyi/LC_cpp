/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.17%)
 * Likes:    1929
 * Dislikes: 0
 * Total Accepted:    185.3K
 * Total Submissions: 707.1K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {

private:
    vector<vector<int>> res;

public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        if(nums.size() <= 2)
            return res;
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < nums.size() - 2 ; ){

            int left = i + 1, right = nums.size() - 1;
            
            while(left < right){

                if(nums[left] + nums[right] + nums[i] > 0)
                    do{right --;} while(right > 0 && nums[right + 1] == nums[right]);

                else if(nums[left] + nums[right] + nums[i] < 0)
                    do{left ++;} while(left < nums.size() && nums[left - 1] == nums[left] );

                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    do{right --;} while(right > 0 && nums[right + 1] == nums[right]);
                    do{left ++;} while(left < nums.size() && nums[left - 1] == nums[left] );
                }
            }
            do{i++;} while ( i < nums.size() && nums[i - 1] == nums[i]);    
        }
        
        return res;
    }
};
// @lc code=end


