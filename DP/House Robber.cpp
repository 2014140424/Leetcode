/**
* ×´Ì¬×ª»»£¬dp
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        int max_r = nums[0];
        int max_n = 0;
        for(int i=1; i<n; ++i) {
            int tmp_r = max_n + nums[i];
            int tmp_n = max(max_r, max_n);
            max_n = tmp_n;
            max_r = tmp_r;
        }
        return max(max_n, max_r);
    }
};