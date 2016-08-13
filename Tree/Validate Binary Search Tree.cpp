/**
 * 题目：判断一棵二叉树是否是二叉搜索树
 * 思想：二叉搜索树的中序遍历是一个有序的序列
 * 过程：用pre变量记录中序遍历的上一个节点的数值，遍历到的下一个节点值应该大于pre，否则不是二叉搜索树
 * 细节: 遍历第一个节点时不存在上一个节点，所以需要特殊处理
 * 
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* t = root;
        int pre = 0;
        int flag = 0;
        while(!st.empty() || t != NULL) {
            while(t != NULL) {
                st.push(t);
                t = t->left;
            }
            t = st.top();
            st.pop();
            if(t->val <= pre && flag > 0) {
                return false;
            }
            pre = t->val;
            t = t->right;
            flag++;
        }
        return true;
    }
};