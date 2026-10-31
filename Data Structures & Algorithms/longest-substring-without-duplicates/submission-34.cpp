class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max = 0;
        array<int, 128> record {};
        for (int l = 0, r = 0; r < s.size(); ++r) {
            //char c = s[r];
            ++record[s[r]];
            while (record[s[r]] > 1) --record[s[l++]];
            max = std::max(max, r - l + 1);
        } return max;
    }
};
