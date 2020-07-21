/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (68.44%)
 * Likes:    358
 * Dislikes: 0
 * Total Accepted:    31.2K
 * Total Submissions: 45.5K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:
    vector<vector<string>> res;
    vector<bool> col, diog1, diog2;

    vector<string> generateBoard(int n, vector<int> row){
        vector<string> ans;
        ans = vector<string>(n, string(n, '.'));
        for(int i = 0 ; i < n ; i ++)
            ans[i][row[i]] = 'Q';
        return ans;
    }

    void putQueens(int n, int index, vector<int>& row){

        if(index == n){
            res.push_back(generateBoard(n, row));
            return;
        }

        for(int i = 0 ; i < n ; i ++ ){
            if(!col[i] && !diog1[index + i] && !diog2[index - i + n - 1]){
                row.push_back(i);
                col[i] = true;
                diog1[index + i] = true;
                diog2[index - i + n - 1] =true;
                putQueens(n, index + 1, row);
                row.pop_back();
                col[i] = false;
                diog1[index + i] = false;
                diog2[index - i + n - 1] =false;
            }
        }

        return;
    }


public:
    vector<vector<string>> solveNQueens(int n) {

        col = vector<bool>(n, false);
        diog1 = vector<bool>(2 * n - 1, false);
        diog2 = vector<bool>(2 * n - 1, false);

        vector<int> row;
        putQueens(n, 0, row);

        return res;
        
    }
};
// @lc code=end

