/**
* ��Ҫ˼�룺Ħ��ͶƱ�����������һ�����ڰ�����Ԫ�أ��򷴸�ѡ��������ͬ��Ԫ��һ���õ������ʣ�µĿ϶����Ǹ����ڰ�����Ԫ�ء�
* ����ʵ�֣���res��¼ʣ������Ԫ�أ�flag��ʾʣ����Ԫ�صĸ�����ÿ�ζ���һ����Ԫ��nums[i],���res==nums[i],��ʣ������Ԫ�ظ�����1�����res!=nums[i],flag>0,���ǰ�nums[i]��һ��res��ȥ�����flag==0,��ʾû��Ԫ��ʣ��������res=nums[i]��
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

