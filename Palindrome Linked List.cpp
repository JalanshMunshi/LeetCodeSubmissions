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
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next)
            return true;
        string s = "";
        while(head)
        {
            s += head->val - '0';
            head = head->next;
        }
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
};