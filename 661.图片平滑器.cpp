/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 *
 * https://leetcode-cn.com/problems/image-smoother/description/
 *
 * algorithms
 * Easy (53.58%)
 * Likes:    50
 * Dislikes: 0
 * Total Accepted:    8K
 * Total Submissions: 15K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入)
 * ，平均灰度的计算是周围的8个单元和它本身的值求平均，如果周围的单元格不足八个，则尽可能多的利用它们。
 * 
 * 示例 1:
 * 
 * 
 * 输入:
 * [[1,1,1],
 * ⁠[1,0,1],
 * ⁠[1,1,1]]
 * 输出:
 * [[0, 0, 0],
 * ⁠[0, 0, 0],
 * ⁠[0, 0, 0]]
 * 解释:
 * 对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
 * 对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
 * 对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
 * 
 * 
 * 注意:
 * 
 * 
 * 给定矩阵中的整数范围为 [0, 255]。
 * 矩阵的长和宽的范围均为 [1, 150]。
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {

private:
    vector<vector<int>> res;
    int d[8][2] = {{1,0},{0,1},{0,-1},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};
    int caluSmoother(const vector<vector<int>>& M, int i, int j){
        int smoother = M[i][j];
        int area = 1;
        for(int k = 0 ; k < 8 ; k ++){
            int ni = i + d[k][0];
            int nj = j + d[k][1];
            if(ni >= 0 && nj >= 0 && ni < M.size() && nj < M[0].size()){
                area ++;
                smoother += M[ni][nj];
            }
        }
        return smoother / area;
    }

public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        res = vector<vector<int>>(M.size(), vector<int>(M[0].size()));
        for(int i = 0 ; i < M.size() ; i ++)
            for(int j = 0 ; j < M[0].size() ; j ++)
                res[i][j] = caluSmoother(M, i, j);
        
        return res;
    }   
};
// @lc code=end

