const int N = 1e5 + 7;
int mem[N], vis[N], vs;

class Solution {
  int k;
  string s;

  int dp(int i) {
    if (i >= s.length())return 0;
    int &ret = mem[i];
    if (vis[i] == vs)return ret;
    vis[i] = vs;
    ret = 1e6;
    long long x = 0;
    while (i < s.length()) {
      x = (x * 10) + (s[i] - '0');
      if (x > k)break;
      ret = min(ret, dp(i + 1) + 1);
      ++i;
    }
    return ret;
  }

public:
  int minimumPartition(string ss, int x) {
    k = x;
    ss.swap(s);
    vs++;
    int res = dp(0);
    if (res < 1e6)return res;
    return -1;
  }
};