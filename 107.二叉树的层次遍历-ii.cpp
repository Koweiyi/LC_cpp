/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (65.54%)
 * Likes:    238
 * Dislikes: 0
 * Total Accepted:    60.1K
 * Total Submissions: 91.7K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其自底向上的层次遍历为：
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
 * ]
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
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:
    vector<vector<int>> res;

public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if(root == NULL)
            return res;

        vector<int> floor;
        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            for(int i = 0 ; i < size ; i ++ ){
                TreeNode * curNode = que.front();
                que.pop();
                floor.push_back(curNode->val);
                if(curNode->left)
                    que.push(curNode->left);
                if(curNode->right)
                    que.push(curNode->right);
            }

            res.push_back(floor);
            floor.clear();
        }

        reverse(res.begin(), res.end());
        return res;
        
    }
};
// @lc code=end

