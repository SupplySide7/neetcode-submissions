#include <cstddef>

class Solution {
public:
    bool isPalindrome(string s) {
        auto alnum = [](char c) {return isalnum(static_cast<unsigned char>(c)) != 0;};
        auto lower = [](char c) {return tolower(static_cast<unsigned char>(c));};

        ptrdiff_t l = 0;
        ptrdiff_t r = ssize(s) - 1;

        while (l < r) {
            while (l < r && !alnum(s[l])) {++l;}
            while (l < r && !alnum(s[r])) {--r;}
            
            if (lower(s[l]) != lower(s[r])) {return false;}
            ++l;
            --r;
        }
        return true;
    }
};
