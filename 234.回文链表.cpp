/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (41.11%)
 * Likes:    439
 * Dislikes: 0
 * Total Accepted:    73.9K
 * Total Submissions: 179.7K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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

private:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur->next != NULL){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        cur->next = pre;
        return cur;
    }
public:
    bool isPalindrome(ListNode* head) {

        int cnt = 0;
        ListNode* p = head;
        while(p){
            cnt ++;
            p = p->next;
        }
        ListNode* middle = head;
        for(int i = 0 ; i < cnt / 2 ; i ++)
            middle = middle->next;
        
        ListNode* back = reverseList(middle);
        while(head && back){
            if(head->val != back->val)
                return false;
            
            head = head->next;
            back = back->next;
        }

        return true;
        
    }
};
// @lc code=end

