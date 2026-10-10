class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}

        array<int, 26> anagram;
        for (const char& c : s) {
            anagram[c - 'a']++;
        }
        
        for (const char& c : t) {
            anagram[c -'a']--;
        }

        for (const int &i: anagram) {
            if (i !=0) {return false;}
        }
        return true;
    }
};