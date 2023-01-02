const int N = 1e4;
int vis[N + 1], frq[N + 1], vs, mem[2][N + 1], vis2[2][N+1];

class Solution {
  vector<int> a;
  int dp(bool t, int i) {
    if (i > N)return 0;
    int &ret = mem[t][i];
    if (vis2[t][i] == vs)return ret;
    vis2[t][i] = vs;
    ret = dp(true, i + 1);
    if (t and vis[i] == vs)
      ret = max(ret, dp(false, i + 1) + frq[i]);
    return ret;
  }

public:
  int deleteAndEarn(vector<int> &nums) {
    ++vs;
    for (int x: nums) {
      if (vis[x] == vs)
        frq[x] += x;
      else
        vis[x] = vs, frq[x] = x;
    }
    a.swap(nums);
    return dp(1, 1);
  }
};