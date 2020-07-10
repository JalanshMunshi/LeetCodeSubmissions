/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        
        if(!head)
            return NULL;
        Node *ans = new Node(head->val);
        ans->next = flatten(head->child);
        Node* curr = ans;
        while(curr->next)
        {
            curr->next->prev = curr;
            curr = curr->next;
        }
        curr->next = flatten(head->next);
        if(curr->next)
            curr->next->prev = curr;
        return ans;
    }
};