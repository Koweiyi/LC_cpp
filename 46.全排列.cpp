/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.45%)
 * Likes:    571
 * Dislikes: 0
 * Total Accepted:    92.3K
 * Total Submissions: 123.9K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */
#include<bits/stdc++.h>
using namespace std;


// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    vector<bool> book;

    void generatePerutation(vector<int> nums, int index, vector<int> p){

        if(nums.size() == index){
            res.push_back(p);
            return;
        }
        
        for(int i = 0 ; i < nums.size() ; i ++){
            if(!book[i]){
                p.push_back(nums[i]);
                book[i] = true;
                generatePerutation(nums, index + 1, p);
                p.pop_back();
                book[i] = false;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {

        res.clear();
        book = vector<bool>(nums.size(),false);
        if(nums.size() == 0) 
            return res;

        vector<int> p;
        generatePerutation(nums, 0, p);
        
        return res;
        
    }
};
// @lc code=end

