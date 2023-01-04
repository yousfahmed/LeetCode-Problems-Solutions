class Solution {

  class mont_queue {
    deque<pair<int, int>> q;
  public:
    void push(int i, int v) {
      while (q.size() && q.back().first >= v)
        q.pop_back();
      q.emplace_back(v, i);
    }

    void pop(int i) {
      while (q.size() && q.front().second <= i)
        q.pop_front();
    }

    int top() {
      return q.front().first;
    }

    void print() {
      cout << "Queue is : ";
      for (const auto &[i, _]: q)
        cout << i << ' ';
      cout << '\n';
    }

  };

public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int n = nums.size();
    mont_queue q;
    for (int i = 0; i < n - 1; ++i)
      nums.push_back(nums[i]);
    int m = nums.size();
    q.push(-1, 0);
    int res = -1e9, sum = 0;
    for (int i = 0; i < m; ++i) {
      q.pop(i - n - 1);
      sum += nums[i];
      res = max(res, sum - q.top());
      q.push(i, sum);
    }
    return res;
  }
};