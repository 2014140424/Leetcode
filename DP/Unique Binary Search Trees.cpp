/**
* dp[n] = dp[0]*dp[n-1] + dp[1]*dp[n-2] + бнбн + dp[n-1]*dp[0];
*/
class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];        
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i=1; i<=n; ++i) {
           for(int j=0; j<=i-1; ++j) {
               dp[i] += (dp[j] * dp[i-j-1]);
           }
        }
        return dp[n];
    }
};