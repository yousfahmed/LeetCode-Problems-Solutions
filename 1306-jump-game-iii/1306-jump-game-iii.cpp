class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        const int n = arr.size();
        char vis[n];
        memset(vis,0,sizeof vis);
        queue<int> q;
        vis[start] = true;
        q.emplace(start);
        int cnt = 0;
        while(q.size()){
            int i = q.front();
            if(!arr[i])return true;
            q.pop();
            if(i+arr[i] < n and !vis[i+arr[i]]){
                vis[i+arr[i]] = true;
                q.push(i+arr[i]);
            }
            if(i-arr[i] >= 0 and !vis[i-arr[i]]){
                vis[i-arr[i]] = true;
                q.push(i-arr[i]);
            }
        }
        
        return false;
    }
};