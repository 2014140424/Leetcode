/*
* 不限次数，所有我们要在每次低谷买入，每次高峰卖出；
* 高峰-低谷 = 高峰和低谷之间各个上升阶段的上升值的和
* 最高值 = 所有攀升的的阶段的攀升值得和值
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)
            return 0;
        int res = 0;
        for(int i=0; i<n-1; ++i) {
            if(prices[i] < prices[i + 1]) {
                res += (prices[i + 1] - prices[i]);
            }
        }
        return res;
    }
};