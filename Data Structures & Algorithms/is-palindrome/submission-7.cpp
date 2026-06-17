class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {return !::isalnum(c);}), s.end());
        
        for (int i = 0; i < s.size(); i++) {
            if(!(s[i] == s[s.size() - 1 - i])) {return false;}
        }
        return true;
    }
};
