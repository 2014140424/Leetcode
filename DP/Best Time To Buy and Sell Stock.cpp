/**
* 对于同样的高峰之前，越低的低谷，盈利越大，所以程序不断地更新minPrice；
* 有可能大低谷在大高峰之前，所以需要对比res
* 很简单的道理，说清楚这么难
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if(n < 2) {
			return 0;
		}
		int minPrice = prices[0];
		int res = 0;
		for(int i=1; i<n; ++i) {
			if(prices[i] > minPrice) {
				res = max(res, prices[i]-minPrice);
			}
			else {
				minPrice = prices[i];
			}
		}
		return res;
    }
};