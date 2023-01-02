class Solution {
  int n;
  vector<int> a;
  vector<vector<vector<vector<int>>>> mem;

  int dp(bool f, bool t, int i, int c) {
    if (i == n) i = 0;
    if(c == n)return 0;
    int &ret = mem[f][t][i][c];
    if (~ret)return ret;
    if (c) {
      if (c == n - 1) {
        if (f) {
          ret = 0;
        } else if (t) {
          ret = a[i];
        } else {
          ret = 0;
        }
      } else {
        ret = dp(f, true, i + 1, c + 1);
        if (t)
          ret = max(
              ret,
              dp(f, false, i + 1, c + 1) + a[i]
          );
      }
    } else {
      ret = max(
          dp(true, false, i + 1, 1) + a[i],
          dp(false, true, i + 1, 1)
      );
    }
    return ret;
  }

public:
  int rob(vector<int> &nums) {
    a.swap(nums), n = a.size();
    mem = vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2, vector<vector<int>>(n, vector<int>(n,
                                                                                                                   -1))));
    int res = 0;
    for (int i = 0; i < n; ++i)
      res = max(res, dp(0, 0, i, 0));
    return res;
  }
};