/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.58%)
 * Likes:    678
 * Dislikes: 0
 * Total Accepted:    113.4K
 * Total Submissions: 224.2K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
 * 
 */


#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x) ,left(NULL), right(NULL){}
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
// private:
//     bool dfs(TreeNode* left, TreeNode* right){
//         if(!left && !right)
//             return true;
//         if(!left || !right)
//             return false;
//         return left->val == right->val && dfs(left->left, right->right) && dfs(left->right, right->left);

//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         if(root == NULL)
//             return true;
//         return dfs(root->left, root->right);
//     }

public:
    bool isSymmetric(TreeNode* root){
        if(root == NULL)
            return true;
        
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while(!q.empty()){

            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if(!left && !right)
                continue;
            if(!left || !right)
                return false;
            if(left->val != right->val)
                return false;

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};
// @lc code=end

