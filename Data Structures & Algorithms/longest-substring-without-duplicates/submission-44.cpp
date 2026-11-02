class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        array<int, 128> substring {0};
        int maxlen = 0;
        if (s.empty()) return 0; 
        for (int l = 0, r = 0; r < s.size(); ++r) {
            ++substring[s[r]];
            if (!(substring[s[r]] > 1)) maxlen = std::max(maxlen, r - l + 1);
            else {while (substring[s[r]] > 1) --substring[s[l++]];}
            
        } return maxlen;
    }
};
