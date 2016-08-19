/**
*	题目：股票问题，交易两次
*	思路：1）从左到右遍历，求出0-i之间的最大盈利；2）从右到左遍历，求出i-(n-1)之间的最大盈利；3）res = max(res, pre[i] + post[i]);
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) {
            return 0;
        }
        int pre[n] = {0};
        int curMin = prices[0];
        for(int i=1; i<n; ++i) {
            if(prices[i] < curMin) {
                curMin = prices[i];
                pre[i] = pre[i - 1];
            }
            else {
                pre[i] = max(pre[i - 1], prices[i] - curMin);
            }
        }
        int post[n] = {0};
        int curMax = prices[n - 1];
        for(int i=n-2; i>=0; --i) {
            if(prices[i] > curMax) {
                curMax = prices[i];
                post[i] = post[i+1];
            }
            else {
                post[i] = max(post[i+1], curMax - prices[i]);
            }
        }
        int res = 0;
        for(int i=0; i<n; ++i) {
            res = max(res, pre[i] + post[i]);
        }
        return res;
    }
};