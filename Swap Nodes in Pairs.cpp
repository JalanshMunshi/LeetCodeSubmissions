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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode *ret = new ListNode(-1), *temp = ret;
        ret->next = head;
        while(head && head->next)
        {
            ListNode *nextNode = head->next->next;
            temp->next = head->next;
            head->next->next = head;
            temp = head;
            temp->next = nextNode;
            head = nextNode;
        }
        return ret->next;
    }
};