class Solution {
  int n;
  vector<int> a;
  vector<vector<int>> mem;

  int dp(bool v = false, int i = 0) {
    if (i == n)return -1e9;
    int &ret = mem[v][i];
    if (~ret)return ret;
    return ret = max(
        dp(v, i + 1),
        a[i] + (v ? -i - 1 : i + 1 + dp(true, i + 1))
    );
  }

public:
  int maxScoreSightseeingPair(vector<int> &values) {
    n = values.size();
    a.swap(values);
    mem = vector<vector<int>>(2, vector<int>(n, -1));
    return dp();
  }
};