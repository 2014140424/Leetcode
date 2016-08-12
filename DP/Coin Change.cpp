/**
* ��������С��С�������0������0�����amount
* ע����dp[i] = amount + 1��ʾ�ղ�����
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
		int dp[amount + 1];
		dp[0] = 0;
		for(int i=1; i<=amount; ++i) {
			dp[i] = amount + 1;
		}
		sort(coins.begin(),coins.end());
		for(int i=1; i<=amount; ++i) {
			for(int j=0; coins[j]<=i && j<n; ++j) {
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
		return dp[amount] > amount ? -1 : dp[amount];
    }
};