/**
* 最大子序列问题，不必多说
* 改天加上分值解法
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        int this_max = nums[0];
        int res = nums[0];
        for(int i=1; i<n; ++i) {
            if(this_max < 0) {
                this_max = nums[i];
            }
            else{
                this_max += nums[i];
            }
            res = max(res, this_max);
        }
        return res;
    }
};