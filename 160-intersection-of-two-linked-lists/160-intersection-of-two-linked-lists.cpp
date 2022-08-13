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
        ListNode* itrA = headA;
        ListNode* itrB = headB;

        while(itrA != itrB){
            if(itrA) itrA = itrA -> next;
            else itrA = headB;
            
            if(itrB) itrB = itrB -> next;
            else itrB = headA;
        }
        return itrA;
    }
};