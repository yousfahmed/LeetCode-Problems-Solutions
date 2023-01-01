class Solution {
public:
  int distinctPrimeFactors(vector<int> &a) {
    const int n = a.size();
    set<int> res;
    for (int i = 0; i < n; ++i) {
      int x = a[i];
      for (int j = 2; j * j <= x; ++j) {
        if (x % j == 0) {
          res.emplace(j);
          while (!(x % j))x /= j;
        }
      }
      if (x > 1)
        res.emplace(x);
    }
    return (int) (res.size());
  }
};