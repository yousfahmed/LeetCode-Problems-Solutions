class Solution {
public:
  int minFallingPathSum(vector<vector<int>> &matrix) {
    const int N = matrix.size();
    int dp[2][N];
    for (int i = 0; i < N; ++i) 
      dp[0][i] = matrix[0][i];
    for (int i = 0, b; i < N - 1; ++i) {
      memset(dp[(i + 1) & 1], 32, sizeof dp[(i + 1) & 1]);
      for (int j = 0; j < N; ++j) {
        for (int k = -1; k <= 1; ++k) {
          b = k + j;
          if (b >= 0 and b < N) {
            dp[(i + 1) & 1][b] = min(
                dp[(i + 1) & 1][b],
                dp[i & 1][j] + matrix[i + 1][b]
            );
          }
        }
      }
    }
    return *min_element(dp[(N - 1) & 1], dp[(N - 1) & 1] + N);
  }
};