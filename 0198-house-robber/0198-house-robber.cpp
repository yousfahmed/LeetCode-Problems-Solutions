class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        int mx = nums.back() ,cur=nums[n-2];
        int ret = max(mx,cur);
        for(int i = n-3; ~i ;--i){
            int t = nums[i] + mx;
            mx = max(mx,cur);
            cur = t;
            ret = max(ret , cur);
        }
        return ret;
    }
};