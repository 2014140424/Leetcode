/**
 *	��Ŀ��Ѱ�Ҷ����������ڵ�������������
 *	˼�룺1�����root���������ڵ�֮һ������������Ⱦ���root��2����������ڵ�ֱ���root�����������У�root������������ȣ�
 *		3����������ڵ㶼��root��һ�������У�����˵������������ô����������Ƚ���root�ڡ�������û�й�ϵ��
 *	���̣�1���ݹ����,rootΪ�����ڵ�֮һ����rootΪNULL��2�����������ݹ�����������ֱ�����������ݹ�Ѱ�����ڵ㣻
 *		3)����ֱ�λ�������������ظ������������ط�NULL�Ľڵ㡣
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