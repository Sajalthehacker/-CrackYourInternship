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
    ListNode* removeElements(ListNode* head, int val) {
        // Recursive
        
        // If the node is NULL, We dont need to return anything, return NULL
        // Base Case
        if(head == NULL) return head;
        ListNode* next = removeElements(head->next, val);
        if(head->val == val) return next;
        else{
            head->next = next;
            return head;
        }
    }
};