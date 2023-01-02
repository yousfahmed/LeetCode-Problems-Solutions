class Solution {
  int lvl(int u) {
    return 31 - __builtin_clz(u);
  }

  int LCA(int u, int v) {
    int a = lvl(u), b = lvl(v);
    while (a > b)u >>= 1, --a;
    while (a < b)v >>= 1, --b;
    while (u != v) u >>= 1, v >>= 1, --a;
    return u;
  }

public:
  vector<int> cycleLengthQueries(int n, vector<vector<int>> &queries) {
    vector<int> ret;
    ret.reserve(queries.size());
    for (auto &x: queries) {
      int a = lvl(x[0]), b = lvl(x[1]), lca = LCA(x[0], x[1]);
      if (lca == x[0]) {
        ret.emplace_back(b - a + 1);
      } else if (lca == x[1]) {
        ret.emplace_back(a - b + 1);
      } else {
        ret.emplace_back(a + b - 2 * lvl(lca) + 1);
      }
    }
    return ret;
  }
};