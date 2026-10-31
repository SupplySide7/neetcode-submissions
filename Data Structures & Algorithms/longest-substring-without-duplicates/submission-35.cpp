class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        array<int, 128> record {0};
        for (int l = 0, r = 0; r < static_cast<int>(s.size()); ++r) {
            ++record[s[r]];
            while (record[s[r]] > 1) --record[s[l++]];
            max = std::max(max, r - l + 1);
        } return max;
    }
};
