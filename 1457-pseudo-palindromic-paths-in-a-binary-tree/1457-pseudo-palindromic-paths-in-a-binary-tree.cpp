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
private:
    void dfs(TreeNode* root, vector<int> &freq, int &cnt){
        if(root == NULL) return;
        freq[root->val]++;
        if(root -> left == NULL && root -> right == NULL){
            int oddCnt = 0;
            for(int i=0; i<10; i++){
                if(freq[i] % 2) oddCnt++;
                
                if(oddCnt > 1) break;
            }
            if(oddCnt <= 1) cnt++;
        }
        dfs(root -> left, freq, cnt);
        dfs(root -> right, freq, cnt);
        freq[root->val]--;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> freq(10, 0);
        int cnt = 0;
        dfs(root, freq, cnt);
        return cnt;
    }
};