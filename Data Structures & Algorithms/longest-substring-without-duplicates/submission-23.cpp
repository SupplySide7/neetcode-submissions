class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {return 0;}

        unordered_map<char, int> seen;
        int length = 1;
        int max_length = 0;
        int start_index = 0;
        int end_index = 0;

        while (end_index < s.size()) {
            char c = s[end_index];
            auto it = seen.find(c);

            if (it != seen.end()) { //duplicate
                int duplicate_index = it->second;
                if (duplicate_index < start_index) {
                    seen.erase(it);
                } else {
                    start_index = duplicate_index + 1;
                }
                //seen.erase(c);
                seen[c] = end_index;
                ++end_index;
            } else {
                seen[c] = end_index;
                ++end_index;
            }
            length = end_index - start_index;
            max_length = std::max(max_length, length);
        }
        return max_length;
    }
};