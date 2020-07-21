 /*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 *
 * https://leetcode-cn.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (45.95%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 48.9K
 * Testcase Example:  '[1,5,11,5]'
 *
 * 给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
 * 
 * 注意:
 * 
 * 
 * 每个数组中的元素不会超过 100
 * 数组的大小不会超过 200
 * 
 * 
 * 示例 1:
 * 
 * 输入: [1, 5, 11, 5]
 * 
 * 输出: true
 * 
 * 解释: 数组可以分割成 [1, 5, 5] 和 [11].
 * 
 * 
 * 
 * 
 * 示例 2:
 * 
 * 输入: [1, 2, 3, 5]
 * 
 * 输出: false
 * 
 * 解释: 数组不能分割成两个元素和相等的子集.
 * 
 * 
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:

    vector<vector<int>> memo;

    bool tryPartition(const vector<int>& nums, int index, int sum){
        if(sum == 0)
            return true;
        if(index < 0 || sum < 0)
            return false;
        if(memo[index][sum] == -1)
        memo[index][sum] = tryPartition(nums, index - 1,sum) || tryPartition(nums, index - 1,sum - nums[index]);

        return memo[index][sum];
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums)
            sum += num;
        
        if(sum % 2)
            return false;
        
        // memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1, -1));
        // return tryPartition(nums, nums.size() - 1, sum / 2);
        int n = nums.size();
        int C = sum / 2;
        vector<bool> memo(C + 1, false);
        for(int j = 0 ; j <= C ; j ++)
            memo[j] = (j == nums[0]);
        
        for(int i = 1 ; i < n ; i ++)
            for(int j = C ; j >= nums[i] ; j --)
                memo[j] = memo[j] || memo[j - nums[i]];
            
        return memo.back();

    }
};
// @lc code=end

