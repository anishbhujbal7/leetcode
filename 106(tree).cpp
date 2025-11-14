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

    unordered_map<int,int> map;
    int rootIndex =-1;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i<inorder.size(); i++){
            map[inorder[i]] = i;
        }

        rootIndex = postorder.size()-1;

        return build(inorder, postorder, 0, inorder.size()-1);

    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int start, int end){
        if(start>end) return nullptr;
        int rootVal = postorder[rootIndex--];
        TreeNode* root = new TreeNode(rootVal);
        int index = map[rootVal];

        root-> right = build(inorder,postorder,index+1,end);
        root->left = build(inorder,postorder,start,index-1);
        return root;
    }
};
