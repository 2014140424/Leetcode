class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
		vector<int> res;
		int n = nums.size();
		for(int i=0; i<n; ++i) {
			if(!q.empty() && q.front() == i - k) {
				//res.push_back(nums[q.front()]);
				q.front_pop();
			}
			while(!q.empty() && nums[q.back()] < nums[i]) {
				q.back_pop();
			}
			q.back_push(i);
			if(i > k - 1)
				res.push_back(nums[q.front()]);
		}
		
		return res;
    }
};