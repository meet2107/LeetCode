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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int,TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();

                if(node->left){
                    parent[node->left->val] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right->val] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_map<int,int> vis;
        q.push(target);

        while(k-- && !q.empty()){
            int size = q.size();

            for(int i=0;i<size;i++){
                auto node = q.front();
                q.pop();

                vis[node->val]= 1;

                if(node->left && !vis[node->left->val]){
                    q.push(node->left);
                }
                if(node->right && !vis[node->right->val]){
                    q.push(node->right);
                }
                if(parent[node->val] && !vis[parent[node->val]->val]){
                    q.push(parent[node->val]);
                }
            }
        }

        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
