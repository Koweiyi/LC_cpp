/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (73.63%)
 * Likes:    71
 * Dislikes: 0
 * Total Accepted:    24.1K
 * Total Submissions: 32.8K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * 给定一个 N 叉树，返回其节点值的后序遍历。
 * 
 * 例如，给定一个 3叉树 :
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 返回其后序遍历: [5,6,3,2,4,1].
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
    void postOrder(Node* root){
        if(!root) return;
        for(int i = 0 ; i < root->children.size() ; i ++)
            postOrder(root->children[i]);
        res.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root) {
        postOrder(root);
        return res;
    }
};
// @lc code=end

