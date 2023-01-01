class Solution {
public:
    int maximumTastiness(vector<int> &a, int k) {
        const int n = a.size();
        sort(a.begin(), a.end());
        int s = 1, e = 1e9, md, ans = 0;

        auto okay = [&](int x) -> bool {
            int cnt = 0, i = 0;
            while (i < n) {
                ++cnt;
                i = lower_bound(a.begin(), a.end(), a[i] + x) - a.begin();
            }
            return cnt >= k;
        };

        while (s <= e) {
            md = (e - s) / 2 + s;
            if (okay(md))
                ans = md, s = md + 1;
            else
                e = md - 1;
        }
        return ans;

    }
};
