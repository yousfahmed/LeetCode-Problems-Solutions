class Solution {

public:
  int uniquePathsIII(vector<vector<int>> &grid) {
    const int n = grid.size(), m = grid[0].size();
    
    vector<vector<int>> vis(n, vector<int>(m));

    pair<int, int> adj[] = {
        {-1, 0},
        {0,  +1},
        {+1, 0},
        {0,  -1}
    };
    auto in = [&](int i, int j) -> bool {
      return i >= 0 and j >= 0 and i < n and j < m;
    };
    int res = 0, cnt = 0;
    function<void(int, int)> fun = [&](int i, int j) {
      if (grid[i][j] == 2) {
        res += (cnt == n * m);
        return;
      }
      for (auto &[a, b]: adj) {
        int x = i + a, y = j + b;
        if (in(x, y) and !vis[x][y] and ~grid[x][y]) {
          ++cnt, vis[x][y] = 1;
          fun(x, y);
          --cnt, vis[x][y] = 0;
        }
      }
    };
    int sx, sy;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          sx = i, sy = j;
        } else if (grid[i][j] == -1) {
          ++cnt;
        }
      }
    }
    ++cnt, vis[sx][sy] = 1;
    fun(sx, sy);
    return res;
  }
};