class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}

        std::array<int, 26> freq{};
        for (const char& c : s) {
            freq[c -'a']++;
        }
        for (const char& c : t) {
            freq[c -'a']--;
        }

        for (const int& i : freq) {
            if (i != 0) {return false;}
        }
        return true;
    }
};
