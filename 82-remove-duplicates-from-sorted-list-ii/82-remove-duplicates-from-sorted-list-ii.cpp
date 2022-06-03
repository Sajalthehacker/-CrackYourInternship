class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* a = new ListNode(0);
        a->next = head;
        ListNode* dummy = a;

        ListNode* b = head;
        
        while(b->next != NULL){
            if(b->val == b->next->val){
                while(b->next != NULL && b->val == b->next->val){
                    ListNode* temp1 = b;
                    b=b->next;
                    a->next = b->next;
                    delete(temp1);
                } 
                
                if(b->next != NULL){
                    b = b->next;
                    a->next=b;
                }
            }
            else{
                a=a->next;
                if(b->next != NULL)
                    b=b->next;
            }
            
        }
        
        return dummy->next;
    }
};