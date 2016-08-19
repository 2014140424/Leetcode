/**
 * ��Ŀ���ж�һ�ö������Ƿ��Ƕ���������
 * ˼�룺���������������������һ�����������
 * ���̣���pre������¼�����������һ���ڵ����ֵ������������һ���ڵ�ֵӦ�ô���pre�������Ƕ���������
 * ϸ��: ������һ���ڵ�ʱ��������һ���ڵ㣬������Ҫ���⴦��
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