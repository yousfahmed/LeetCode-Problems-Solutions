const int N = 5 * 1e4;
int frq[N + N + 5];

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    for (int &x: nums) ++frq[x + N];
    int i = 0;
    for (int j = -N; j <= N; ++j)
      while (frq[j + N] > 0)
        nums[i++] = j, --frq[j + N];
    return nums;
  }
};