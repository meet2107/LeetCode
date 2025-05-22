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

    void inorder(TreeNode* root, int &ksmall, int &cnt, int k){
        if(!root || cnt >= k){
            return;
        }

        inorder(root->left,ksmall,cnt,k);
        cnt++;
        if(cnt == k){
            ksmall = root->val;
            return;
        }
        inorder(root->right,ksmall,cnt,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        // vector<int> in;
        int ksmall = INT_MIN;
        int cnt = 0;
        inorder(root,ksmall,cnt,k);
        return ksmall;
    }
};
