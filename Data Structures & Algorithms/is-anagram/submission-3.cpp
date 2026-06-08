class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) { return false; }
/*
      std::unordered_set<char> seen;
        for (char x : s) {
            if (seen.contains(x)) { continue; }

            int sCount = std::count(s.begin(), s.end(), x);
            int tCount = std::count(t.begin(), t.end(), x);
            if (sCount != tCount) { return false; }
        }
        return true;
*/
        std::unordered_map<char, int> sFreq;
        std::unordered_map<char, int> tFreq;

        for (int i = 0; i < s.length(); i++) {
            sFreq[s[i]]++;
            tFreq[t[i]]++;
        }
        return (sFreq == tFreq);
    }
};
