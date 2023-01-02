class Solution {
#define bs(x, v) binary_search(x.begin(),x.end(),v)
public:
  bool isPossible(int n, vector<vector<int>> &edges) {
    vector<int> cnt(n + 1);
    for (auto &x: edges) {
      ++cnt[x[0]], ++cnt[x[1]];
      if (x[0] > x[1])
        swap(x[0], x[1]);
    }
    sort(edges.begin(), edges.end());
    vector<int> odds;
    for (int i = 1; i <= n; ++i)
      if (cnt[i] & 1)
        odds.emplace_back(i);

    if (odds.empty())
      return true;
    if (odds.size() & 1 or odds.size() > 4)
      return false;
    vector<int> t;
    if (odds.size() == 2) {
      int &u = odds[0], &v = odds[1];
      if (!bs(edges, odds)) {
        return true;
      }
      for (int i = 1; i <= n; ++i) {
        if (i != u && i != v) {
          t = {min(u, i), max(u, i)};
          if (bs(edges, t))continue;
          t = {min(v, i), max(v, i)};
          if (bs(edges, t))continue;
          return true;
        }
      }
      return false;
    }
    for (int i = 0; i < 4; ++i) {
      for (int j = i + 1; j < 4; ++j) {
        t = {odds[i], odds[j]};
        if (bs(edges, t))continue;
        t.clear();
        for (int k = 0; k < 4; ++k)
          if (k != i && k != j)
            t.push_back(odds[k]);
        if (bs(edges, t))continue;
        return true;
      }
    }
    return false;
  }

#undef bs

};