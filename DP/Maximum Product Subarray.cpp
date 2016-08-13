/**
* 	��Ŀ�������������е����˻�
* 	˼�룺��maxProduct[i]Ϊ��nums[i]Ϊ��β���������������������������кͣ����е��ƹ�ʽ��
*		maxProduct[i] = max(minProduct[i-1]*nums[i], maxProduct[i-1]*nums[i], nums[i]);
*	ϸ�ڣ��˷���ͬ�ڼӷ����˷��п��ܳ�����С�ĸ����˸�������Ϊ������
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