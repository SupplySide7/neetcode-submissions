class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        const int n = s.size();
        array<int, 128> key{0};
        for (int l = 0, r = 0; r < n; ++r) {
            ++key[s[r]];
            while (key[s[r]] > 1) --key[s[l++]];
            max = std::max(max, r - l + 1);
        } return max;
    }
};
