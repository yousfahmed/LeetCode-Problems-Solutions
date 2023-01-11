class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> adj(n);
    for (auto &x: edges) {
      adj[x[0]].emplace_back(x[1]);
      adj[x[1]].emplace_back(x[0]);
    }
    function<int(int, int)> dfs = [&](int u, int p) {
      int res = 0;
      for (int &v: adj[u])
        if (v != p) {
          int x = dfs(v, u);
          if (x or hasApple[v]) res += 2;
          res += x;
        }
      return res;
    };
    return dfs(0, 0);


  }
};
