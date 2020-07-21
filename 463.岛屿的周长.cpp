/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 *
 * https://leetcode-cn.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (66.79%)
 * Likes:    191
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 26.1K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * 给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。
 * 
 * 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
 * 
 * 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100
 * 。计算这个岛屿的周长。
 * 
 * 
 * 
 * 示例 :
 * 
 * 输入:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 * 
 * 输出: 16
 * 
 * 解释: 它的周长是下面图片中的 16 个黄色的边：
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
    int res;

public:

    int d[4][2] = {{0, 1},{1, 0}, {0, -1}, {-1, 0}};

    int islandPerimeter(vector<vector<int>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        res = 0;
        for(int i = 0 ; i < grid.size() ; i ++){
            for(int j = 0 ; j < grid[i].size() ; j ++){
                if(grid[i][j] == 1){
                    for(int k = 0 ; k < 4 ; k ++){
                        int nx = i + d[k][0];
                        int ny = j + d[k][1];
                        if(nx >=0 && ny >= 0 && nx < grid.size() && ny < grid[0].size() && grid[nx][ny] == 1)
                            continue;
                        else 
                            res ++;

                    }
                }
            }
        }

        return res;

    }
};
// @lc code=end

