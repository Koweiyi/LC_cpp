/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.95%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    46K
 * Total Submissions: 112K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:
    
    bool search(vector<vector<char>>& board,const string& word, int index, int startx,int starty){
        
        if(index >= word.size())
            return true;
        
        if(startx < 0 || startx >= board.size() || starty < 0 || starty >= board[0].size() || board[startx][starty] != word[index])
            return false;
        
        board[startx][starty] += 250;
        bool res = search(board, word, index + 1, startx - 1, starty) ||
                search(board, word, index + 1, startx, starty + 1) ||
                search(board, word, index + 1, startx + 1, starty) ||
                search(board, word, index + 1, startx, starty - 1);
        board[startx][starty] -= 250;

        return res;
    }


public:
    bool exist(vector<vector<char>>& board, string word) {
        
        // visited = vector<vector<bool>>(board.size(),vector<bool>(board[0].size(),false));

        for(int i = 0 ; i < board.size() ; i ++ )
            for(int j = 0 ; j < board[0].size() ; j ++ )
                if(search(board, word, 0, i, j))
                    return true;

        return false;
    }   
};
// @lc code=end

