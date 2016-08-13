/**
*	题目：m*n的格子，其中有一些格子是障碍无法通过，求从到左上角到右下角一共有多少走法
*	思路：到达一个格子的路径数量依赖于到达该格子上方和左方格子的路径数量，多判断一下是否是该格子是否是障碍而已
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0)
            return 0;
        int n = obstacleGrid[0].size();
        if(n == 0)
            return 0;
        vector<vector<int>> dp = obstacleGrid;
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for(int i=1; i<n; ++i) {
            if(obstacleGrid[0][i] == 1) {
                dp[0][i] = 0;
            }
            else {
                dp[0][i] = dp[0][i - 1];
            }
        }
        
        for(int i=1; i<m; ++i) {
            if(obstacleGrid[i][0] == 1) {
                dp[i][0] = 0;
            }
            else {
                dp[i][0] = dp[i - 1][0];
            }
        }
        
        for(int i=1; i<m; ++i) {
            for(int j=1; j<n; ++j) {
                if(obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};