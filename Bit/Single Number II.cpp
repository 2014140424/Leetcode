class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	int one = 0, two = 0;
    	int n = nums.size();
    	for(int i=0; i<n; ++i) {
    		int tmp = (one & nums[i]);
    		two = (tmp | two);
    		one = (one ^ nums[i]);
    		int three = (one & two);
    		two = (two & ~three);
    		one = (one & ~three);
    	}
    	return one;
    }
};