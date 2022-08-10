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
    TreeNode* createTree(int root, unordered_map<int, pair<int, int>> &mpp){
        if(root == -1) return NULL;
        TreeNode* node = new TreeNode(root);
        if(mpp.find(root) == mpp.end()){
            return node;
        }
        
        node -> left = createTree(mpp[root].first, mpp);
        node -> right = createTree(mpp[root].second, mpp);
        return node;
    }
public:
    TreeNode* createBinaryTree(vector<vector<int>>& des) {
        // Find the root node throgh set
        unordered_set<int> stt;
        
        // make a map {node, {left-node, right-node}}
        // So that it will be easy to access
        unordered_map<int, pair<int, int>> mpp;
        for(auto it : des){
            if(mpp.find(it[0]) == mpp.end()) mpp[it[0]] = {-1, -1};
            if(it[2] == 1) mpp[it[0]].first = it[1];
            else mpp[it[0]].second = it[1];
            stt.insert(it[1]);
        }
        // Root will not be prese t in any of the child
        int tempR;
        for(auto it : des){
            if(stt.find(it[0]) == stt.end()){
                tempR = it[0];
                break;
            }
        }
        // Use recursion to make a tree
        return createTree(tempR, mpp);
    }
};