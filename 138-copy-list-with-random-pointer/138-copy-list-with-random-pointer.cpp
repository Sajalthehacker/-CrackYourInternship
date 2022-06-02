/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        if(head == NULL) return head;
        
        Node* curr = head;
        // Create Chains through out
        while(curr != NULL){
            Node* next = new Node(curr->val);
            Node* temp = curr->next;
            curr->next = next;
            curr->next->next = temp;
            curr = temp; // also coded as curr = curr->next->next;
        }
        curr = head;
        // Replicate all the copy pointers
        while(curr != NULL){
            if(curr->random == NULL) curr->next->random = NULL;
            else curr->next->random = curr->random->next;   
            
            curr = curr->next->next;
        }
        // change the links
        Node* newHead = head->next;
        Node* curr1 = head;
        Node* curr2 = newHead;
        
        while(curr2->next != NULL){
            curr1->next = curr1->next->next;
            curr1 = curr1->next;
            curr2->next = curr2->next->next;
            curr2 = curr2->next;
        }
        curr1->next = NULL;
        curr2->next = NULL;
        
        return newHead;
    }
};