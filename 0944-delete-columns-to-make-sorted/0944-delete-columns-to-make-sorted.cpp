class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int res = 0;
        for(int i = 0 ; i < strs[0].length() ; ++i){
            char prev = 'a';
            for(string&s : strs){
                if(s[i] < prev){
                    ++res;
                    break;
                }
                prev = s[i];
            }
        }
        return res;
    }
};