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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(-101);
        ListNode* li = less;

        ListNode* high = new ListNode(-101);
        ListNode* hi = high;

        ListNode* curr = head;
        
        while(curr!=NULL){
            if(curr->val < x){
                li->next = curr;
                li = li->next;
            }
            else{
                hi->next = curr;
                hi = hi->next;
            }
            
            curr = curr->next;

        }
        
        if(li->val == -101){
            hi->next = NULL;
            return high->next;    
        }
        else{
            if(hi->val == -101){
                li->next = NULL;
                return less->next;
            }  
            else{
                li->next = high->next;
                hi->next = NULL;
                return less->next;
            }
        }
        

    }
};