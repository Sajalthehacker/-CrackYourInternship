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
    void reorderList(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return;
        stack<ListNode*> stt;
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        int cnt = 0;
        while(fast!=NULL){
            cnt++;
            slow = slow -> next;
            fast = fast -> next;
            if(fast!=NULL) fast = fast -> next;
        }
        
        while(slow!=NULL){
            stt.push(slow);
            slow = slow->next;
        }
        ListNode* curr = head;
        for(int i=0; i<cnt; i++){
            if(i < cnt-1){
                ListNode* temp = curr->next;
                curr->next = stt.top();
                stt.pop();
                curr->next->next = temp;
                curr = curr->next->next;
            }
            else{
                curr->next = stt.top();
                stt.pop();
                if(!stt.empty()){
                    curr = curr->next;
                    curr->next = stt.top();
                    stt.pop();
                }
                curr->next->next = NULL;
            }
        }
        
    }
};