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
    ListNode *detectCycle(ListNode *head) {
        // Use floyd slow fast ptr technique
        ListNode *slow = head, *fast = head, *slow2 = head;
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                while(slow != slow2){
                    slow = slow -> next;
                    slow2 = slow2 -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};