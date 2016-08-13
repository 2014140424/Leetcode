/**
*	题目：s是只包含'('字符和')'字符的字符串，求最长有效括号对的长度
*	思路：将互相匹配的左括号和右括号用1表示，其余不能匹配的用0表示，然后这个题就转化为寻找最长连续为1的子序列长度
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