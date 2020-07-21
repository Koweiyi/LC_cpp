/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (61.09%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    53.4K
 * Total Submissions: 87.4K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res(2, vector<int>(rowIndex + 1, 1));
        if(rowIndex < 2)
            return res[rowIndex % 2];
        
        for(int i = 2 ; i <= rowIndex ; i ++ )
            for(int j = 1 ; j < i ; j ++)
                res[i % 2][j] = res[(i + 1) % 2][j - 1] + res[(i + 1) % 2][j];

        return res[rowIndex % 2];
    }
};
// @lc code=end

