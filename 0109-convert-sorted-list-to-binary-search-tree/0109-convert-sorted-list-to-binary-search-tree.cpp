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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail = NULL) {
        // This is same problem as sorted array to BST
        // Challenge here is random access of elements
        // for that we run slow-fast ptr algo for finding mid
        // asssumptions are same, 
        // left sublist = left subtree && right as follows
        
        if(head == tail) return NULL;
        
        ListNode *slow = head, *fast = head;
        while(fast != tail && fast->next != tail){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        TreeNode *root = new TreeNode(slow -> val);
        root -> left = sortedListToBST(head, slow);
        root -> right = sortedListToBST(slow -> next, tail);

        
        
        return root;
    }
};