#include<bits/stdc++.h>
using namespace std;

struct ListNode{

    int val;
    ListNode *next;
    ListNode(int x) : val(x) , next(NULL){};
};


// @lc code=start
class Solution {
public:
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
};
// @lc code=end

