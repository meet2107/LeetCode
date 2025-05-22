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
    set<int> s;
    bool check(TreeNode* root, int k){
        if(!root){
            return false;
        }

        if(s.find(k-root->val) != s.end()){
            return true;
        }

        s.insert(root->val);
        return check(root->left,k) || check(root->right,k);
    }

    bool findTarget(TreeNode* root, int k) {
        return check(root,k);
    }
};
