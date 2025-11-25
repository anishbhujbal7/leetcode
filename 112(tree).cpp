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
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*,int>>q;
        if(root == nullptr) return false;
        q.push({root,root->val});
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int currSum = q.front().second;
            q.pop();
            if(node->left == nullptr && node->right == nullptr){
                if(currSum == targetSum) return true;
            }
            if(node->left) q.push({node->left,currSum+node->left->val});
            if(node->right) q.push({node->right, currSum+node->right->val});

        }
        return false;
    }
};
