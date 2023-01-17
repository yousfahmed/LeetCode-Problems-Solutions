class NumMatrix {
  vector<vector<int>> a;
  int n, m;
public:
  NumMatrix(vector<vector<int>> &matrix) {
    n = matrix.size(), m = matrix[0].size();
    a = vector<vector<int>>(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[i][j] = matrix[i][j] -
                  (i && j ? a[i - 1][j - 1] : 0) +
                  (i ? a[i - 1][j] : 0) +
                  (j ? a[i][j - 1] : 0);
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int res = a[row2][col2];
    if (row1) res -= a[row1 - 1][col2];
    if (col1) res -= a[row2][col1 - 1];
    if (row1 && col1) res += a[row1 - 1][col1 - 1];
    return res;
  }
};
