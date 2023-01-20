class Solution {
  vector<vector<int>> g;
  int n, m;

  void set(vector<vector<int>> &a) {
    n = a.size(), m = a[0].size();
    g = vector<vector<int>>(n, vector<int>(m));
    g[0][0] = a[0][0];
    for (int i = 1; i < m; ++i)
      g[0][i] = g[0][i - 1] + a[0][i];
    for (int i = 1; i < n; ++i)
      g[i][0] = g[i - 1][0] + a[i][00];
    for (int i = 1; i < n; ++i)
      for (int j = 1; j < m; ++j)
        g[i][j] = a[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
  }

  int query(int sx, int sy, int ex, int ey) {
    assert(sx >= 0 and sx < n and sy >= 0 and sy < m and ex >= 0 and ex < n and ey >= 0 and ey < m);
    int res = g[ex][ey];
    if (sx)res -= g[sx - 1][ey];
    if (sy)res -= g[ex][sy - 1];
    if (sx && sy)res += g[sx - 1][sy - 1];
    return res;
  }

public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k) {
    set(mat);
    vector<vector<int>> ret(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        ret[i][j] = query(
            max(0, i - k),
            max(0, j - k),
            min(n - 1, i + k),
            min(m - 1, j + k)
        );
      }
    }
    return ret;
  }
};
