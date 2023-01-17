class Solution {
  vector<vector<int>> mem;

  int dp(int i, int j) {
    if (j <= i)return 1;
    int &ret = mem[i][j];
    if (~ret)return ret;
    ret = 0;
    for (int k = i; k <= j; ++k)
      ret += dp(i, k - 1) * dp(k + 1, j);
    return ret;
  }

public:
  int numTrees(int n) {
    mem = vector<vector<int>>(n, vector<int>(n, -1));
    return dp(0, n - 1);
  }
};