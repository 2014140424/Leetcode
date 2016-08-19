class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
		if(n == 0)
			return nums;
		vector<int> res;
		sort(nums.begin(), nums.end());
		vector<int> tmp(n);
		vector<int> dp(n, 1);
		for(int i=0; i<n; ++i) {
			tmp[i] = i;
		}
		int maxSize = 1;
		int endMax = 0;
		for(int i=1; i<n; ++i) {
			for(int j=0; j<i; ++j) {
				if(nums[i] % nums[j] != 0)
					continue;
				if(dp[j]+1 > dp[i]) {
					dp[i] = dp[j] + 1;
					tmp[i] = j;
					if(dp[i] > maxSize) {
						maxSize = dp[i];
						endMax = i;
					}
				}
			}
		}
		res.push_back(nums[endMax]);
		for(int i=endMax; tmp[i]!=i; i=tmp[i]) {
			res.push_back(nums[tmp[i]]);
		}
		reverse(res.begin(), res.end());
		return res;
    }
};