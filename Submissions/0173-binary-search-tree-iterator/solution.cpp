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
class BSTIterator {
public:

    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* ans = s.top();
        s.pop();
        pushall(ans->right);
        return ans->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }

    void pushall(TreeNode* node){
        for(;node!=NULL;s.push(node),node=node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
