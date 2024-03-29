/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.58%)
 * Likes:    245
 * Dislikes: 0
 * Total Accepted:    48.5K
 * Total Submissions: 149K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();

        vector<vector<long long>> dp(m,vector<long long>(n,0));
        for(int i = 0 ; i < n && !obstacleGrid[0][i]; i++)
            dp[0][i] = 1;

        for(int i = 0 ; i < m && !obstacleGrid[i][0]  ; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i < m ; i ++)
            for(int j = 1 ; j < n ; j ++)
            {
                if(obstacleGrid[i][j] == 1)
                    continue;
                dp[i][j] += obstacleGrid[i - 1][j] == 0 ? dp[i - 1][j] : 0;
                dp[i][j] += obstacleGrid[i][j - 1] == 0 ? dp[i][j - 1] : 0;
            }

        return dp[m - 1][n - 1];

    }
};
// @lc code=end

int main(int argc, char const *argv[])
{

    vector<vector<int>> o(3,vector<int>(3,0));
    o[1][1] = 1;
    cout << Solution().uniquePathsWithObstacles(o);
    return 0;
}
