class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int x = 0;
        vector<vector<int>> zigzag;
        if(root == NULL) return zigzag;
        
        queue < TreeNode* > que;
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            vector<int> level;
            for(int i=0; i<size; i++){
                TreeNode *node = que.front();
                que.pop();
                level.push_back(node -> val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            if(x%2) reverse(level.begin(), level.end());
            zigzag.push_back(level);
            x++;
        }
        return zigzag;
    }
};