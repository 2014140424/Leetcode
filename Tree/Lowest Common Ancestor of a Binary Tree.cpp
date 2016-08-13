/**
 *	题目：寻找二叉树两个节点的最近公共祖先
 *	思想：1）如果root就是两个节点之一，最近公共祖先就是root；2）如果两个节点分别在root的左右子树中，root是最近公共祖先；
 *		3）如果两个节点都在root的一棵子树中（比如说左子树），那么最近公共祖先将和root节、右子树没有关系。
 *	过程：1）递归出口,root为两个节点之一或者root为NULL；2）如果不满足递归出口条件，分别从左右子树递归寻找两节点；
 *		3)如果分别位于左右子树返回根；否则尽量返回非NULL的节点。
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