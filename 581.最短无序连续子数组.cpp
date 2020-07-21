/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 *
 * https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Easy (34.60%)
 * Likes:    308
 * Dislikes: 0
 * Total Accepted:    27.6K
 * Total Submissions: 79.7K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
 * 
 * 你找到的子数组应是最短的，请输出它的长度。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [2, 6, 4, 8, 10, 9, 15]
 * 输出: 5
 * 解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
 * 
 * 
 * 说明 :
 * 
 * 
 * 输入的数组长度范围在 [1, 10,000]。
 * 输入的数组可能包含重复元素 ，所以升序的意思是<=。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> oldNum(nums.begin(), nums.end());
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        while(l < nums.size()){
            if(oldNum[l] == nums[l])
                l ++;
            else 
                break;
        }
        while(r >= 0){
            if(oldNum[r] == nums[r])
                r --;
            else break;
        }
        int res = r - l + 1;
        return res > 0 ? res : 0;

    }
};
// @lc code=end

