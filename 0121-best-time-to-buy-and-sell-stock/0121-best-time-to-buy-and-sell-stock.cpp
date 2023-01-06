class Solution {
public:
  int maxProfit(vector<int> &prices) {
    const int n = prices.size();
    reverse(prices.begin(), prices.end());
    int mx = 0;
    int ret = 0;
    for (int &i: prices) {
      ret = max(ret, mx - i);
      if (i > mx) mx = i;
    }
    return ret;
  }
};
