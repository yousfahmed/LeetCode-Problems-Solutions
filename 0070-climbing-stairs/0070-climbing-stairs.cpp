class Solution {

public:
  int climbStairs(int n) {
    int dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      if (dp[i]) {
        if (i + 2 <= n) {
          dp[i + 1] += dp[i];
          dp[i + 2] += dp[i];
        } else if (i + 1 <= n) {
          dp[i + 1] += dp[i];
        }
      }
    }
    return dp[n];
  }
};