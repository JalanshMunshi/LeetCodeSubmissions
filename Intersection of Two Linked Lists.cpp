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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Better approach using two pointers.
        if(headA == NULL || headB == NULL)
            return NULL;
        ListNode *ptr1 =  headA, *ptr2 = headB;
        while(ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            if(ptr1 == ptr2)
                return ptr1;
            if(!ptr1)
                ptr1 = headB;
            if(!ptr2)
                ptr2 = headA;
        }
        return ptr1;
        // Brute force approach. Using unordered_map.
        // if(headA == NULL || headB == NULL)
        //     return NULL;
        // unordered_map<ListNode*, int> m;
        // while(headA)
        // {
        //     m[headA] = 1;
        //     headA = headA->next;
        // }
        // while(headB)
        // {
        //     if(m.find(headB) != m.end())
        //         return headB;
        //     headB = headB->next;
        // }
        // return NULL;
    }
};