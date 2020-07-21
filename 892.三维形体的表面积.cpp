/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (56.07%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    5.9K
 * Total Submissions: 10.5K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
 * 
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
 * 
 * 请你返回最终形体的表面积。
 * 
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：[[2]]
 * 输出：10
 * 
 * 
 * 示例 2：
 * 
 * 输入：[[1,2],[3,4]]
 * 输出：34
 * 
 * 
 * 示例 3：
 * 
 * 输入：[[1,0],[0,2]]
 * 输出：16
 * 
 * 
 * 示例 4：
 * 
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 * 
 * 
 * 示例 5：
 * 
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:
    
    int ans = 0;
    int calu(const vector<vector<int>>& grid, int i, int j, int n )
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return n;
        else if(grid[i][j] >= n)
            return 0;
        else 
            return n - grid[i][j]; 
    }
    void caluArea(const vector<vector<int>>& grid, int i, int j){
        if(grid[i][j] == 0)
            return;
        ans += 2;
        ans += calu(grid, i - 1, j, grid[i][j]);
        ans += calu(grid, i, j - 1, grid[i][j]);
        ans += calu(grid, i + 1, j, grid[i][j]);
        ans += calu(grid, i, j + 1, grid[i][j]);
        return;
    }


public:
    int surfaceArea(vector<vector<int>>& grid) {

        if(grid.size() == 0)
            return 0;

        for(int i = 0 ; i < grid.size() ; i ++ )
            for(int j = 0 ; j < grid[0].size() ; j ++ )
                caluArea(grid, i, j);
        
        return ans;
    }
};
// @lc code=end

