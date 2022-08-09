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
private:
    ListNode* reverse(ListNode* midd){
        ListNode* curr = midd;
        ListNode* next = midd;
        ListNode* prev = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        int res = 0;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        slow = reverse(slow);
        
        while(slow != NULL){
            // cout << head -> val << " " << slow -> val << endl;
            res = max(res, head->val + slow->val);
            slow = slow -> next;
            head = head -> next;
        }
        
        return res;
    }
};