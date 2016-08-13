/**
* 	题目：求连续子序列的最大乘积
* 	思想：设maxProduct[i]为以nums[i]为结尾的所有连续子序列中最大的子序列和，则有递推公式：
*		maxProduct[i] = max(minProduct[i-1]*nums[i], maxProduct[i-1]*nums[i], nums[i]);
*	细节：乘法不同于加法，乘法有可能出现最小的负数乘负数，变为最大的数
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int minCurrent = nums[0];
        int maxCurrent = nums[0];
        int res = nums[0];
        for(int i=1; i<n; ++i) {
            int tmp1 = maxCurrent * nums[i];
            int tmp2 = minCurrent * nums[i];
            maxCurrent = max(max(tmp1, tmp2), nums[i]);
            minCurrent = min(min(tmp1, tmp2), nums[i]);
            res = max(res, maxCurrent);
        }
        return res;
    }
};