/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (61.40%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 43.8K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 * 
 * 
 * 
 * 例如：
 * 
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 * 
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 * 
 * 
 * 
 * 
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
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
    TreeNode* pre;
    void inOrder(TreeNode* root){
        if(!root)return;
        inOrder(root->right);
        if(pre)
            root->val += pre->val;
        pre = root;
        inOrder(root->left);
    }

public:
    TreeNode* convertBST(TreeNode* root) {
        pre = NULL;
        inOrder(root);
        return root;
    }
};
// @lc code=end

