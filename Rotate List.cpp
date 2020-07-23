/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)
            return head;
        int len = 0;
        ListNode *cur = head, *start = head;
        while(cur)
        {
            len++;
            cur = cur->next;
        }
        k = k % len;
        if(k == 0)
            return head;
        k = len - k;
        cur = head;
        ListNode *prev;
        while(k--)
        {
            prev = cur;
            cur = cur->next;
        }
        prev->next = NULL;
        head = cur;
        while(cur && cur->next)
            cur =  cur->next;
        if(cur)
            cur->next = start;
        return head;
    }
};