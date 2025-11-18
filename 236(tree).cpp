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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findAncestor(root,p,q);
    }

    TreeNode*findAncestor(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == nullptr || node == p || node == q) return node;
        TreeNode* left = findAncestor(node->left,p,q);
        TreeNode* right = findAncestor(node->right,p,q);

        if(right == nullptr) return left;
        else if(left == nullptr) return right;
        else return node;
    }
};
