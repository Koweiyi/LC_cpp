/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.21%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    40.4K
 * Total Submissions: 55.1K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
private:
    vector<vector<int>> res;
    void generateCombine(int n, int k, int step, vector<int> p){

        if(p.size() == k){
            res.push_back(p);
            return;
        }

        for(int i = step ; i <= n - (k - p.size()) + 1; i ++){
            p.push_back(i);
            generateCombine(n, k, i + 1, p);
            p.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {

        res.clear();
        if(n < k)
            return res;

        vector<int> p;
        generateCombine(n, k, 1, p);

        return res;
    }
};
// @lc code=end

