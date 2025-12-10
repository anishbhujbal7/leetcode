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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int n = q.size();
            int currMax = INT_MIN;
            for(int  i = 0; i<n; i++){
                TreeNode* node = q.front();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
                currMax = max(currMax, node->val);
                q.pop();
            }
            ans.push_back(currMax);
        }
        return ans;
    }
};
