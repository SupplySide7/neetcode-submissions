class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {return 0;}

        unordered_map<char, int> seen;
        int length = 0;
        int max_length = 0;

        int i = 0;
        while (i < s.size()) {
            auto it = seen.find(s[i]);
            if (it == seen.end()) {
                ++length;
                char c = s[i];
                seen[c] = i;
                max_length = std::max(max_length, length);
                i++;
            } else {
                max_length = std::max(max_length, length);
                length = 0;
                //seen[s[i]] = i;
                int index = it->second;
                seen.clear();
                i = (index) + 1;
            }
        }
        return max_length;
    }
};