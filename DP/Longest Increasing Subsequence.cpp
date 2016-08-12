/**
* dp[i]��ʾ��nums[i]��β����������г��ȣ�
* ��ʼ����ȫ��dp[i]Ϊ1
* �κ�nums[i],����֮ǰ��������nums[j]���ζԱȣ��������nums[j],������ӵ�nums[j]�����γɣ��µĵ������У�����֮ǰ�ıȽϳ��ȡ��ҳ�����dp[i]�����ֵ��
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
		if(n < 2) {
			return n;
		}
		int dp[n];
		for(int i=0; i<n; ++i) {
			dp[i] =  1;
		}
		int mh = 1;
		for(int i=1; i<n; ++i) {
			for(int j=0; j<i; ++j) {
				if(nums[i] > nums[j]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			mh = max(mh, dp[i]);
		}
		return mh;
    }
};