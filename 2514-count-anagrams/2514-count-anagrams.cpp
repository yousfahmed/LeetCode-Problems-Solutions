const int mod = 1e9 + 7, N = 1e5 + 7;
int fact[N], inv[N], vs = 1;

class Solution {
  int mul(int a, int b) {
    return ((1LL * a) * b) % mod;
  }

  int power(int n, int p) {
    if (!p)return 1;
    int res = power(n, p >> 1);
    res = mul(res, res);
    if (p & 1)res = mul(res, n);
    return res;
  }

public:

  int countAnagrams(string s) {
    if (vs) {
      vs = 0;
      fact[0] = inv[0] = 1;
      for (int i = 1; i < N; ++i) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = power(fact[i], mod - 2);
      }
    }
    s.push_back(' ');
    string x;
    int res = 1;
    for (char &ch: s) {
      if (ch == ' ') {
        vector<int> frq(30);
        for (char &i: x)
          ++frq[i - 'a'];
        res = mul(res, fact[x.length()]);
        for (int i = 0; i < 30; ++i)
          res = mul(inv[frq[i]], res);
        x.clear();
      } else {
        x += ch;
      }
    }
      return res;
  }
};
