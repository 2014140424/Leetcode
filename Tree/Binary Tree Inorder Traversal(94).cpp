/**
 *	��Ŀ���ǵݹ��������
 *	ϸ�ڣ���Ҳ�ñ���
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
        stack<TreeNode*> st;
		TreeNode* t = root;
		while(t != NULL || !st.empty()) {
			while(t != NULL) {
				st.push(t);
				t = t->left;
			}
			t = st.top();
			st.pop();
			res.push_back(t->val);
			t = t->right;
		}
		return res;
    }
};