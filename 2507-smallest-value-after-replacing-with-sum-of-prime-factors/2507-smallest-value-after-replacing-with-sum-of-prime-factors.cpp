const int N = 1e5 + 1;
int mem[N];

class Solution {
public:
  int smallestValue(int x) {
    if (x == 4)return 4;
    int &ret = mem[x];
    if (ret) return ret;
    int sum = 0;
    for (long long i = 2; i * i <= x; ++i)
      while (!(x % i)) sum += i, x /= i;
    if (!sum) {
      return ret = x;
    }
    if (x > 1) {
      sum += x;
    }
    return ret = min(sum, smallestValue(sum));
  }
};