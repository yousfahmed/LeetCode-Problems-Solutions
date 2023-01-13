class Solution {
public:
  int longestPath(vector<int> &parent, string s) {
    const int n = s.length();
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; ++i) {
      adj[i].emplace_back(parent[i]);
      adj[parent[i]].emplace_back(i);
    }
    int ans = 1;
    function<int(int, int)> dfs = [&](int u, int p) {
      vector<int> res{-1, -1};
      char ch = s[u];
      s[u] = '0';
      for (int &v: adj[u])
        if (v != p and s[v] != ch and isalpha(s[v])) {
          res.emplace_back(dfs(v, u));
          sort(res.rbegin(), res.rend());
          res.pop_back();
        }
      replace(res.begin(), res.end(), -1, 0);
      ans = max(ans, res[0] + res[1] + 1);
      return res.front() + 1;
    };
    int u = 0;
    for (char &ch: s) {
      if (isalpha(ch))
        dfs(u, u);
      ++u;
    }
    return ans;
  }
};