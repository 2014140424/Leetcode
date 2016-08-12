/**
* ����ͬ���ĸ߷�֮ǰ��Խ�͵ĵ͹ȣ�ӯ��Խ�����Գ��򲻶ϵظ���minPrice��
* �п��ܴ�͹��ڴ�߷�֮ǰ��������Ҫ�Ա�res
* �ܼ򵥵ĵ���˵�����ô��
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