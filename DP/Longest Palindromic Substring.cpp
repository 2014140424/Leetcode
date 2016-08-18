class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        bool dp[n][n];
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; ++j) {
				if(i >= j) {
					dp[i][j] = true;
				}
				else {
					dp[i][j] = false;
				}
			}
		}
		int res = 0;
		for(int i=2; i<n; ++i) {
			for(int j=0; j<=n-i; ++j) {
				if(s[j] == s[j+i-1] && dp[j+1][j+i-2]) {
					dp[j][j+i-1] = true;
					res = max(res, i);
				}
			}
		}
		return res;
    }
};