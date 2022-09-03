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
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode *oddHead = head -> next, *evenHead = head;
        ListNode* oddIter = oddHead, *evenIter = evenHead;
        
        while(oddIter && oddIter -> next){
            evenIter -> next = oddIter -> next;
            evenIter = evenIter -> next;
            
            oddIter -> next = evenIter -> next;
            oddIter = oddIter -> next;
        }
        evenIter -> next = oddHead;
        return evenHead;
    }
};