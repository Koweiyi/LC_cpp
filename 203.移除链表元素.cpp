/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.15%)
 * Likes:    346
 * Dislikes: 0
 * Total Accepted:    60.9K
 * Total Submissions: 137.8K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 * 
 * 示例:
 * 
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 * 
 * 
 */
//Definition for singly-linked list.

#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *pre = dummyHead;
        while (pre->next != NULL)
        {
            if (pre->next->val == val)
            {
                ListNode *delNode = pre->next;
                pre->next = pre->next->next;
                delete delNode;
            }
            else
            {
                pre = pre->next;
            }
        }
        ListNode *retNode = dummyHead->next;  
        delete dummyHead;
        return retNode;

    }
};
// @lc code=end
