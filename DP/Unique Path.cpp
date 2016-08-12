/**
* 也没啥可说的，简单的动态规划
* 注意动态规划的初始条件设置
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
			return 0;
		int dp[m][n];
		memset(dp, 0, sizeof(dp));
		for(int i=0; i<n; ++i) {
			dp[0][i] = 1;
		}
		for(int i=0; i<m; ++i) {
			dp[i][0] = 1;
		}
		for(int i=1; i<m; ++i) {
			for(int j=1; j<n; ++j) {
				dp[i][j] = dp[i-1][j] + dp[i][j-1];
			}
		}
		return dp[m-1][n-1];
    }
};