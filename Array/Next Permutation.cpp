class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
		if(n == 0)
			return;
		int pos =  -1;
		for(int i=n-1; i-1>=0; --i) {
			if(nums[i] > nums[i-1]) {
				pos = i - 1;
				break;
			}
		}
		if(pos == -1) {
			reverse(nums.begin(), nums.end());
			return;
		}
		for(int i=n-1; i>pos; --i) {
			if(nums[i] > nums[pos]) {
				swap(nums[i], nums[pos]);
				break;
			}
		}
		reverse(nums.begin()+pos, nums.end());		
    }
};