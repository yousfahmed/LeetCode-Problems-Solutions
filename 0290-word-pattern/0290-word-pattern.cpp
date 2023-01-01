class Solution {
public:
  bool wordPattern(string pattern, string s) {
    map<char, string> mp;
    set<string> un;
    int words = count(s.begin(), s.end(), ' ') + 1;
    if (words != pattern.size())return false;
    s.push_back(' ');
    string x;
    int i = 0;
    for (char &ch: s) {
      if (ch == ' ') {
        char c = pattern[i++];
        if (mp.count(c)) {
          if (x != mp[c])
            return false;
        } else {
          if (un.count(x))return false;
          un.emplace(x);
          mp[c] = x;
        }
        x.clear();
      } else {
        x += ch;
      }
    }
    return true;
  }

};