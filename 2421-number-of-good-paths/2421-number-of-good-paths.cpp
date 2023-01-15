class Solution {
  vector<vector<int>> adj;
  vector<int> par, sz;

  int findLeader(int u) {
    if (u == par[u])return u;
    return par[u] = findLeader(par[u]);
  }

public:
  int numberOfGoodPaths(vector<int> &vals, vector<vector<int>> &edges) {
    const int n = vals.size();
    adj = vector<vector<int>>(n);
    par = vector<int>(n), sz = vector<int>(n, 1);
    iota(par.begin(), par.end(), 0);
    for (auto &e: edges) adj[e[0]].emplace_back(e[1]), adj[e[1]].emplace_back(e[0]);
    sort(edges.begin(), edges.end(), [&](const vector<int> &u, const vector<int> &v) {
      return max(vals[u[0]], vals[u[1]]) < max(vals[v[0]], vals[v[1]]);
    });
    int res = n;
    for (auto &e: edges) {
      int u = findLeader(e[0]), v = findLeader(e[1]);
      if (vals[u] == vals[v]) {
        res += sz[u] * sz[v];
        sz[u] += sz[v];
        par[v] = u;
      } else if (vals[u] > vals[v]) {
        par[v] = u;
      } else {
        par[u] = v;
      }
      cout << '\n';
    }
    return res;

  }
};