/**
* ����һ������hash��¼������ĸ���һ�γ��ֵ�λ�ã������������ʾ��ĸ�������ֵ��ʾ����ĸ���һ�γ��ֵ�λ�á�
* hash�����ʼȫ����-1����ʾ������ĸ��δ���ֹ���
* border��ʾ���һ����Чλ�ã���ʼʱborderΪ-1����ʾ����λ����Ч���Ժ�ÿ�γ����ظ�Ԫ��border���ᱻ��Ϊ���ظ�Ԫ���ϴε�λ��
* ѭ��������ĸ���д������s[i]��ǰû���ֹ�����hash[s[i]]==0�����s[i]������border�Լ���ǰ����hash[s[i]] <= border;�������������Ӱ��border��ֵ��ֱ�Ӹ���hash����͵�ǰ����thisLength���ж��������࣬����������⣩�����s[i]���ֹ��ҳ�����border�Ժ�Ҳ����hash[s[i]] > border, ��ʱ��Ϊ�ظ�Ԫ�س�����thisLength���������ǵ�Ԫ���У���ʱ��Ҫ����border�����¼���thisLength��
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
		if(n == 0)
			return 0;
		int hash[150];
		memset(hash, -1, sizeof(hash));
		int border = -1;
		int thisLength = 0;
		int maxLength = 0;
		for(int i=0; i<n; ++i) {
			if(hash[s[i]] == -1 || hash[s[i]] <= border) {
				hash[s[i]] = i;
				thisLength++;				
			}
			else {				
				border = hash[s[i]];
				thisLength = i - border;	
				hash[s[i]] = i;
			}
			maxLength = max(maxLength, thisLength);
		}
		return maxLength;
    }
};