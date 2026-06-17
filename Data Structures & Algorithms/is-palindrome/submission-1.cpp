class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        s.erase(std::remove_if(s.begin(), s.end(), [](unsigned char c) {return !std::isalnum(c);}), s.end());
        unique_ptr<string> front = make_unique<string>(s);
        unique_ptr<string> back = make_unique<string>(s);
        
        for (int i = 0; i < s.size(); i++) {
            char front_char = (*front)[i];
            char back_char = (*back)[s.size() - 1 - i];
            if(!(front_char == back_char)) {return false;}
        }
        return true;
    }
};
