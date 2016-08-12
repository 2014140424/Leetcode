class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
		if(n == 0)
			return 0;
		int res = nums[0];
		int flag = 1;
		for(int i=1; i<n; ++i) {
			if(nums[i] == res) {
			    flag++;
			}
			else {
			    if(flag == 0) {
			        res = nums[i];
			        flag = 1;
			    }
			    else {
			        flag--;
			    }
			}
		}
		return res;
    }
};

