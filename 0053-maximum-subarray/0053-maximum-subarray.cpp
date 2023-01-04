class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mn = 0 , res = -1e9 , sum = 0;
        for(int &i:nums){
            sum += i;
            res = max(res , sum - mn);
            mn = min(sum,mn);
        }
        return res;
    }
};