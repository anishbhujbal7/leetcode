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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> vec;
            int n = q.size();
            for(int i =0; i<n; i++){
                TreeNode* node = q.front();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                q.pop();
                vec.push_back(node->val);
            }
            ans.push_back(vec);
        }
        vector<int>res;
        for(auto level : ans){
            int n = level.size();
            res.push_back(level[n-1]);
        }
        return res;
    }
};
