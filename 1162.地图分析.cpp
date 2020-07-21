/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (38.53%)
 * Likes:    27
 * Dislikes: 0
 * Total Accepted:    6.8K
 * Total Submissions: 17.6K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 * 
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 -
 * x1| + |y0 - y1| 。
 * 
 * 如果我们的地图上只有陆地或者海洋，请返回 -1。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释： 
 * 海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释： 
 * 海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:

    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> d = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        queue<pair<int,int>> q;
        for(int i = 0 ; i < n ; i ++ )
            for(int j = 0 ; j < n ; j ++ )
                if(grid[i][j])
                    q.push({i,j});

        if(q.size() == 0 || q.size() == n * n)
            return -1;

        int res = -1;
        while(!q.empty())
        {
            int size = q.size();
            while(size --){
                pair<int, int> p = q.front(); q.pop();
                for(int i = 0 ; i < 4 ; i ++)
                {
                    int nx = p.first + d[i][0];
                    int ny = p.second + d[i][1];
                    if(nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0)
                    {
                        q.push({nx, ny});
                        grid[nx][ny] = -1;
                    }   
                }
            }

            res ++;
        } 

        return res;
    }
};
// @lc code=end

int main(int argc, char const *argv[])
{
    vector<vector<int>> test = {{1,0,1}, {0,0,0}, {1,0,1}};
    int res = Solution().maxDistance(test);
    cout << res;   
    return 0;
}
