struct segmentTree {
  vector<int> seg;
  int sz;

  void update(int l, int r, int v, int x, int lx, int rx) {
    if (l <= lx and rx <= r) {
      seg[x] = min(seg[x], v);
      return;
    }
    if (r <= lx or rx <= l)return;
    int m = (rx + lx) >> 1;
    update(l, r, v, x * 2 + 1, lx, m);
    update(l, r, v, x * 2 + 2, m, rx);
  }

  segmentTree(int n) {
    sz = 1;
    while (sz < n)sz <<= 1;
    seg = vector<int>(sz << 1, 1e9);
  }

  int query(int i, int x, int lx, int rx) {
    if (rx - lx == 1) return seg[x];
    int m = (rx + lx) >> 1;
    int res = seg[x];
    if (i < m) res = min(res, query(i, x * 2 + 1, lx, m));
    else res = min(res, query(i, x * 2 + 2, m, rx));
    return res;
  }

  void update(int l, int r, int v) {
    update(l, r, v, 0, 0, sz);
  }

  int query(int i) {
    return query(i, 0, 0, sz);
  }
};


class Solution {
public:
  int jump(vector<int> &nums) {
    const int n = nums.size();
    segmentTree seg(n);
    seg.update(0, 1, 0);
    for (int i = 0; i < n; ++i) 
      seg.update(i, min(n, nums[i] + i + 1), seg.query(i) + 1);
    return seg.query(n - 1);
  }
};