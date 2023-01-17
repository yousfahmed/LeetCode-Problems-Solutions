class Solution {
  vector<vector<int>> dp;
  vector<vector<char>> vis;
  vector<int> a;
  int n,f;

  int solve(bool j, int i) {
    if (i == n)return !j ? 0 : -1e9;
    int &ret = dp[j][i];
    if (vis[j][i])return ret;
    vis[j][i] = true;
    return ret = max(
        solve(j, i + 1),
        solve(!j, i + 1) + (j ? a[i] : -a[i]-f)
    );
  }

public:
  int maxProfit(vector<int> &aa, int fee) {
    f = fee;
    a = aa;
    n = a.size();
    dp = vector<vector<int>>(2, vector<int>(n));
    vis = vector<vector<char>>(2, vector<char>(n));
    return solve(0, 0);
  }
};