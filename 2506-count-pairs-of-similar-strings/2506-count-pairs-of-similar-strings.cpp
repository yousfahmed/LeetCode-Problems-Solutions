class Solution {
public:
    int similarPairs(vector<string>& words) {
        map<vector<bool>,int> mp;
        int ret = 0;
        for(string&x:words){
            vector<bool>frq(26);    
            for(char&ch:x)
                frq[ch-'a'] = true;
            ret+= mp[frq]++;
        }
        return ret;
    }
};