/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
    void dfs(Node* parent, vector<int>& res){
        if (parent == nullptr) return;
        res.push_back(parent->val);
        for(Node* child : parent->children){
            dfs(child, res);
        }
    }
};
