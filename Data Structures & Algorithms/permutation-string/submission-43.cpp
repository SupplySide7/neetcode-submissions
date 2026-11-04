class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int m = s1.size(), n = s2.size();
        array<int, 26> need {}, have {};
        for (const auto& c : s1) ++need[c - 'a'];
        for (int l = 0, r = 0; r < n; ++r) {
            ++have[s2[r] - 'a'];
            if (r - l + 1 == m) {
                if (need == have) return true;
                --have[s2[l++] - 'a'];
            }
        } return false;
    }
};
