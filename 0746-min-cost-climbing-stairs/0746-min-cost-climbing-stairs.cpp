class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    cost.push_back(0);
    cost.insert(cost.begin(), 0);
    for (int i = 2; i < cost.size(); ++i) {
      cost[i] += min(cost[i - 1], cost[i - 2]);
    }
    return cost.back();
  }
};