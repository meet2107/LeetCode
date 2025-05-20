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

    int ans = 0;

    int help(TreeNode* root){
        if(!root){
            return 0;
        }

        int lh = help(root->left);
        int rh = help(root->right);

        ans = max(ans,lh+rh);

        return 1+max(lh,rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        help(root);
        return ans;
    }
};
