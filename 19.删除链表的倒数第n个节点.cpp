/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (38.17%)
 * Likes:    747
 * Dislikes: 0
 * Total Accepted:    143.3K
 * Total Submissions: 375.1K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 * 
 * 示例：
 * 
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 * 
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 * 
 * 
 * 说明：
 * 
 * 给定的 n 保证是有效的。
 * 
 * 进阶：
 * 
 * 你能尝试使用一趟扫描实现吗？
 * 
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}   
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
            return head;

        ListNode* dummyHead =new ListNode(0);
        dummyHead->next = head;

        ListNode *pre = dummyHead,*back = dummyHead;
        while(back->next){
            if(n <= 0)
                pre = pre->next;
            back = back->next;
            n --;
        }
        ListNode* delNode = pre->next;
        pre->next = delNode->next;
        delete delNode;
        
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;

    }
};
// @lc code=end

