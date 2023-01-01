const int N = 1e6 + 4;
vector<int> p;
char vis[N];
pair<int, int> table[25][N];

class Solution {
  void sieve() {
    for (int i = 2; i < N; ++i)
      if (!vis[i]) {
        p.emplace_back(i);
        for (int j = i; j < N; j += i)
          vis[j] = true;
      }
    for (int i = 0; i < p.size() - 1; ++i)
      table[0][i] = {p[i + 1] - p[i], p[i]};
    for (int msk = 1; (1 << msk) <= p.size() - 1; ++msk) {
      for (int i = 0; (i + (1 << msk) - 1) < p.size() - 1; ++i) {
        table[msk][i] = min(
            table[msk - 1][i],
            table[msk - 1][i + (1 << (msk - 1))]
        );
      }
    }
  }

public:
  vector<int> closestPrimes(int left, int right) {
    if (p.empty())sieve();
    int f = lower_bound(p.begin(), p.end(), left) - p.begin();
    if (f == p.size() or p[f] > right)return {-1, -1};
    int s = upper_bound(p.begin(), p.end(), right) - p.begin();
    s -= 2;
    if (s < f)return {-1, -1};
    int log = 31 - __builtin_clz(s - f + 1);
    auto res = min(
        table[log][f],
        table[log][s - (1 << log) + 1]
    ).second;
    vector<int> ret = {
        res,
        *upper_bound(p.begin(), p.end(), res)
    };
    return ret;
  }
};