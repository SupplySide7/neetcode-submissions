class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        int maxlen = 0;
        array<int, 26> key;
        for (int l = 0, r = 0; r < n; ++r) {
            ++key[s[r] - 'A'];
            while (r - l + 1 - ranges::max(key) > k) {
                --key[s[l++] - 'A'];
            }
            maxlen = std::max(maxlen, r - l + 1);
        } return maxlen;
    }
};
