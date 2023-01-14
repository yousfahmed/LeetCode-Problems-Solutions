class Solution {
  vector<int> par;

  int findLeader(int u) {
    if (par[u] == u)return u;
    return par[u] = findLeader(par[u]);
  }

  bool join(int u, int v) {
    u = findLeader(u), v = findLeader(v);
    if (u == v)return false;
    if (u < v)swap(u, v);
    par[u] = v;
    return true;
  }


public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    par = vector<int>(26);
    iota(par.begin(), par.end(), 0);
    for (int i = 0; i < s1.length(); ++i) {
      join(s1[i] - 'a', s2[i] - 'a');
    }
    for (char &ch: baseStr) {
      ch = findLeader(ch - 'a') + 'a';
    }
    return baseStr;
  }
};