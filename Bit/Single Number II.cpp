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
//基本思路是， 每一位出现3个1就清零，以上是优化算法。
//需要注意的：每次循环开始的时候，不会有一位one和two同时为1。
//第一次循环都为0，不会出现相同的一位都为1；
//以后每次循环，总是将one和two相同的位合并为three，然后在分别从one和two中清去这一位。
