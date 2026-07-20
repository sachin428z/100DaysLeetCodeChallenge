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
    int ans=0;

    int dfs(TreeNode* root) {
        if(!root) return INT_MIN;

        int leftMax=dfs(root->left);
        int rightMax=dfs(root->right);

        int mx=max(root->val,max(leftMax,rightMax));

        if(root->val==mx) ans++;

        return mx;
    }
    
    int countDominantNodes(TreeNode* root) {
       ans=0;
        dfs(root);
        return ans;
    }
};