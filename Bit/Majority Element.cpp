/**
* 主要思想：摩尔投票法，如果存在一个多于半数的元素，则反复选择两个不同的元素一起拿掉，最后剩下的肯定是那个多于半数的元素。
* 具体实现：用res记录剩下来的元素，flag表示剩下来元素的个数。每次对于一个新元素nums[i],如果res==nums[i],则剩下来的元素个数加1；如果res!=nums[i],flag>0,这是把nums[i]和一个res拿去；如果flag==0,表示没有元素剩下来，则res=nums[i]。
*/
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

