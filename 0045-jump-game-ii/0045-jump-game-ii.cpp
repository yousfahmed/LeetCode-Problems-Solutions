class Solution {
public:
    int jump(vector<int>& nums) {
        const int n = nums.size();
        int dp[n];
        memset(dp,63,sizeof dp);
        const int inf = dp[0];
        dp[0] = 0;

        for(int i = 0 ; i < n ; ++i){
            for(int j = 1 ; j <= nums[i] && j + i < n; ++j){
                dp[j+i] = min(dp[i+j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
};