class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> key {};
        int maxlen = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++key[s[r] - 'A'];
            while (r - l + 1 - ranges::max(key) > k) --key[s[l++] - 'A'];
            maxlen = std::max(maxlen, r - l + 1);
        } return maxlen;
    }
};
