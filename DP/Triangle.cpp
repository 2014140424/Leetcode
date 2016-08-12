/**
* 从下层开始计算，倒数第一层到最底下的最短路径就为本身数值
* 倒数第二层，到最底下的最短路径为
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        if(m == 0)
            return 0;
        int n = triangle[m - 1].size();
        vector<int> dp = triangle[m - 1];
        for(int i=m-2; i>=0; --i) {
            for(int j=0; j<=i; ++j) {
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};