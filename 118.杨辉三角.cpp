/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (66.00%)
 * Likes:    268
 * Dislikes: 0
 * Total Accepted:    67.7K
 * Total Submissions: 102.5K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:
    vector<vector<int>> res;
public:
    vector<vector<int>> generate(int numRows) {

        res = vector<vector<int>>(numRows, vector<int>());
        for(int i = 0 ; i < numRows ; i ++)
            res[i] = vector<int>(i + 1, 1);

        for(int i = 2 ; i < numRows ; i ++)
            for(int j = 1 ; j < i ; j ++ )
                res[i][j] = res[i - 1][j] + res[i - 1][j - 1];

        return res;

    }
};
// @lc code=end

