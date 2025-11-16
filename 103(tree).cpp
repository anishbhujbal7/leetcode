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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> ans;
       if(root == nullptr) return ans;
       queue<TreeNode*> q;
       q.push(root);
       int count = 2;
       while(!q.empty()){
        vector<int> vec;
        int n = q.size();
        
        for(int i = 0; i<n; i++){
            TreeNode* node = q.front();
           
            if(node->left != nullptr) q.push(node->left);
            if(node->right !=nullptr) q.push(node->right);
            q.pop();
            vec.push_back(node->val);
        }
        if(count%2!=0) reverse(vec.begin(), vec.end());
        count++;
        ans.push_back(vec);
       } 
       return ans; 
    }
};
