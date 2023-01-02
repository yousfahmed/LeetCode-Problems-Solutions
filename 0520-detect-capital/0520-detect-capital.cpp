class Solution {
public:
  bool detectCapitalUse(string word) {
    int c = count_if(word.begin(), word.end(), [&](char x) { 
      return isupper(x); 
    });
    return c == word.length() or (isupper(word[0]) and c == 1) or c == 0;
  }
};