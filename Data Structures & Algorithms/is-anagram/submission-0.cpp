class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        std::unordered_set<char> seen;
        for (char x : s) {
            if (seen.contains(x)) {
                continue;
            }
            int sCount = std::count(s.begin(), s.end(), x);
            int tCount = std::count(t.begin(), t.end(), x);
            if (sCount != tCount) {
                return false;
            }
        }
        return true;
    }
};
