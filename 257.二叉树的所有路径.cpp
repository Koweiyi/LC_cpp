/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 *
 * https://leetcode-cn.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (62.17%)
 * Likes:    225
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 46.2K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * 给定一个二叉树，返回所有从根节点到叶子节点的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 输入:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * 输出: ["1->2->5", "1->3"]
 * 
 * 解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if(root == NULL)
            return res;

        if(root->left == NULL && root->right == NULL ){
            res.push_back(to_string(root->val));
            return res;
        }

        vector<string> leftS = binaryTreePaths(root->left);
        for(auto path : leftS)
            res.push_back(to_string(root->val) + "->" + path );
        vector<string> rightS = binaryTreePaths(root->right);
        for(auto path : rightS)
            res.push_back(to_string(root->val) + "->" + path);
        
        return res;
     }
};
// @lc code=end

