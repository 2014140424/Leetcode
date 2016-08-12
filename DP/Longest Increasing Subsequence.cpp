/**
* dp[i]表示以nums[i]结尾的最长的子序列长度；
* 开始假设全部dp[i]为1
* 任何nums[i],和它之前的所有数nums[j]依次对比，如果大于nums[j],则把它接到nums[j]后面形成，新的递增序列，并于之前的比较长度。找出所有dp[i]的最大值。
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