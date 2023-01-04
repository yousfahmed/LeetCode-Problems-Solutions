class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int &i:tasks)
            ++mp[i];
        int res = 0;
        for(auto&[_,i]:mp){
            if(i == 1)return -1;
            res+=(i+2)/3;
        }
        return res;
    }
};