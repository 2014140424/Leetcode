class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
		int n = nums.size();
		int tmp = 0;
		for(int i=0; i<n; ++i) {
			tmp = (tmp ^ nums[i]);
		}
		tmp = ((~(tmp - 1)) & tmp);
		int a = 0;
		int b = 0;
		for(int i=0; i<n; ++i) {
			if((nums[i] & tmp) == 0) {
				a = a ^ nums[i];
			}
			else {
				b = b ^ nums[i];
			}
		}
		res.push_back(a);
		res.push_back(b);
		return res;
    }
};
//注意点：找出最低位的1    tmp = ((~(tmp - 1)) & tmp);