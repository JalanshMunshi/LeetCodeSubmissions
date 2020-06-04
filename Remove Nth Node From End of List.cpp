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
        
        ListNode* fast = head, *slow = head;
        while(n--)
            fast = fast->next;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        if(fast)
            slow->next = slow->next->next;
        else
            head = head->next;
        return head;
    }
};