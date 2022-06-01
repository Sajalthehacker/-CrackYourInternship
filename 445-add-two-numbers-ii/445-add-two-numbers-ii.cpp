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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> num1;
        stack<int> num2;
        
        while(l1!=NULL){
            num1.push(l1->val);
            l1 = l1->next;
        }
        while(l2!=NULL){
            num2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* curr = new ListNode(0);
        int sum = 0;
        
        while(!num1.empty() || !num2.empty()){
            if(!num1.empty()) {
                sum += num1.top();
                num1.pop();
            }
            if(!num2.empty()) {
                sum += num2.top();
                num2.pop();
            }
            curr->val = sum%10;
            ListNode* head = new ListNode(sum/10);
            head->next = curr;
            curr = head;
            sum /= 10;
        }
        if(curr->val == 0){
            return curr -> next;
        }else return curr;
    }
};