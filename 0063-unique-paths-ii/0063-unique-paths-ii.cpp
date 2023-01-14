class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        if(arr[arr.size()-1][arr[0].size()-1] || arr[0][0])
            return 0;
           for(int i=1,len=arr.size(),pr=0;i<len;i++){
          
               arr[i][0]=1 * (arr[i][0]||pr?-1:1);
                pr=arr[i][0]<0;
           }
        for(int i=0,len=arr[0].size(),pr=0;i<len;i++){
            
            arr[0][i]=1 * (arr[0][i]||pr?-1:1);
            pr=arr[0][i]<0;
        }



        for(int i=1,len=arr.size();i<len;i++){
            for(int j=1,len=arr[i].size();j<len;j++){
                if(arr[i][j]){
                    arr[i][j]*=-1;
                    continue;
                }
                int u = arr[i-1][j];
                int r= arr[i][j-1];
                arr[i][j]= (u>0 ? u:0) + (r>0? r:0);
            }
        } 
        return arr[arr.size()-1][arr[0].size()-1];
    }
};