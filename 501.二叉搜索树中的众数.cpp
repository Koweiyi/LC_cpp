/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
 *
 * https://leetcode-cn.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (44.73%)
 * Likes:    109
 * Dislikes: 0
 * Total Accepted:    14K
 * Total Submissions: 31.1K
 * Testcase Example:  '[1,null,2,2]'
 *
 * 给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
 * 
 * 假定 BST 有如下定义：
 * 
 * 
 * 结点左子树中所含结点的值小于等于当前结点的值
 * 结点右子树中所含结点的值大于等于当前结点的值
 * 左子树和右子树都是二叉搜索树
 * 
 * 
 * 例如：
 * 给定 BST [1,null,2,2],
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 返回[2].
 * 
 * 
 * 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内）
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

class Solution {

private:
    vector<int> res;
    TreeNode* pre;
    int curTime, maxTime;
    void inOrder(TreeNode* root){
        if(!root) 
            return;
        inOrder(root->left);
        if(pre)
            curTime = root->val == pre->val ? curTime + 1 : 1;
        if(curTime == maxTime)
            res.push_back(root->val);
        else if(curTime > maxTime){
            res.clear();
            res.push_back(root->val);
            maxTime = curTime;
        }
        pre = root;
        inOrder(root->right);
    }


public:
    vector<int> findMode(TreeNode* root) {
        res.clear();
        if(!root)
            return res;
        pre = NULL;
        curTime = 1;
        maxTime = 0;
        inOrder(root);
        return res;

    }
};
// @lc code=end

