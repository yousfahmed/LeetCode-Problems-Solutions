class Solution {
  vector<int> val;
#define int long long
  vector<vector<int>> adj, dp;
  int res;

  int go(bool hasRoot, int u, int p) {
    int &ret = dp[hasRoot][u];
    if (~ret)return ret;
    ret = 0;
    multiset<int> s;
    for (int &v: adj[u])
      if (v != p)
        s.insert(go(false, v, u)); /// without the root
    for (int &v: adj[u])
      if (v != p) {
        int cur = go(false, v, u);
        s.erase(s.find(cur));/// delete cur
        int x = go(true, v, u); /// with the root
        if (s.size()) {
          res = max(res, x + *s.rbegin() + val[u]);
        } else {
          res = max(res, x + val[u]);
          res = max(res, cur);
        }
        s.insert(cur);
      }
    if (hasRoot) {
      if (adj[u].size() > 1) {
        for (int &v: adj[u]) {
          if (v == p)continue;
          ret = max(ret, go(1, v, u) + val[u]);
        }
      }

      return ret;
    } else {
      for (int &v: adj[u]) {
        if (v == p)continue;
        ret = max(ret, go(0, v, u));
      }
      ret += val[u];
      return ret;
    }
  };
#undef int
public:
  long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &vl) {
    val.swap(vl);
#define int long long
    adj = vector<vector<int>>(n);
    dp = vector<vector<int>>(2, vector<int>(n, -1));
    for (auto &e: edges) {
      adj[e[0]].emplace_back(e[1]);
      adj[e[1]].emplace_back(e[0]);
    }
    res = 0;
    go(0, 0, 0);
    return res;
#undef int
  }
};