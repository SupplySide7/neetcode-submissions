class Solution {
public:
    int characterReplacement(string s, int k) {
        int max = 0;
        array<int, 26> count{};
        for (int l = 0, r = 0; r < static_cast<int>(s.size()); ++r) {
            ++count[s[r] - 'A'];
            while (r - l + 1 - ranges::max(count) > k) --count[s[l++] - 'A'];
            max = std::max(max, r - l + 1);
        } return max;
    }
};
