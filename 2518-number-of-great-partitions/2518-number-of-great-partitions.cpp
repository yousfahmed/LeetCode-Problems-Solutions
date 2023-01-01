const int N = 1e3 + 4, mod = 1e9 + 7;
int mem[N][N], vis[N][N], vs;

class Solution {
  int n;
  vector<int> a;
  int K;

  int power(int x, int p) {
    if (!p)return 1;
    long long res = power(x, p >> 1);
    res = (res * res) % mod;
    if (p & 1) res = (res * x) % mod;
    return res;
  }

  int dp(int i, int k) {
    if (k >= K)return 0;
    if (i == n) return 1;
    int &ret = mem[i][k];
    if (vis[i][k] == vs)return ret;
    vis[i][k] = vs;
    ret = dp(i + 1, k) + dp(i + 1, k + a[i]);
    if(ret >=mod)   ret -= mod;
    return ret;
  }

public:
  int countPartitions(vector<int> &nums, int k) {
    
    K = k;
    if (accumulate(nums.begin(), nums.end(), 0LL) < 2 * k) return 0;
    a.swap(nums);
    n = a.size();
    ++vs;
    return ((power(2, n) + 0LL - 2*dp(0, 0)%mod)+mod)%mod;
  }
};