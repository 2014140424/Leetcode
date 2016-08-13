/**
*	��Ŀ��s��ֻ����'('�ַ���')'�ַ����ַ����������Ч���ŶԵĳ���
*	˼·��������ƥ��������ź���������1��ʾ�����಻��ƥ�����0��ʾ��Ȼ��������ת��ΪѰ�������Ϊ1�������г���
*/


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        stack<int> st;
        int dp[n] = {0};
        for(int i=0; i<n; ++i) {
            if(s[i] == '(') {
                st.push(i);
            }
            else if(!st.empty()) {
                dp[st.top()] = 1;
                dp[i] = 1;
                st.pop();
            }
        }
        int thisMax = dp[0];
        int res = dp[0];
        for(int i=1; i<n; ++i) {
            if(dp[i] == 0) {
                thisMax = 0;
            }
            else {
                thisMax++;
                res = max(res, thisMax);
            }
        }
        return res;
    }
};