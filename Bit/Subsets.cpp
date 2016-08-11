class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        if(n == 0) {
            return res;
        }
        vector<int> tmp;
        putRes(res, tmp, nums, 0);
        return res;
    }
    
    void putRes(vector<vector<int>>& res, vector<int>& tmp, vector<int>& nums, int s) {
    	int n = nums.size();
    	if(s < n - 1) {
    		vector<int> tmp1 = tmp;
    		tmp1.push_back(nums[s]);
    		putRes(res, tmp1, nums, s+1);
    		putRes(res, tmp, nums, s+1);
    	} else {
			vector<int> tmp1 = tmp;
    		tmp1.push_back(nums[s]);
    		res.push_back(tmp);
    	}
    }
};

//注意点：对于每个数都有放入或不放入两种情况，到组后一个数的时候结束递归