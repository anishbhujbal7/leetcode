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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;
        queue<pair<TreeNode*, long long>> q;  
        q.push({root, 0});  // node + index

        while (!q.empty()) {
            int n = q.size();
            long long leftIndex = q.front().second;
            long long rightIndex = leftIndex;

            for (int i = 0; i < n; i++) {
                auto cur = q.front(); 
                q.pop();

                TreeNode* node = cur.first;
                long long idx = cur.second;

                rightIndex = idx;  // last node's index in this level

                // push children with adjusted indices
                if (node->left)  q.push({node->left, 2 * (idx - leftIndex) + 1});
                if (node->right) q.push({node->right, 2 * (idx - leftIndex) + 2});
            }

            ans = max(ans, rightIndex - leftIndex + 1);
        }

        return ans;
    }
};
