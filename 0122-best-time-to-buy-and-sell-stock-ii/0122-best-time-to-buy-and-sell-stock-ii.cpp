class Solution {
  int n;
  vector<int> a;
  vector<vector<int>> mem;
  vector<vector<bool>> vis;

  int dp(bool is = false, int i = 0) {
    if (i == n)return 0;
    int &ret = mem[is][i];
    if (vis[is][i])return ret;
    vis[is][i] = true;
    return ret = max(
        dp(is, i + 1),
        dp(!is, i + 1) + (is ? a[i] : -a[i])
    );
  }

public:
  int maxProfit(vector<int> &prices) {
    n = prices.size();
    mem.resize(2, vector<int>(n));
    vis.resize(2, vector<bool>(n));
    a.swap(prices);
    return dp();
  }
};