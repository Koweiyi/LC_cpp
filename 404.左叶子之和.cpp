/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (54.61%)
 * Likes:    151
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 46.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 * 
 * 示例：
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
 * 
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 */
class Solution {

private:
    int sum = 0;
    void solve(TreeNode* root, int s){
        if(root == NULL)
            return;
        if(root->left == NULL && root->right == NULL){
            if(s == 1)
                sum += root->val;
        }
            
        else {
            solve(root->left, 1);
            solve(root->right, 0);
        }
        return;
    }

public:
    int sumOfLeftLeaves(TreeNode* root) {
        solve(root, 0);
        return sum;
    }
};
// @lc code=end

