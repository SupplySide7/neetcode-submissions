class Solution {
public:
    bool isPalindrome(string s) {
        ptrdiff_t l = 0, r = ssize(s);
        auto alnum = [&] (char c) {
            return static_cast<unsigned char>(isalnum(c)) != 0;};
        auto lower = [&] (char c) {return static_cast<unsigned char>(tolower(c));};
        while (l < r) {
            while (l < r && !alnum(s[l])) {++l;}
            while (l < r && !alnum(s[r])) {--r;}
            if (lower(s[l]) != lower(s[r])) {return false;}
            ++l; --r;
        }
        return true;
    }
};
