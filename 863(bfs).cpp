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

    void buildGraph(TreeNode* root, vector<vector<int>>& adjList){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->right){
                adjList[node->val].push_back(node->right->val);
                adjList[node->right->val].push_back(node->val);
                q.push(node->right);
            }
            if(node->left){
                adjList[node->val].push_back(node->left->val);
                adjList[node->left->val].push_back(node->val);
                q.push(node->left);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == nullptr) return {};
   ;
        vector<vector<int>> adjList(501);
        buildGraph(root, adjList);
        queue<pair<int,int>> q;
        vector<bool> visited(501, false);
       
        q.push({target->val,0});
        visited[target->val] = true;
        vector<int> ans;
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            if(dist == k){
                ans.push_back(node);
                continue;
            }
            
            for(auto nextNode : adjList[node]){
                if(!visited[nextNode]){
                    q.push({nextNode, dist+1});
                    visited[nextNode] = true;
                }
            }
        }
        return ans;
    }
};
