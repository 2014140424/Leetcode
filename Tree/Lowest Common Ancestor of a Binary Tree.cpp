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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == NULL) {
            return root;
        }
        TreeNode* pp = lowestCommonAncestor(root->left, p, q);
        TreeNode* qq = lowestCommonAncestor(root->right, p, q);
        if(pp != NULL && qq != NULL)
            return root;
        return pp == NULL ? qq : pp;
    }
}; 