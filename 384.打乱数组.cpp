/*
 * @lc app=leetcode.cn id=384 lang=cpp
 *
 * [384] 打乱数组
 *
 * https://leetcode-cn.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (50.14%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    16.6K
 * Total Submissions: 33K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * 打乱一个没有重复元素的数组。
 * 
 * 示例:
 * 
 * 
 * // 以数字集合 1, 2 和 3 初始化数组。
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 * 
 * // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。
 * solution.shuffle();
 * 
 * // 重设数组到它的初始状态[1,2,3]。
 * solution.reset();
 * 
 * // 随机返回数组[1,2,3]打乱后的结果。
 * solution.shuffle();
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {

private:
    vector<int> clone;
    vector<int> shuffled;

public:
    Solution(vector<int>& nums) {
        clone = vector<int>(nums.begin(), nums.end());
        shuffled = vector<int>(nums.begin(), nums.end());
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return clone;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {

        vector<bool> used(clone.size(), false);
        // srand((int)time(NULL));  

        int cnt = 0;
        while(cnt < clone.size()){

            int index;
            do{
                index = rand() % clone.size();
            } while (used[index]);
            used[index] = true;
            shuffled[cnt ++] = clone[index];  
        }

        return shuffled;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
// @lc code=end

