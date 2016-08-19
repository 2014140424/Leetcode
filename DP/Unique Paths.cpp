/**
* 题目：m*n的格子，从左上角到右下角的所有路径数量
* 思路：递推公式：dp[i][j] = dp[i-1][j] + dp[i][j-1]，设置好初始条件即可
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