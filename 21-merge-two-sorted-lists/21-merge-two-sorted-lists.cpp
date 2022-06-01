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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1 == NULL) return list2;
        else if(list2 == NULL) return list1;
        ListNode* ans = new ListNode(-1);
        ListNode* ansitr = ans;
        
        ListNode* curr1 = list1;
        ListNode* next1=list1;
        ListNode* curr2 = list2;
        ListNode* next2=list2;

        
        while(curr1 && curr2){
            if(curr1->val <= curr2->val){
                next1 = curr1->next;
                ansitr->next = curr1;
                curr1 = next1;
                ansitr = ansitr->next;
            }else{
                next2 = curr2->next;
                ansitr->next = curr2;
                curr2 = next2;
                ansitr = ansitr->next;
            }
        }
        if(curr1){
            ansitr->next = curr1;
        }else if(curr2){
            ansitr->next = curr2;
        }
        return ans->next;

    }
};