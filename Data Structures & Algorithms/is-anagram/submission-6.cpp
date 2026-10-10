class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}
        std::unordered_map<char, int>freq;
        for (const auto& c : s) {
            ++freq[c];
        }
        for (const auto& c : t) {
            if (--freq[c] ==0) {freq.erase(c);}
        }
        return freq.empty();
    }
};
