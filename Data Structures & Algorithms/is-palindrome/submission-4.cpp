class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {return !::isalnum(c);}), s.end());
        unique_ptr<string> front = make_unique<string>(s);
        unique_ptr<string> back = make_unique<string>(s);
        
        for (int i = 0; i < s.size(); i++) {
            char front_char = s[i];
            char back_char = s[s.size() - 1 - i];
            if(!(s[i] == s[s.size() - 1 - i])) {return false;}
        }
        return true;
    }
};
