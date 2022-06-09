/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map_parents(root);
        
        queue<TreeNode*> que;
        vector<int> ans;
        vector <bool> vis(505, false);
        
        que.push(target);
        while(!que.empty()){
            int size = que.size();
            for(int i=0; i<size; i++){
                TreeNode* temp = que.front();
                vis[temp->val] = true;
                que.pop();
                if(temp->left && !vis[temp->left->val]) que.push(temp->left);
                if(temp->right && !vis[temp->right->val]) que.push(temp->right);
                if(mpp.find(temp)!=mpp.end() && !vis[mpp[temp]->val]) que.push(mpp[temp]);
                if(k==0) ans.push_back(temp->val);
            }
            k--;
            if(k<0) break; // To prevent from doing futrther iterations
        }
        return ans;
    }
private:
    unordered_map<TreeNode*, TreeNode*> mpp;
    
    void map_parents(TreeNode* root){
        if(root == NULL) return;
        
        if(root->left) mpp[root->left] = root;
        if(root->right) mpp[root->right] = root;
        map_parents(root->left);
        map_parents(root->right);
    }
    
};