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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd = new ListNode(-1);
        ListNode *even = new ListNode(-1);
        ListNode *curr = head, *next;
        ListNode *oddIter = odd, *evenIter = even;
        int ind = 0;
        
        while(curr != NULL){
            next = curr -> next;            

            if(ind % 2 == 1) {
                evenIter -> next = curr;
                evenIter = evenIter -> next;
            }
            else {
                oddIter -> next = curr;
                oddIter = oddIter -> next;
            }
            
            curr -> next = NULL;
            curr = next;
            
            ind ++;
        }

        oddIter -> next = even -> next;
        return odd -> next;
    }
};