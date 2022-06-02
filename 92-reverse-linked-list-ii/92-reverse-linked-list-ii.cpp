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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL || left==right) return head;
        
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* curr = newHead;
        
        for(int i=0; i<left-1; i++){
            curr = curr->next;
        }
        ListNode* tail = curr->next;
        
        for(int i=0; i<(right-left); i++){
            ListNode* temp = curr->next;
            curr->next = tail->next;
            tail->next = tail->next->next;
            curr->next->next = temp;
        }
        return newHead->next;
        
    }
};