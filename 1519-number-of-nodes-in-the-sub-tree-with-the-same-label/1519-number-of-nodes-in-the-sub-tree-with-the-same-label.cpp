class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>> edges, string labels) {
    vector<vector<int>> adj(n);
    for (auto &e: edges) {
      adj[e[0]].emplace_back(e[1]);
      adj[e[1]].emplace_back(e[0]);
    }
    vector<int> ans(n), t(26);
    function<void(int, int, vector<int> &)> dfs = [&](int u, int p, vector<int> &ret) {
      int now = ret[labels[u] - 'a'];
      for (int &v: adj[u])
        if (v != p)
          dfs(v, u, ret);
      ++ret[labels[u] - 'a'];
      ans[u] = ret[labels[u] - 'a'] - now;
    };
    dfs(0, 0, t);
    return ans;
  }
};