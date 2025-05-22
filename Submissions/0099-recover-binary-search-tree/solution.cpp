class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* middle = nullptr;
    TreeNode* last = nullptr;
    TreeNode* prev = nullptr;

    void inorder(TreeNode* root) {
        if (root == nullptr) return;

        inorder(root->left);

        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;
        prev = nullptr;

        inorder(root);

        if (first && last) {
            std::swap(first->val, last->val);
        } else if (first && middle) {
            std::swap(first->val, middle->val);
        }
    }
};

