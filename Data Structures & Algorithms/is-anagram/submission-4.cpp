class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int>freq;
        for (const auto& c : s) {
            ++freq[c];
        }

        for (const auto& c : t) {
            --freq[c];
            if (freq[c]==0) {
                freq.erase(c);
            }
        }
        if (freq.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};
