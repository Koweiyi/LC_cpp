/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal/description/
 *
 * algorithms
 * Easy (73.29%)
 * Likes:    78
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 38.4K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的前序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其前序遍历: [1,3,5,6,2,4]。
 * 
 * 
 * 
 * 说明: 递归法很简单，你可以使用迭代法完成此题吗?
 */
#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
*/

class Solution {

private:
    vector<int> res;
    void preOrder(Node* root){
        if(!root) return;
        res.push_back(root->val);
        for(int i = 0 ; i < root->children.size() ; i ++)
            preOrder(root->children[i]);
    }

public:
    vector<int> preorder(Node* root) {
        preOrder(root);
        return res;
    }
};
// @lc code=end

