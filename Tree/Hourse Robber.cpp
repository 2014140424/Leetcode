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
    int rob(TreeNode* root) {
		int noMax = 0, robMax = 0;
		get(root, robMax, noMax);
        return max(noMax, robMax);
    }
	
	void get(TreeNode* root, int& robMax, int& noMax) {
		if(root == NULL) {
			robMax = 0;
			noMax = 0;
			return;
		}
		if(root->left == NULL && root->right == NULL) {
			robMax = root->val;
			noMax = 0;
			return;
		}
		int noMaxL, robMaxL, noMaxR, robMaxR;
		get(root->left, robMaxL, noMaxL);
		get(root->right, robMaxR, noMaxR);
		robMax = noMaxL + noMaxR + root->val;
		noMax = max(robMaxL, noMaxL) + max(noMaxR, robMaxR);
		
	}
};