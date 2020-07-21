/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (56.69%)
 * Likes:    643
 * Dislikes: 0
 * Total Accepted:    38.6K
 * Total Submissions: 68K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：word1 = "horse", word2 = "ros"
 * 输出：3
 * 解释：
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2：
 * 
 * 输入：word1 = "intention", word2 = "execution"
 * 输出：5
 * 解释：
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {

private:

    vector<vector<int>> memo;

    int minOperation(const string& word1, const string& word2, int i, int j){
        if(j == word2.size())
            return word1.size() - i;

        if(i == word1.size())
            return word2.size() - j;

        if(memo[i][j] != -1)
            return memo[i][j];

        int res = INT_MAX;
        
        if(word1[i] == word2[j])
            res = min(res, minOperation(word1, word2, i + 1, j + 1));
         
        res = min(res, minOperation(word1, word2, i, j + 1) + 1);
        res = min(res, 1 + minOperation(word1, word2, i + 1, j));
        res = min(res, 1 + minOperation(word1, word2, i + 1, j + 1));

        return memo[i][j] = res;
    }

public:
    int minDistance(string word1, string word2) {

        memo = vector<vector<int>>(word1.size(), vector<int>(word2.size(), -1));
        return minOperation(word1, word2, 0, 0);
    }
};
// @lc code=end

