class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) { return false;}

         vector<int> key (26, 0);
         for (const char& c : s) {
            ++key[c - 'a'];
         }
         for (const char& c : t) {
            --key[c - 'a'];
         }
         for (const int& k : key) {
            if (k != 0) {return false;}
         }
         return true;
    }
};
